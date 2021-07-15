#ifndef _KEYBOARDMANAGER_H_
#define _KEYBOARDMANAGER_H_

#include <iostream>
#include <string>
#include <map>
#include <SDL2/SDL.h>

//キーボードの入力を管理するクラス
class KeyboardManager {
private:
    std::map<SDL_Keycode, bool> KeyDownState;
    std::map<SDL_Keycode, bool> KeyPressed;
    std::map<SDL_Keycode, bool> KeyReleased;
public:
    bool IsKeyDown(SDL_Keycode keycode) { return KeyDownState[keycode]; }
    bool IsKeyPressed(SDL_Keycode keycode) { return KeyPressed[keycode]; }
    bool IsKeyReleased(SDL_Keycode keycode) { return KeyReleased[keycode]; }
    void Polling(SDL_Event e);
    void ClearKeyEvent();
};

#endif /* _KEYBOARDMANAGER_H_ */