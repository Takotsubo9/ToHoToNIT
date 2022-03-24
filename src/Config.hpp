#ifndef _CONFIG_H_
#define _CONFIG_H_

#include <algorithm>
#include <unordered_map>
#include <string>
#include "Const/Buttons.hpp"
#include "Const/FullScreenMode.hpp"
#include "Const/CharacterID.hpp"

const int UNDEFINED_BUTTONS = -1;

class Config {
private:
    uint8_t player_count;
    uint8_t bomb_count;
    uint8_t bgm_volume;
    uint8_t se_volume;
    FullScreenMODE fullscreen_mode;
    CharacterID selected_chara;
public:
    std::unordered_map<Buttons, int32_t> joystick_buttons_map;
    Config();
    virtual ~Config(){

    }
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

    void setFullScreenMode(FullScreenMODE fsm) {
        this->fullscreen_mode = fsm;
    }

    void setSelectedCharacterID(CharacterID chara) {
        this->selected_chara = chara;
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

    FullScreenMODE getFullScreenMode() {
        return fullscreen_mode;
    }

    CharacterID getSelectedCharacterID() {
        return selected_chara;
    }

    void Reset();
    void KeyConfigReset();
    void Export(std::string base_path);
    void Import(std::string base_path);
};

#endif /* _CONFIG_H_ */