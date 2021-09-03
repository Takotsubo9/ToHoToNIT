#include "GameWindow.hpp"
#include <SDL2/SDL_image.h>

GameWindow::GameWindow(std::string window_title, int width, int height) {

    char* application_path_char = SDL_GetBasePath();
    this->application_path = std::string(application_path_char);
    SDL_free(application_path_char);

    main_fps = 60;
    fullscreen_mode = FullScreenMODE::Windowed;
    SDL_Init(SDL_INIT_VIDEO|SDL_INIT_JOYSTICK); 
    IMG_Init(IMG_INIT_PNG);
    window_handle = SDL_CreateWindow(window_title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_HIDDEN|SDL_WINDOW_RESIZABLE);
    renderer_handle = SDL_CreateRenderer(window_handle, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer_handle, width, height);
    keyboard_manager = new KeyboardManager();
    joystick_manager = new JoystickManager();
    operate = new Operate();
    SDL_SetRenderDrawBlendMode(renderer_handle, SDL_BLENDMODE_BLEND);
    is_active = false;
}

GameWindow::~GameWindow() {
    delete operate;
    delete joystick_manager;
    delete keyboard_manager;
    SDL_DestroyRenderer(renderer_handle);
    SDL_DestroyWindow(window_handle);
    IMG_Quit();
    SDL_Quit();
}

void GameWindow::setFullScreenMode(FullScreenMODE fsm) {
    if( !(this->fullscreen_mode == fsm) ) {
        if(fsm == FullScreenMODE::Fullscreen) {
            SDL_SetWindowFullscreen(window_handle, SDL_WINDOW_FULLSCREEN);
        } else if (fsm == FullScreenMODE::BorderLess){
            SDL_SetWindowFullscreen(window_handle, SDL_WINDOW_FULLSCREEN_DESKTOP);
        } else {
            SDL_SetWindowFullscreen(window_handle, 0);
        }
        this->fullscreen_mode = fsm;
    }
}

void GameWindow::Run() {
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