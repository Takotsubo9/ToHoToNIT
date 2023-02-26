#include "Player.hpp"

Player::Player(Config& config) {
    switch(config.getSelectedCharacterID()) {
        case CharacterID::MarisaMa:
            this->chara = std::make_unique<MarisaMa>();
            break;
        case CharacterID::MarisaKoi:
            this->chara = std::make_unique<MarisaKoi>();
            break;
        case CharacterID::ReimuRei:
            this->chara = std::make_unique<ReimuRei>();
            break;
        case CharacterID::ReimuYume:
            this->chara = std::make_unique<ReimuYume>();
            break;
        case CharacterID::SatsukiHana:
            this->chara = std::make_unique<SatsukiHana>();
            break;
        case CharacterID::SatsukiKaze:
            this->chara = std::make_unique<SatsukiKaze>();
            break;
        default:
            this->chara = std::make_unique<TestChara>();
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

Player::~Player() {
    
}