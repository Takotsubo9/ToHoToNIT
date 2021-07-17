#include "GameWindow.hpp"

GameWindow::GameWindow(std::string window_title, int width, int height) {
    main_fps = 60;
    fullscreen_mode = FullScreenMODE::Windowed;
    SDL_Init(SDL_INIT_VIDEO|SDL_INIT_JOYSTICK); 
    window_handle = SDL_CreateWindow(window_title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_HIDDEN);
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

    SDL_Surface* bootsur = SDL_LoadBMP("image/booting/booting.bmp");
    SDL_RenderClear(renderer_handle);
    SDL_BlitSurface( bootsur, NULL, SDL_GetWindowSurface(window_handle), NULL );
    SDL_UpdateWindowSurface(window_handle);
    SDL_FreeSurface(bootsur);

    image_manager = new ImageManager(renderer_handle);

    quit = false;
    while (!quit) {
        SDL_Delay(1);
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
            //std::cout << pollevent.type << std::endl;
        }
        if(this->is_active)
        {
            uint64_t Ticks = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
            if (Ticks - PrevTicks > 1000000 / main_fps) {
                operate->Polling(keyboard_manager, joystick_manager);
                SDL_SetRenderDrawColor( renderer_handle, 0x00, 0x00, 0x00, 0xFF );
                SDL_RenderClear(renderer_handle);

                screen_manager.Render(this);
                SDL_RenderPresent(renderer_handle);
                
                PrevTicks = Ticks;
                keyboard_manager->ClearKeyEvent();
                joystick_manager->ClearKeyEvent();
            }
        }
    }
    
    
    delete image_manager;
    image_manager = nullptr;

    SDL_HideWindow(this->window_handle);
}