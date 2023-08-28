#include <string>
#if defined(__ANDROID__) && !defined(__TERMUX__)
#include <SDL_image.h>
#include <SDL_mixer.h>
#else
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#endif

#include "GameWindow.hpp"
#include "Const/TouchRect.hpp"

GameWindow::GameWindow(std::string window_title, unsigned int width, unsigned int height) {
    //加速度センサをジョイスティックとして使う機能をオフ
    SDL_SetHint(SDL_HINT_ACCELEROMETER_AS_JOYSTICK, "0");
    SDL_SetHint(SDL_HINT_ORIENTATIONS, "LandscapeLeft LandscapeRight");
    this->application_path = "";
#ifndef __ANDROID__
    //Android以外の場合、実行ファイルが配置されているパスを取得し、保存しておく
    //カレントディレクトリが実行ファイル配置場所と違う場所で実行された場合にテクスチャのロードができなくなるのを防止
    char* application_path_char = SDL_GetBasePath();
    if (!application_path_char) {
        application_path_char = SDL_strdup("./");
    }
    this->application_path = std::string(application_path_char);
    SDL_free(application_path_char);
#endif

    this->window_handle = nullptr;
    this->renderer_handle = nullptr;
    this->keyboard_manager = nullptr;
    this->joystick_manager = nullptr;
    this->touch_manager = nullptr;
    this->sound_manager = nullptr;
    this->operate = nullptr;

    //起動前にコンフィグを読み込んでおく
    this->config.Import(application_path);

    //SDLの初期化
    if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO|SDL_INIT_JOYSTICK) != 0) {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Touhou-Koumatou", "Failed to initialize SDL2", nullptr);
        return;
    }
    //SDL_imageの初期化
    int flags = IMG_INIT_PNG;
    if((IMG_Init(flags) & flags) != flags) {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Touhou-Koumatou", "Failed to initialize SDL2_image", nullptr);
        return;
    }
    //SDL_mixerの初期化
    flags = MIX_INIT_MP3;
    if((Mix_Init(flags) & flags) != flags) {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Touhou-Koumatou", "Failed to initialize SDL2_mixer", nullptr);
        return;
    }
    //音声出力の開始
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1) {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Touhou-Koumatou", "Failed to open audio device", nullptr);
        return;
    }
    //ウィンドウを作成する
    window_handle = SDL_CreateWindow(window_title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_HIDDEN|SDL_WINDOW_RESIZABLE|SDL_WINDOW_ALLOW_HIGHDPI);
    //.cfgから読み込んだフルスクリーンモードをセット
    this->setFullScreenMode(config.getFullScreenMode());
    //レンダラーの作成(できるだけHWアクセラレーションを有効化する)
    renderer_handle = SDL_CreateRenderer(window_handle, -1, SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);

    //スケーリングアルゴリズムをlinearに
    //nearestより重くなるかもしれないが、きれいを優先
    //あとでconfigなどで設定できるようにするのもいいかも
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    //レンダラーのサイズを設定
    SDL_RenderSetLogicalSize(renderer_handle, width, height);

    //InputManager系のインスタンス生成
    keyboard_manager = std::make_unique<KeyboardManager>();
    joystick_manager = std::make_unique<JoystickManager>();
    touch_manager = std::make_unique<TouchManager>();
    sound_manager = std::make_unique<SoundManager>(application_path);
    //コンフィグから読み込んだボリュームの設定
    sound_manager->SetBGMVolume(config.getBGMVolume());
    sound_manager->SetSEVolume(config.getSEVolume());

    operate = std::make_unique<Operate>(width, height);
    SDL_SetRenderDrawBlendMode(renderer_handle, SDL_BLENDMODE_BLEND);
    is_active = false;
}

GameWindow::~GameWindow() {
    config.Export(application_path);
    operate.reset();
    sound_manager.reset();
    touch_manager.reset();
    joystick_manager.reset();
    keyboard_manager.reset();
    if(renderer_handle)
        SDL_DestroyRenderer(renderer_handle);
    if(window_handle)
        SDL_DestroyWindow(window_handle);
    Mix_CloseAudio();
    Mix_Quit();
    IMG_Quit();
    SDL_Quit();
}

void GameWindow::setFullScreenMode(FullScreenMODE fsm) {
    if(!window_handle)
        return;

    if(fsm == FullScreenMODE::Fullscreen) {
        SDL_SetWindowFullscreen(window_handle, SDL_WINDOW_FULLSCREEN);
    } else if (fsm == FullScreenMODE::BorderLess){
        SDL_SetWindowFullscreen(window_handle, SDL_WINDOW_FULLSCREEN_DESKTOP);
    } else {
        SDL_SetWindowFullscreen(window_handle, 0);
    }
    this->config.setFullScreenMode(fsm);
}

void GameWindow::Run() {
    if(!window_handle)
        return;

    ScreenManager screen_manager;

    SDL_Event pollevent;

    auto next_frame_time = std::chrono::system_clock::now();

    SDL_ShowWindow(this->window_handle);

    SDL_Surface* bootsur = IMG_Load((this->application_path+"image/booting/booting.png").c_str());
    SDL_RenderClear(renderer_handle);
    SDL_BlitSurface( bootsur, nullptr, SDL_GetWindowSurface(window_handle), nullptr);
    SDL_UpdateWindowSurface(window_handle);
    SDL_FreeSurface(bootsur);

    //画像/音声のロード処理
    image_manager = std::make_unique<ImageManager>(renderer_handle, application_path);

    quit = false;
    while (!quit) {
        while (SDL_PollEvent(&pollevent) != 0) {
            switch(pollevent.type) {
                case SDL_QUIT:
                    quit = true;
                    break;
                case SDL_KEYDOWN:
                case SDL_KEYUP:
                    keyboard_manager->Polling(pollevent);
                    break;
                case SDL_JOYDEVICEADDED:
                case SDL_JOYDEVICEREMOVED:
                    joystick_manager->TrySetJoyStick();
                    break;
                case SDL_JOYBUTTONUP:
                case SDL_JOYBUTTONDOWN:
                    joystick_manager->Polling(pollevent);
                    break;
                case SDL_FINGERDOWN:
                case SDL_FINGERMOTION:
                case SDL_FINGERUP:
                    touch_manager->Polling(pollevent);
                    break;
                case SDL_WINDOWEVENT:
                    if(pollevent.window.event == SDL_WINDOWEVENT_FOCUS_GAINED) {
                        this->is_active = true;
                    } else if(pollevent.window.event == SDL_WINDOWEVENT_FOCUS_LOST) {
                        this->is_active = false;
                    }
                    break;
            }
        }
        if(this->is_active)
        {
            auto now_time = std::chrono::system_clock::now();
            if (now_time >= next_frame_time) {
                operate->Polling(keyboard_manager.get(), joystick_manager.get(), touch_manager.get(), &config);
                SDL_SetRenderDrawColor(renderer_handle, 0x00, 0x00, 0x00, 0xFF);
                SDL_RenderClear(renderer_handle);

                screen_manager.Render(this);

#if defined(__ANDROID__)
                this->TouchGuide();
#endif

                SDL_SetRenderDrawColor(renderer_handle, 0, 0, 0, 0xff);
                SDL_RenderPresent(renderer_handle);

                next_frame_time += this->frame_duration_micro;
                keyboard_manager->ClearKeyEvent();
                joystick_manager->ClearKeyEvent();
                touch_manager->ClearKeyEvent();
            } else {
                SDL_Delay(1);
            }
        } else {
            SDL_Delay(this->inactive_delay_milli);
            next_frame_time = std::chrono::system_clock::now();
        }
    }

    image_manager = nullptr;

    SDL_HideWindow(this->window_handle);
}

//Android用のタッチガイド
void GameWindow::TouchGuide() {
    this->FillRect(0xff, 0x00, 0x00, 0x20, &TouchRectList[Buttons::Shot]);
    this->FillRect(0x00, 0xff, 0x00, 0x20, &TouchRectList[Buttons::Bomb]);
    this->FillRect(0x00, 0x00, 0x00, 0x20, &TouchRectList[Buttons::Pause]);
    this->FillRect(0x00, 0x00, 0xff, 0x20, &TouchRectList[Buttons::Slow]);
    this->FillRect(0xff, 0x00, 0xff, 0x20, &TouchRectList[Buttons::Skip]);
}
