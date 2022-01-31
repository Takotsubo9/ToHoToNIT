#include "ScreenManager.hpp"
#include "Screens/TitleScreen.hpp"
#include "Screens/GameScreen.hpp"
#include "Screens/MusicRoomScreen.hpp"
#include "GameWindow.hpp"

ScreenManager::ScreenManager() {
    this->screen = new TitleScreen();
}

ScreenManager::~ScreenManager() {
    delete this->screen;
}

void ScreenManager::Render(GameWindow* game_window) {
    ScreenID id = screen->Render(game_window);
    if(screen->getScreenID() != id) {
        delete this->screen;
        switch(id) {
            case ScreenID::Title:
                this->screen = new TitleScreen();
                break;
            case ScreenID::Game:
                this->screen = new GameScreen();
                break;
            case ScreenID::MusicRoom:
                this->screen = new MusicRoomScreen();
            default:
                break;
        }
    }

    this->fps.Update();
    this->fps.DrawFPS(game_window);
}