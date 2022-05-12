#ifndef _FPS_HPP_
#define _FPS_HPP_

#if defined(__ANDROID__) && !defined(__TERMUX__)
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

class GameWindow;

class FPS {
private:
    static const double update_frame;
    uint64_t first;
    uint64_t second;
    uint16_t frames;
public:
    FPS();
    void Update();
    void DrawFPS(GameWindow* game_window);
    double GetFPS();
};

#endif /* _FPS_HPP_ */