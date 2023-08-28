#include "GameWindow.hpp"
#include "FPS.hpp"

const double FPS::update_frame = 30;

inline uint64_t getNowTime() {
    return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

FPS::FPS() {
    this->first = 0;
    this->second = getNowTime();
    this->frames = 0;
    this->fps = 0;
}

//FPS値のアップデートを行う
void FPS::Update() {
    if(frames == this->update_frame) {
        this->first = this->second;
        this->second = getNowTime();
        if(this->second - this->first != 0)
            this->fps = 1000 / ((this->second - this->first) / this->update_frame);
        else
            this->fps = 0;
        frames = 0;
    }
    frames++;
}

//FPS値を右下に描画する
void FPS::DrawFPS(GameWindow* game_window) {
    double FPS = this->GetFPS();

    //fps文字表示
    {
        const SDL_Rect srcrect = {32,0,96,48};
        const SDL_Rect dstrect = {912,696,48,24};
        game_window->DrawImage(ImageID::fps_text, &srcrect, &dstrect, RefPoint::LeftTop);
    }
    //fps小数点以下表示
    {
        for(int i = 0; i < 2; i++) {
            int Deg = (static_cast<int>(FPS / pow(10, -i-1)) % 10);
            const SDL_Rect srcrect = {32*Deg,0,32,48};
            const SDL_Rect dstrect = {16*i+880,696,16,24};
            game_window->DrawImage(ImageID::number, &srcrect, &dstrect, RefPoint::LeftTop);
        }
    }
    //fps点の表示
    {
        const SDL_Rect srcrect = {0,0,32,48};
        const SDL_Rect dstrect = {864,696,16,24};
        game_window->DrawImage(ImageID::fps_text, &srcrect, &dstrect, RefPoint::LeftTop);
    }
    //fps整数側表示
    {
        int digit = 0;
        int num = FPS;
        while(num != 0){
            num /= 10;
            digit++;
        }
        if(digit == 0)
            digit++;
        for(int i = 0; i < digit; i++) {
            int Deg = (static_cast<int>(FPS / pow(10, i)) % 10);
            const SDL_Rect srcrect = {32*Deg,0,32,48};
            const SDL_Rect dstrect = {-16*i+848,696,16,24};
            game_window->DrawImage(ImageID::number, &srcrect, &dstrect, RefPoint::LeftTop);
        }
    }
}

double FPS::GetFPS() {
    return fps;
}
