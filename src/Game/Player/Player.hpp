#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "../../Config.hpp"
#include "../../Const/CharacterID.hpp"
#include "../Chara/Character.hpp"
#include "../Chara/SatsukiHana.hpp"
#include "../Chara/SatsukiKaze.hpp"
#include "../Chara/TestChara.hpp"

class Player {
private:
    Character* chara;
    long AllPoint;
    int PlayerCount;
    int BombCount;
    int Power;
    int Graze;
    int Point;
public:
    Player(CharacterID charaID, Config& config);
    virtual ~Player() {
        delete this->chara;
    }
    Character * getCharacter(){
        return this->chara;
    }
};

#endif /* _PLAYER_H_ */