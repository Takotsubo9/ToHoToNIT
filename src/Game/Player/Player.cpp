#include "Player.hpp"

Player::Player(CharacterID charaID, Config& config) {
    switch(charaID) {
        case CharacterID::SatsukiHana:
            this->chara = new SatsukiHana();
            break;
        case CharacterID::SatsukiKaze:
            this->chara = new SatsukiKaze();
            break;
        default:
            this->chara = new TestChara();
            break;
    }
    this->AllPoint = 0;
    this->BombCount = config.getBombCount();
    this->Graze = 0;
    this->PlayerCount = config.getPlayerCount();
    this->Point = 0;
    this->Power = 0;
}