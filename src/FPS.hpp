#ifndef _FPS_HPP_
#define _FPS_HPP_

#include <string>

class GameWindow;

class FPS {
private:
    static constexpr double update_frame = 60;
    uint64_t first;
    uint64_t second;
    uint16_t frames;
    double fps;
public:
    FPS();
    void Update();
    void DrawFPS(GameWindow* game_window);
    double GetFPS();
};

#endif /* _FPS_HPP_ */
