#include "Operate.hpp"
#include "Config.hpp"
#include "Const/TouchRect.hpp"
#include "InputManager/KeyboardManager.hpp"
#include "InputManager/JoystickManager.hpp"
#include "InputManager/TouchManager.hpp"
#include "Config.hpp"
#include <cmath>

Operate::Operate(unsigned int width, unsigned int height) {
    this->width = width;
    this->height = height;
    this->EnableJoyStickButton = true;
}

//すべてのInputManagerより、自機の動きやどのボタンが押されたかをセットする
void Operate::Polling(KeyboardManager* keyboard_manager, JoystickManager* joystick_manager, TouchManager* touch_manager, Config* config) {
    std::map<Buttons, bool> tmpPressing;
    //キーボードより押されているボタンの取得
    tmpPressing[Buttons::Up] = keyboard_manager->IsKeyDown(SDLK_UP);
    tmpPressing[Buttons::Down] = keyboard_manager->IsKeyDown(SDLK_DOWN);
    tmpPressing[Buttons::Left] = keyboard_manager->IsKeyDown(SDLK_LEFT);
    tmpPressing[Buttons::Right] = keyboard_manager->IsKeyDown(SDLK_RIGHT);
    tmpPressing[Buttons::Bomb] = keyboard_manager->IsKeyDown(SDLK_x);
    tmpPressing[Buttons::Shot] = keyboard_manager->IsKeyDown(SDLK_z);
    tmpPressing[Buttons::Pause] = keyboard_manager->IsKeyDown(SDLK_ESCAPE);
    tmpPressing[Buttons::Skip] = keyboard_manager->IsKeyDown(SDLK_LCTRL) || keyboard_manager->IsKeyDown(SDLK_RCTRL);
    tmpPressing[Buttons::Slow] = keyboard_manager->IsKeyDown(SDLK_LSHIFT) || keyboard_manager->IsKeyDown(SDLK_RSHIFT);

    //キーボードの押下情報より、現在の方向を取得
    this->NowAxis[0] = 0;
    this->NowAxis[1] = 0;

    if(tmpPressing[Buttons::Up]) {
        this->NowAxis[1] += -1;
    }
    if(tmpPressing[Buttons::Right]) {
        this->NowAxis[0] += 1;
    }
    if(tmpPressing[Buttons::Down]) {
        this->NowAxis[1] += 1;
    }
    if(tmpPressing[Buttons::Left]) {
        this->NowAxis[0] += -1;
    }

    {
        //タブレットやスマホ用のタッチ操作での方向やボタンを取得
        std::vector<SDL_FingerID> finger_list = touch_manager->GetFingerIDList();
        for(SDL_FingerID& id : finger_list) {
            Point now_point = touch_manager->GetTouchingPos(id);
            Point first_point = touch_manager->GetFirstTouchPos(id);
            if(first_point.x < 0.5) {
                //十字キー側
                float dx = now_point.x - first_point.x;
                float dy = now_point.y - first_point.y;
                if(dx > 0.1) {
                    tmpPressing[Buttons::Right] |= true;
                }
                if(dx < -0.1) {
                    tmpPressing[Buttons::Left] |= true;
                }
                if(dy > 0.1) {
                    tmpPressing[Buttons::Down] |= true;
                }
                if(dy < -0.1) {
                    tmpPressing[Buttons::Up] |= true;
                }

                this->NowAxis[0] = std::clamp(dx / 0.1, -1.0, 1.0);
                this->NowAxis[1] = std::clamp(dy / 0.1, -1.0, 1.0);
            }
            if(first_point.x >= 0.5 && now_point.x >= 0.5) {
                //ショットやボムなどのボタン
                const std::vector<Buttons> touch_buttons = {
                    Buttons::Bomb,
                    Buttons::Pause,
                    Buttons::Shot,
                    Buttons::Skip,
                    Buttons::Slow
                };
                for(size_t i = 0; i < touch_buttons.size(); i++) {
                    SDL_Rect rect = TouchRectList[touch_buttons[i]];
                    if(first_point.x >= (rect.x / static_cast<double>(this->width)) && first_point.x <= ((rect.x + rect.w) / static_cast<double>(this->width)) && first_point.y >= (rect.y / static_cast<double>(this->height)) && first_point.y <= ((rect.y + rect.h) / static_cast<double>(this->height)) && now_point.x >= (rect.x / static_cast<double>(this->width)) && now_point.x <= ((rect.x + rect.w) / static_cast<double>(this->width)) && now_point.y >= (rect.y / static_cast<double>(this->height)) && now_point.y <= ((rect.y + rect.h) / static_cast<double>(this->height)))
                        tmpPressing[touch_buttons[i]] |= true;
                }
            }
        }
    }

    if(joystick_manager->getEnableJoyStick()) {
        //ジョイスティックの情報を取得
        if(this->EnableJoyStickButton) {
            for(const auto& it : config->joystick_buttons_map) {
                tmpPressing[it.first] |= joystick_manager->IsButtonDown(it.second);
            }
        }

        if(joystick_manager->getEnableAxis()) {

            tmpPressing[Buttons::Right] |= (joystick_manager->getAxis(0) > 24576);
            tmpPressing[Buttons::Left] |= (joystick_manager->getAxis(0) < -24576);
            tmpPressing[Buttons::Down] |= (joystick_manager->getAxis(1) > 24576);
            tmpPressing[Buttons::Up] |= (joystick_manager->getAxis(1) < -24576);

            //以下Axis
            this->NowAxis[0] = joystick_manager->getAxis(0) / 32768.0;
            this->NowAxis[1] = joystick_manager->getAxis(1) / 32768.0;
        }
    }

    //遊び
    if(this->NowAxis[0] < 0)
        this->NowAxis[0] = (std::min(this->NowAxis[0] + 0.1, 0.0) / 0.9);
    else
        this->NowAxis[0] = (std::max(this->NowAxis[0] - 0.1, 0.0) / 0.9);

    if(this->NowAxis[1] < 0)
        this->NowAxis[1] = (std::min(this->NowAxis[1] + 0.1, 0.0) / 0.9);
    else
        this->NowAxis[1] = (std::max(this->NowAxis[1] - 0.1, 0.0) / 0.9);

    double angle = std::atan2(-this->NowAxis[1], this->NowAxis[0]);
    this->NowAxis[0] = std::cos(angle) * std::abs(this->NowAxis[0]);
    this->NowAxis[1] = -std::sin(angle) * std::abs(this->NowAxis[1]);

    //前回押されていなくて、今回押されていた場合は、初回なのでPressedに格納
    for(int i=0;i<8;i++) {
        if((!Pressing[static_cast<Buttons>(i)] && tmpPressing[static_cast<Buttons>(i)])) {
            Pressed[static_cast<Buttons>(i)] = true;

            //初回だけマイナス値を与えることで、調節
            if(static_cast<int>(Buttons::Up) <= i && i <= static_cast<int>(Buttons::Right))
                PressingCount[static_cast<Buttons>(i)] = -30;
        } else {
            Pressed[static_cast<Buttons>(i)] = false;
        }
        if(static_cast<int>(Buttons::Up) <= i && i <= static_cast<int>(Buttons::Right)) {
            if(tmpPressing[static_cast<Buttons>(i)])
                PressingCount[static_cast<Buttons>(i)]++;
            if(PressingCount[static_cast<Buttons>(i)] >= 7) {
                Pressed[static_cast<Buttons>(i)] = true;
                PressingCount[static_cast<Buttons>(i)] = 0;
            }
        }
    }

    this->Pressing = tmpPressing;
}

//自機の動きを返す
void Operate::GetSelfMovements(float* x, float* y) {
    *x = this->NowAxis[0];
    *y = this->NowAxis[1];
}
