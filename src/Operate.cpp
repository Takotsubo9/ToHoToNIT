#include "Operate.hpp"
#include "Config.hpp"
#include "Const/WindowSize.hpp"
#include "Const/TouchRect.hpp"
#include "InputManager/KeyboardManager.hpp"
#include "InputManager/JoystickManager.hpp"
#include <cmath>
#include <iostream>

void Operate::Polling(KeyboardManager* keyboard_manager, JoystickManager* joystick_manager, TouchManager* touch_manager, Config* config) {
    this->tmpPressing[Buttons::Up] = keyboard_manager->IsKeyDown(SDLK_UP);
    this->tmpPressing[Buttons::Down] = keyboard_manager->IsKeyDown(SDLK_DOWN);
    this->tmpPressing[Buttons::Left] = keyboard_manager->IsKeyDown(SDLK_LEFT);
    this->tmpPressing[Buttons::Right] = keyboard_manager->IsKeyDown(SDLK_RIGHT);
    this->tmpPressing[Buttons::Bomb] = keyboard_manager->IsKeyDown(SDLK_x);
    this->tmpPressing[Buttons::Shot] = keyboard_manager->IsKeyDown(SDLK_z);
    this->tmpPressing[Buttons::Pause] = keyboard_manager->IsKeyDown(SDLK_ESCAPE);
    this->tmpPressing[Buttons::Skip] = keyboard_manager->IsKeyDown(SDLK_LCTRL) || keyboard_manager->IsKeyDown(SDLK_RCTRL);
    this->tmpPressing[Buttons::Slow] = keyboard_manager->IsKeyDown(SDLK_LSHIFT) || keyboard_manager->IsKeyDown(SDLK_RSHIFT);


    this->NowAxis[0] = 0;
    this->NowAxis[1] = 0;

    if(this->tmpPressing[Buttons::Up]) {
        this->NowAxis[1] += -1;
    }
    if(this->tmpPressing[Buttons::Right]) {
        this->NowAxis[0] += 1;
    }
    if(this->tmpPressing[Buttons::Down]) {
        this->NowAxis[1] += 1;
    }
    if(this->tmpPressing[Buttons::Left]) {
        this->NowAxis[0] += -1;
    } 

    if(this->NowAxis[0] != 0 && this->NowAxis[1] != 0) {
        this->NowAxis[0] /= 1.41;
        this->NowAxis[1] /= 1.41;
    }

    {
        std::vector<SDL_FingerID> finger_list = touch_manager->GetFingerIDList();
        for(SDL_FingerID& id : finger_list) {
            Point now_point = touch_manager->GetTouchingPos(id);
            Point first_point = touch_manager->GetFirstTouchPos(id);
            if(first_point.x < 0.5 && now_point.x < 0.5) {
                //十字キー側
                float dx = now_point.x - first_point.x;
                float dy = now_point.y - first_point.y;
                if(dx > 0.1) {
                    this->tmpPressing[Buttons::Right] |= true;
                }
                if(dx < -0.1) {
                    this->tmpPressing[Buttons::Left] |= true;
                }
                if(dy > 0.1) {
                    this->tmpPressing[Buttons::Down] |= true;
                }
                if(dy < -0.1) {
                    this->tmpPressing[Buttons::Up] |= true;
                }

                float angle;
                if(dx != 0) {
                    angle = std::atan(-dy/static_cast<double>(dx));
                    if(dx<0) {
                        angle += M_PI;
                    }
                } else {
                    angle = M_PI / 2.0;
                    if(dy > 0) {
                        angle += M_PI;
                    } 
                }

                this->NowAxis[0] = std::cos(angle) * std::min(std::abs(dx / 0.1), 1.0);
                this->NowAxis[1] = -std::sin(angle) * std::min(std::abs(dy / 0.1), 1.0);
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
                    if(first_point.x >= (rect.x / static_cast<double>(WINDOW_WIDTH)) && first_point.x <= ((rect.x + rect.w) / static_cast<double>(WINDOW_WIDTH)) && first_point.y >= (rect.y / static_cast<double>(WINDOW_HEIGHT)) && first_point.y <= ((rect.y + rect.h) / static_cast<double>(WINDOW_HEIGHT)) && now_point.x >= (rect.x / static_cast<double>(WINDOW_WIDTH)) && now_point.x <= ((rect.x + rect.w) / static_cast<double>(WINDOW_WIDTH)) && now_point.y >= (rect.y / static_cast<double>(WINDOW_HEIGHT)) && now_point.y <= ((rect.y + rect.h) / static_cast<double>(WINDOW_HEIGHT)))
                        this->tmpPressing[touch_buttons[i]] |= true;
                }
            }
        }
    }

    if(joystick_manager->getEnableJoyStick()) {
        if(this->EnableJoyStickButton) {
            for(std::unordered_map<Buttons, int>::const_iterator it = config->joystick_buttons_map.begin(); it != config->joystick_buttons_map.end(); ++it) {
                this->tmpPressing[it->first] |= joystick_manager->IsButtonDown(it->second);
            }
        }

        if(joystick_manager->getEnableAxis()) {

            this->tmpPressing[Buttons::Right] |= (joystick_manager->getAxis(0) > 24576);
            this->tmpPressing[Buttons::Left] |= (joystick_manager->getAxis(0) < -24576);
            this->tmpPressing[Buttons::Down] |= (joystick_manager->getAxis(1) > 24576);
            this->tmpPressing[Buttons::Up] |= (joystick_manager->getAxis(1) < -24576);

            //以下Axis
            float angle;
            if(joystick_manager->getAxis(0)!=0) {
                angle = std::atan(-joystick_manager->getAxis(1)/static_cast<double>(joystick_manager->getAxis(0)));
                if(joystick_manager->getAxis(0)<0) {
                    angle += M_PI;
                }
            } else {
                angle = M_PI / 2.0;
                if(joystick_manager->getAxis(1)>0) {
                    angle += M_PI;
                } 
            }

            this->NowAxis[0] = std::cos(angle) * std::abs(joystick_manager->getAxis(0) / 32768.0);
            this->NowAxis[1] = -std::sin(angle) * std::abs(joystick_manager->getAxis(1) / 32768.0);
        }
    }

    for(int i=0;i<8;i++) {
        Pressed[static_cast<Buttons>(i)] = (!Pressing[static_cast<Buttons>(i)] && tmpPressing[static_cast<Buttons>(i)]);
    }

    this->Pressing = this->tmpPressing;
}

void Operate::GetSelfMovements(float* x, float* y) {
    *x = this->NowAxis[0];
    *y = this->NowAxis[1];
}
