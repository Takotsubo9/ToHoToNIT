#ifndef _FPS_HPP_
#define _FPS_HPP_

#include <SDL2/SDL.h>
#include <queue>
#include <iostream>

const int MAX_FPS_VECTOR_COUNT = 30;

class GameWindow;

class FPS {
private:
    std::queue<uint64_t> ticks_queue;
public:
    void Update();
    void DrawFPS(GameWindow* game_window);
    double GetFPS();
};

#endif /* _FPS_HPP_ */