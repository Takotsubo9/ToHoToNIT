#ifndef _GAMEWINDOW_H_
#define _GAMEWINDOW_H_

#if defined(__ANDROID__) && !defined(__TERMUX__)
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

#include <string>
#include <vector>
#include "InputManager/KeyboardManager.hpp"
#include "InputManager/JoystickManager.hpp"
#include "InputManager/TouchManager.hpp"
#include "Operate.hpp"
#include "ScreenManager.hpp"
#include "AssetsManager/ImageManager.hpp"
#include "AssetsManager/SoundManager.hpp"
#include "Const/FullScreenMode.hpp"
#include "Const/RefPoint.hpp"
#include "Config.hpp"

//メインウィンドウのクラス
class GameWindow {
private:
    unsigned int main_fps;
    bool is_active;
    KeyboardManager* keyboard_manager;
    JoystickManager* joystick_manager;
    TouchManager* touch_manager;
    Operate* operate;
    ImageManager* image_manager;
    SoundManager* sound_manager;
    SDL_Window* window_handle;
    SDL_Renderer* renderer_handle;
    std::string application_path;
    bool quit;
    void TouchGuide();
public:
    Config config;
    GameWindow(std::string window_title,unsigned int width, unsigned int height);
    virtual ~GameWindow();
    //ウィンドウの
    void Run();
    //ウィンドウのフルスクリーンモードをセットする関数
    void setFullScreenMode(FullScreenMODE fsm);
    FullScreenMODE getFullScreenMode() {
        return config.getFullScreenMode();
    }
    //引数に与えられたボタンが押されたかを返す関数
    bool getIsButtonPressed(Buttons button) {
        return this->operate->IsPressed(button);
    }
    //引数に与えられたボタンが押されているかを返す関数
    bool getIsButtonDown(Buttons button) {
        return this->operate->IsDown(button);
    }
    //自機の動きを返す関数
    void getMovement(float* x, float* y) {
        this->operate->GetSelfMovements(x, y);
    }
    std::string& getApplicationPath() {
        return this->application_path;
    }
    //引数に与えられたIDの画像を描画する関数(アルファあり)
    void DrawImage(ImageID image_id, const SDL_Rect* srcrect, const SDL_Rect* dstrect, RefPoint ref = RefPoint::LeftTop, uint8_t alpha = 0xff, double angle = 0, SDL_RendererFlip flip = SDL_FLIP_NONE) {
        SDL_Rect dst = *dstrect;
        switch(ref) {
            case RefPoint::Top:
                dst.x -= (dst.w / 2);
                break;
            case RefPoint::RightTop:
                dst.x -= dst.w;
                break;
            case RefPoint::Left:
                dst.y -= (dst.h / 2);
                break;
            case RefPoint::Center:
                dst.x -= (dst.w / 2);
                dst.y -= (dst.h / 2);
                break;
            case RefPoint::Right:
                dst.x -= dst.w;
                dst.y -= (dst.h / 2);
                break;
            case RefPoint::LeftBottom:
                dst.y -= dst.h;
                break;
            case RefPoint::Bottom:
                dst.x -= (dst.w / 2);
                dst.y -= dst.h;
                break;
            case RefPoint::RightBottom:
                dst.x -= dst.w;
                dst.y -= dst.h;
                break;
            default:
                break;
        }

        this->image_manager->Render(renderer_handle, image_id, srcrect, &dst, alpha, angle, flip);
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
    const std::vector<int>* getJoystickButtonEvent() {
        return this->joystick_manager->getButtonEvent();
    }
    void setJoystickButtonEnable(bool enable) {
        this->operate->EnableJoyStickButton = enable;
    }
    void PlaySE(SoundEffectID se_id) {
        this->sound_manager->PlaySE(se_id);
    }
    void SetSEVolume(int se_volume) {
        this->sound_manager->SetSEVolume(se_volume);
    }
    void SetBGMVolume(int bgm_volume) {
        this->sound_manager->SetBGMVolume(bgm_volume);
    }
};

#endif /* _GAMEWINDOW_H_ */