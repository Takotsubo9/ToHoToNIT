#ifndef _CONFIG_H_
#define _CONFIG_H_

#include <algorithm>
#include <unordered_map>
#include <string>
#include "Const/Buttons.hpp"

const int UNDEFINED_BUTTONS = -1;

class Config {
private:
    int player_count;
    int bomb_count;
    int bgm_volume;
    int se_volume;
public:
    std::unordered_map<Buttons, int> joystick_buttons_map;
    Config(){
        this->Reset();
        this->KeyConfigReset();
    }
    virtual ~Config(){}
    void setPlayerCount(int player_count) {
        this->player_count = ((player_count - 1 + 5) % 5) + 1;
    }
    
    void setBombCount(int bomb_count) {
        this->bomb_count = (bomb_count + 4) % 4;
    }

    void setBGMVolume(int bgm_volume) {
        this->bgm_volume = std::max(0, std::min(100, bgm_volume));
    }
    
    void setSEVolume(int se_volume) {
        this->se_volume = std::max(0, std::min(100, se_volume));
    }

    int getPlayerCount() {
        return player_count;
    }
    
    int getBombCount() {
        return bomb_count;
    }

    int getBGMVolume() {
        return bgm_volume;
    }
    
    int getSEVolume() {
        return se_volume;
    }

    void Reset() {
        this->player_count = 3;
        this->bomb_count = 3;
        this->bgm_volume = 100;
        this->se_volume = 100;
    }

    void KeyConfigReset() {
        joystick_buttons_map[Buttons::Shot] = 0;
        joystick_buttons_map[Buttons::Bomb] = 1;
        joystick_buttons_map[Buttons::Slow] = 2;
        joystick_buttons_map[Buttons::Up] = UNDEFINED_BUTTONS;
        joystick_buttons_map[Buttons::Down] = UNDEFINED_BUTTONS;
        joystick_buttons_map[Buttons::Left] = UNDEFINED_BUTTONS;
        joystick_buttons_map[Buttons::Right] = UNDEFINED_BUTTONS;
        joystick_buttons_map[Buttons::Pause] = UNDEFINED_BUTTONS;
        joystick_buttons_map[Buttons::Skip] = UNDEFINED_BUTTONS;
    }
};

#endif /* _CONFIG_H_ */