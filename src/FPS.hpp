#ifndef _FPS_HPP_
#define _FPS_HPP_

#ifdef __ANDROID__
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

#include <queue>
#include <iostream>

class GameWindow;

class FPS {
private:
    const int MAX_FPS_VECTOR_COUNT = 30;
    std::queue<uint64_t> ticks_queue;
public:
    void Update();
    void DrawFPS(GameWindow* game_window);
    double GetFPS();
};

#endif /* _FPS_HPP_ */