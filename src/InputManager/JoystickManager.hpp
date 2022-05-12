#ifndef _JOYSTICKMANAGER_H_
#define _JOYSTICKMANAGER_H_

#if defined(__ANDROID__) && !defined(__TERMUX__) 
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

#include <iostream>
#include <unordered_map>
#include <vector>

//ジョイスティックの入力を管理するクラス
class JoystickManager {
private:
    std::unordered_map<int, bool> ButtonDownState;
    std::unordered_map<int, bool> ButtonPressed;
    std::unordered_map<int, bool> ButtonReleased;
    std::vector<int> ButtonEvent;
    SDL_Joystick* joystick;
public:
    JoystickManager();
    virtual ~JoystickManager();
    void TrySetJoyStick();
    bool getEnableJoyStick() { return joystick != nullptr; }
    bool getEnableAxis() { return SDL_JoystickNumAxes(joystick) >= 2; }
    short getAxis(int num);
    void Polling(SDL_Event e);
    void ClearKeyEvent();
    bool IsButtonDown(int button) { return ButtonDownState[button]; }
    bool IsButtonPressed(int button) { return ButtonPressed[button]; }
    bool IsButtonReleased(int button) { return ButtonReleased[button]; }
    const std::vector<int>* getButtonEvent() { return &ButtonEvent; }
};

#endif /* _JOYSTICKMANAGER_H_ */