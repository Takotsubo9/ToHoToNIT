#ifndef _OPERATE_H_
#define _OPERATE_H_

#include "InputManager/JoystickManager.hpp"
#include "InputManager/KeyboardManager.hpp"
#include "Const/Buttons.hpp"
#include "Config.hpp"
#include <map>

//入力を管理するクラス
class Operate {
private:
    std::map<Buttons, bool> Pressed;
    std::map<Buttons, bool> Pressing;

    std::map<Buttons, bool> tmpPressing;

    float NowAxis[2];
public:
    bool EnableJoyStickButton;
    Operate() {
        this->EnableJoyStickButton = true;
    }
    void Polling(KeyboardManager* KeyboardManager, JoystickManager* JoystickManager, Config* config);
    bool IsPressed(Buttons button) {
        return this->Pressed[button];
    }
    bool IsDown(Buttons button) {
        return this->Pressing[button];
    }
    void GetSelfMovements(float* x, float* y);
};

#endif /* _OPERATE_H_ */