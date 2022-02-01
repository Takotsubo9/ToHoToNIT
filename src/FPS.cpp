#include "GameWindow.hpp"
#include "FPS.hpp"

void FPS::Update() {
    uint64_t Ticks = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    ticks_queue.push(Ticks);
    if(ticks_queue.size() > MAX_FPS_VECTOR_COUNT) {
        ticks_queue.pop();
    }
}

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
        for(int i = 0; i < digit; i++) {
            int Deg = (static_cast<int>(FPS / pow(10, i)) % 10);
            const SDL_Rect srcrect = {32*Deg,0,32,48};
            const SDL_Rect dstrect = {-16*i+848,696,16,24};
            game_window->DrawImage(ImageID::number, &srcrect, &dstrect, RefPoint::LeftTop);
        }
    }
}

double FPS::GetFPS() {
    
    
    if( ticks_queue.size() <= 1 )
        return 0;
    
    double frame = static_cast<double>(ticks_queue.back() - ticks_queue.front());
    return 1000000.0 / (frame / (ticks_queue.size() - 1));
}