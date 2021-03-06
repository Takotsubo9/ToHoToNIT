#include "JoystickManager.hpp"

JoystickManager::JoystickManager() {
    joystick = nullptr;
    this->TrySetJoyStick();
}

JoystickManager::~JoystickManager() {
    if(SDL_JoystickGetAttached(joystick)) {
        SDL_JoystickClose(joystick);
    }
}

void JoystickManager::TrySetJoyStick() {
    if(joystick != nullptr) {
        joystick = nullptr;
    }
    if(SDL_NumJoysticks() > 0) {
        joystick = SDL_JoystickOpen(0);
    }
}

short JoystickManager::GetAxis(int num) {
    if(SDL_JoystickGetAttached(joystick))
        if(SDL_JoystickNumAxes(joystick) > num)
            return SDL_JoystickGetAxis(joystick, num);
        else
            return 0;
    else 
        return 0;
}

void JoystickManager::Polling(SDL_Event e) {
    if(e.type == SDL_JOYBUTTONDOWN) {
        ButtonDownState[e.jbutton.button] = true;
        ButtonPressed[e.jbutton.button] = true;
        ButtonEvent.push_back(e.jbutton.button);
    }
    else if(e.type == SDL_JOYBUTTONUP) {
        ButtonDownState[e.jbutton.button] = false;
        ButtonReleased[e.jbutton.button] = true;
    }
}

void JoystickManager::ClearKeyEvent() {
    ButtonPressed.clear();
    ButtonReleased.clear();
    ButtonEvent.clear();
}