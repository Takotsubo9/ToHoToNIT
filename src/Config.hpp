#ifndef _CONFIG_H_
#define _CONFIG_H_

#include <algorithm>

class Config {
private:
    int player_count;
    int bomb_count;
    int bgm_volume;
    int se_volume;
public:
    Config(){
        this->Reset();
    }
    ~Config(){}
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
};

#endif /* _CONFIG_H_ */