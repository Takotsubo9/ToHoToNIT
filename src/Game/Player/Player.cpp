#include "Player.hpp"

Player::Player(Config& config) {
    switch(config.getSelectedCharacterID()) {
        case CharacterID::MarisaMa:
            this->chara = new MarisaMa();
            break;
        case CharacterID::MarisaKoi:
            this->chara = new MarisaKoi();
            break;
        case CharacterID::ReimuRei:
            this->chara = new ReimuRei();
            break;
        case CharacterID::ReimuYume:
            this->chara = new ReimuYume();
            break;
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
    this->DefaultBombCount = config.getBombCount();
    this->BombCount = config.getBombCount();
    this->Graze = 0;
    this->DefaultPlayerCount = config.getPlayerCount();
    this->PlayerCount = config.getPlayerCount();
    this->Point = 0;
    this->Power = 0;
}