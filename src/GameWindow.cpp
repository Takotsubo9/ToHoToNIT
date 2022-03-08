#ifdef __ANDROID__
#include <SDL_image.h>
#include <SDL_mixer.h>
#else
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#endif

#include "GameWindow.hpp"

GameWindow::GameWindow(std::string window_title, int width, int height) {

    char* application_path_char = SDL_GetBasePath();
    if (!application_path_char) {
        application_path_char = SDL_strdup("./");
    }
    this->application_path = std::string(application_path_char);
    SDL_free(application_path_char);

    this->window_handle = NULL;
    this->renderer_handle = NULL;
    this->keyboard_manager = NULL;
    this->joystick_manager = NULL;
    this->sound_manager = NULL;
    this->operate = NULL;

    this->config.Import(application_path);

    main_fps = 60;
    if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO|SDL_INIT_JOYSTICK) != 0) {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Touhou-Koumatou", "Failed to initialize SDL2", NULL);
        return;
    }
    int flags = IMG_INIT_PNG;
    if((IMG_Init(flags) & flags) != flags) {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Touhou-Koumatou", "Failed to initialize SDL2_image", NULL);
        return;
    }
    flags = MIX_INIT_MP3;
    if((Mix_Init(flags) & flags) != flags) {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Touhou-Koumatou", "Failed to initialize SDL2_mixer", NULL);
        return;
    }
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1) {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Touhou-Koumatou", "Failed to open audio device", NULL);
        return;
    }
    window_handle = SDL_CreateWindow(window_title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_HIDDEN|SDL_WINDOW_RESIZABLE);
    this->setFullScreenMode(config.getFullScreenMode());
    renderer_handle = SDL_CreateRenderer(window_handle, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer_handle, width, height);
    keyboard_manager = new KeyboardManager();
    joystick_manager = new JoystickManager();
    sound_manager = new SoundManager(application_path);
    sound_manager->SetBGMVolume(config.getBGMVolume());
    sound_manager->SetSEVolume(config.getSEVolume());
    operate = new Operate();
    SDL_SetRenderDrawBlendMode(renderer_handle, SDL_BLENDMODE_BLEND);
    is_active = false;
}

GameWindow::~GameWindow() {
    config.Export(application_path);
    if(operate)
        delete operate;
    if(sound_manager)
        delete sound_manager;
    if(joystick_manager)
        delete joystick_manager;
    if(keyboard_manager)
        delete keyboard_manager;
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

    uint64_t PrevTicks = 0;

    SDL_ShowWindow(this->window_handle);

    SDL_Surface* bootsur = IMG_Load((this->application_path+"image/booting/booting.png").c_str());
    SDL_RenderClear(renderer_handle);
    SDL_BlitSurface( bootsur, NULL, SDL_GetWindowSurface(window_handle), NULL );
    SDL_UpdateWindowSurface(window_handle);
    SDL_FreeSurface(bootsur);

    //画像/音声のロード処理
    image_manager = new ImageManager(renderer_handle, application_path);

    quit = false;
    while (!quit) {
        while (SDL_PollEvent(&pollevent) != 0) {
            if (pollevent.type == SDL_QUIT) {
                quit = true;
            } else if(pollevent.type == SDL_KEYDOWN || pollevent.type == SDL_KEYUP) {
                keyboard_manager->Polling(pollevent);
            } else if(pollevent.type == SDL_JOYDEVICEADDED || pollevent.type == SDL_JOYDEVICEREMOVED) {
                joystick_manager->TrySetJoyStick();
            } else if(pollevent.type == SDL_JOYBUTTONUP || pollevent.type == SDL_JOYBUTTONDOWN) {
                joystick_manager->Polling(pollevent);
            } else if(pollevent.type == SDL_WINDOWEVENT) {
                if(pollevent.window.event == SDL_WINDOWEVENT_FOCUS_GAINED) {
                    this->is_active = true;
                } else if(pollevent.window.event == SDL_WINDOWEVENT_FOCUS_LOST) {
                    this->is_active = false;
                }
            }
        }
        if(this->is_active)
        {
            uint64_t Ticks = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
            if (Ticks - PrevTicks > 1000000 / main_fps) {
                operate->Polling(keyboard_manager, joystick_manager, &config);
                SDL_SetRenderDrawColor( renderer_handle, 0x00, 0x00, 0x00, 0xFF );
                SDL_RenderClear(renderer_handle);

                screen_manager.Render(this);
                SDL_RenderPresent(renderer_handle);
                
                PrevTicks = Ticks;
                keyboard_manager->ClearKeyEvent();
                joystick_manager->ClearKeyEvent();
            } else if (Ticks - PrevTicks + 1 < 1000000 / main_fps) {
                SDL_Delay(1);
            }
        } else {
            SDL_Delay(50);
        }
    }
    
    
    delete image_manager;
    image_manager = nullptr;

    SDL_HideWindow(this->window_handle);
}