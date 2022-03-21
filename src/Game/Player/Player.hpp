#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "../../Config.hpp"
#include "../../Const/CharacterID.hpp"
#include "../Chara/Character.hpp"
#include "../Chara/SatsukiHana.hpp"
#include "../Chara/SatsukiKaze.hpp"
#include "../Chara/TestChara.hpp"
#include <cmath>

class Player {
private:
    Character* chara;
    unsigned long AllPoint;
    unsigned int PlayerCount;
    unsigned int BombCount;
    unsigned int Power;
    unsigned int Graze;
    unsigned int Point;
public:
    Player(CharacterID charaID, Config& config);
    virtual ~Player() {
        delete this->chara;
    }
    Character * getCharacter(){
        return this->chara;
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
};

#endif /* _PLAYER_H_ */