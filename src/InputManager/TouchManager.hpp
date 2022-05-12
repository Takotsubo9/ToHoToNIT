#ifndef _TOUCH_MANAGER_H_
#define _TOUCH_MANAGER_H_

#if defined(__ANDROID__) && !defined(__TERMUX__)
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

#include <unordered_map>
#include <vector>

struct Point {
    float x, y;
    Point() {
        this->x = 0;
        this->y = 0;
    }
    Point(float x, float y) {
        this->x = x;
        this->y = y;
    };
};

class TouchManager {
private:
    std::vector<Point> touched;
    std::unordered_map<SDL_FingerID, Point> touching;
    std::unordered_map<SDL_FingerID, Point> first;
    std::vector<SDL_FingerID> fingerid_list;
public:
    std::vector<Point> GetTouchedVector() {
        return touched;
    }
    Point GetTouchingPos(SDL_FingerID id) {
        return touching[id];
    }
    Point GetFirstTouchPos(SDL_FingerID id) {
        return first[id];
    }
    std::vector<SDL_FingerID> GetFingerIDList() {
        return fingerid_list;
    }
    
    void Polling(SDL_Event e);
    void ClearKeyEvent();
};

#endif /* _TOUCH_MANAGER_H_ */