#ifndef _JOYSTICKMANAGER_H_
#define _JOYSTICKMANAGER_H_

#include <iostream>
#include <map>
#include <vector>
#include <SDL2/SDL.h>

//ジョイスティックの入力を管理するクラス
class JoystickManager {
private:
    std::map<int, bool> ButtonDownState;
    std::map<int, bool> ButtonPressed;
    std::map<int, bool> ButtonReleased;
    std::vector<int> ButtonEvent;
    SDL_Joystick* joystick;
public:
    JoystickManager();
    ~JoystickManager();
    void TrySetJoyStick();
    bool getEnableJoyStick() { return joystick != nullptr; }
    bool getEnableAxis() { return SDL_JoystickNumAxes(joystick) != 0; }
    short GetAxis(int num);
    void Polling(SDL_Event e);
    void ClearKeyEvent();
    bool IsButtonDown(int button) { return ButtonDownState[button]; }
    bool IsButtonPressed(int button) { return ButtonPressed[button]; }
    bool IsButtonReleased(int button) { return ButtonReleased[button]; }
    std::vector<int> getButtonEvent() { return ButtonEvent; }
};

#endif /* _JOYSTICKMANAGER_H_ */