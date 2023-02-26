#include "ScreenManager.hpp"
#include "Screens/Screen.hpp"
#include "Screens/TitleScreen.hpp"
#include "Screens/GameScreen.hpp"
#include "Screens/MusicRoomScreen.hpp"
#include "Screens/ModeSelectScreen.hpp"
#include "GameWindow.hpp"

ScreenManager::ScreenManager() {
    this->screen = std::make_unique<TitleScreen>();
}

ScreenManager::~ScreenManager() {
}

void ScreenManager::Render(GameWindow* game_window) {
    ScreenID id = screen->Render(game_window);
    if(screen->getScreenID() != id) {
        //Screenを追加した場合には、ここにIDとScreenを追加
        switch(id) {
            case ScreenID::Title:
                this->screen = std::make_unique<TitleScreen>();
                break;
            case ScreenID::Game:
                this->screen = std::make_unique<GameScreen>(game_window->config);
                break;
            case ScreenID::MusicRoom:
                this->screen = std::make_unique<MusicRoomScreen>();
                break;
            case ScreenID::ModeSelect:
                this->screen = std::make_unique<ModeSelectScreen>();
                break;
            default:
                break;
        }
    }

    //FPSを描画する
    this->fps.Update();
    this->fps.DrawFPS(game_window);
}