#include "ScreenManager.hpp"
#include "GameWindow.hpp"

ScreenManager::ScreenManager() {
    this->screen = new TestScreen();
}

ScreenManager::~ScreenManager() {
    delete this->screen;
}

void ScreenManager::Render(GameWindow* game_window) {
    ScreenID id = screen->Render(game_window);
    if(screen->getScreenID() != id) {
        delete this->screen;
        switch(id) {
            //ここに遷移用のクラスを列挙する。
            //case ScreenID::hoge:
            //  this->screen = new hogehoge();
            //  break;
                
            default:
                break;
        }
    }

    //ここから下はfps表示----
    uint64_t Ticks = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    double FPS = 1000000 / (double)(Ticks - PrevTicks);

    //fps文字表示
    {
        const SDL_Rect srcrect = {32,0,96,48};
        const SDL_Rect dstrect = {912,696,48,24};
        game_window->DrawImage(ImageID::FPSText, &srcrect, &dstrect);
    }
    //fps小数点以下表示
    {
        for(int i=0;i<2;i++) {
            int Deg = ((int)(FPS / pow(10, -i-1)) % 10);
            const SDL_Rect srcrect = {32*Deg,0,32,48};
            const SDL_Rect dstrect = {16*i+880,696,16,24};
            game_window->DrawImage(ImageID::Number, &srcrect, &dstrect);
        }
    }
    //fps点の表示
    {
        const SDL_Rect srcrect = {0,0,32,48};
        const SDL_Rect dstrect = {864,696,16,24};
        game_window->DrawImage(ImageID::FPSText, &srcrect, &dstrect);
    }
    //fps整数側表示
    {
        int digit = 0;
        int num = FPS;
        while(num != 0){
            num /= 10;
            digit++;
        }
        for(int i=0;i<digit;i++) {
            int Deg = ((int)(FPS / pow(10, i)) % 10);
            const SDL_Rect srcrect = {32*Deg,0,32,48};
            const SDL_Rect dstrect = {-16*i+848,696,16,24};
            game_window->DrawImage(ImageID::Number, &srcrect, &dstrect);
        }
    }

    PrevTicks = Ticks;
}