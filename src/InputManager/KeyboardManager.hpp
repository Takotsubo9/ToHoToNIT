#ifndef _KEYBOARDMANAGER_H_
#define _KEYBOARDMANAGER_H_

#include <string>
#include <unordered_map>
#if defined(__ANDROID__) && !defined(__TERMUX__)
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

//キーボードの入力を管理するクラス
class KeyboardManager {
private:
    std::unordered_map<SDL_Keycode, bool> KeyDownState;
    std::unordered_map<SDL_Keycode, bool> KeyPressed;
    std::unordered_map<SDL_Keycode, bool> KeyReleased;
public:
    bool IsKeyDown(SDL_Keycode keycode) { return KeyDownState[keycode]; }
    bool IsKeyPressed(SDL_Keycode keycode) { return KeyPressed[keycode]; }
    bool IsKeyReleased(SDL_Keycode keycode) { return KeyReleased[keycode]; }
    void Polling(SDL_Event e);
    void ClearKeyEvent();
};

#endif /* _KEYBOARDMANAGER_H_ */