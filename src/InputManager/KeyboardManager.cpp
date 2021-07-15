#include "KeyboardManager.hpp"

void KeyboardManager::Polling(SDL_Event e) {
    if(e.type == SDL_KEYDOWN) {
        if(KeyDownState[e.key.keysym.sym] == false)
            KeyPressed[e.key.keysym.sym] = true;
        KeyDownState[e.key.keysym.sym] = true;
    }
    else if(e.type == SDL_KEYUP) {
        if(KeyDownState[e.key.keysym.sym] == true)
            KeyReleased[e.key.keysym.sym] = true;
        KeyDownState[e.key.keysym.sym] = false;
    }
}

void KeyboardManager::ClearKeyEvent() {
    KeyPressed.clear();
    KeyReleased.clear();
}