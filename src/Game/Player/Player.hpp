#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "../../Config.hpp"
#include "../../Const/CharacterID.hpp"
#include "Chara/Character.hpp"
#include "Chara/MarisaMa.hpp"
#include "Chara/MarisaKoi.hpp"
#include "Chara/ReimuRei.hpp"
#include "Chara/ReimuYume.hpp"
#include "Chara/SatsukiHana.hpp"
#include "Chara/SatsukiKaze.hpp"
#include "Chara/TestChara.hpp"
#include <cmath>
#include <memory>

class Player {
private:
    std::unique_ptr<Character> chara;
    unsigned long AllPoint;
    unsigned int DefaultPlayerCount;
    unsigned int DefaultBombCount;
    unsigned int PlayerCount;
    unsigned int BombCount;
    unsigned int Power;
    unsigned int Graze;
    unsigned int Point;
public:
    Player(Config& config);
    virtual ~Player();
    Character * getCharacter(){
        return this->chara.get();
    }
    unsigned long getAllPoint() {
        return this->AllPoint;
    }
    unsigned int getPlayerCount() {
        return this->PlayerCount;
    }
    unsigned int getBombCount() {
        return this->BombCount;
    }
    unsigned int getPower() {
        return this->Power;
    }
    unsigned int getGraze() {
        return this->Graze;
    }
    unsigned int getPoint() {
        return this->Point;
    }
    void setPower(unsigned int power) {
        this->Power = std::min(static_cast<unsigned int>(128), std::max(static_cast<unsigned int>(0), power));
    }
    void setPlayerCount(unsigned int player_count) {
        this->PlayerCount = std::min(static_cast<unsigned int>(8), std::max(static_cast<unsigned int>(0), player_count));
    }
    void setBombCount(unsigned int bomb_count) {
        this->BombCount = std::min(static_cast<unsigned int>(8), std::max(static_cast<unsigned int>(0), bomb_count));
    }
    void incleaseGraze() {
        this->Graze++;
    }
    void incleasePoint() {
        this->Point++;
    }
};

#endif /* _PLAYER_H_ */