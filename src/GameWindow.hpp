#ifndef _GAMEWINDOW_H_
#define _GAMEWINDOW_H_

#include <string>
#include <SDL2/SDL.h>
#include "InputManager/KeyboardManager.hpp"
#include "InputManager/JoystickManager.hpp"
#include "ScreenManager.hpp"
#include "ImageManager.hpp"
#include "Const/FullScreenMode.hpp"

//メインウィンドウのクラス
class GameWindow {
private:
    unsigned int main_fps;
    bool is_active;
    KeyboardManager* keyboard_manager;
    JoystickManager* joystick_manager;
    ImageManager* image_manager;
    FullScreenMODE fullscreen_mode;
    SDL_Window* window_handle;
    SDL_Renderer* renderer_handle;
    bool quit;
public:
    GameWindow(std::string window_title, int width, int height);
    ~GameWindow();
    //ウィンドウの
    void Run();
    //ウィンドウのフルスクリーンモードをセットする関数
    void setFullScreenMode(FullScreenMODE fsm);
    FullScreenMODE getFullScreenMode() const {
        return fullscreen_mode;
    }
    //引数に与えられたキーが押されているかを返す関数
    bool getIsKeyDown(SDL_Keycode skc) const {
        return this->keyboard_manager->IsKeyDown(skc);
    }
    //引数に与えられたキーが離されたかを返す関数
    bool getIsKeyReleased(SDL_Keycode skc) const {
        return this->keyboard_manager->IsKeyReleased(skc);
    }
    //引数に与えられたキーが押されたかを返す関数
    bool getIsKeyPressed(SDL_Keycode skc) const {
        return this->keyboard_manager->IsKeyPressed(skc);
    }
    //引数に与えられた番号目のスティックの状況を返す関数
    short getAxis(int num) const {
        return this->joystick_manager->GetAxis(num);
    }
    //引数に与えられた番号のボタンが押されているかを返す関数
    bool getIsJoyButtonDown(int num) const {
        return this->joystick_manager->IsButtonDown(num);
    }
    //引数に与えられた番号のボタンが離されたかを返す関数
    bool getIsJoyButtonReleased(int num) const {
        return this->joystick_manager->IsButtonReleased(num);
    }
    //引数に与えられた番号のボタンが押されたかを返す関数
    bool getIsJoyButtonPressed(int num) const {
        return this->joystick_manager->IsButtonPressed(num);
    }
    //引数に与えられたIDの画像を描画する関数
    void DrawImage(ImageID image_id, const SDL_Rect* srcrect, const SDL_Rect* dstrect) {
        this->image_manager->Render(renderer_handle, image_id, srcrect, dstrect);
    }
    //引数に与えられた色を描画する関数
    void FillRect(uint8_t r, uint8_t g, uint8_t b, uint8_t a, const SDL_Rect* rect) {
        SDL_SetRenderDrawColor(renderer_handle, r, g, b, a );
        SDL_RenderFillRect(renderer_handle, rect);
    }
    //ウィンドウを閉じる関数
    void Quit() {
        this->quit = true;
    }
};

#endif /* _GAMEWINDOW_H_ */