#ifdef __ANDROID__
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

#include "Config.hpp"
#include <iostream>

//コンフィグファイルのバージョン情報
const char* config_file_info = "Touhou-Koumatou Config File 1.00";

Config::Config() {
    this->fullscreen_mode = FullScreenMODE::Windowed;
    this->Reset();
    this->KeyConfigReset();
}

Config::~Config() {
    
}

//コンフィグの初期化
void Config::Reset() {
    this->player_count = 3;
    this->bomb_count = 3;
    this->bgm_volume = 100;
    this->se_volume = 100;
    this->selected_chara = CharacterID::TestChara;
}

//キーコンの初期化
void Config::KeyConfigReset() {
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

//コンフィグ情報のファイル出力
void Config::Export(std::string base_path) {
    std::string cfgfile_path = base_path + "Touhou-Koumatou.cfg";
    SDL_RWops* rw = SDL_RWFromFile(cfgfile_path.c_str(), "w");
    if(rw) {
        SDL_RWwrite(rw, config_file_info, 1, SDL_strlen(config_file_info));
        SDL_WriteU8(rw, player_count);
        SDL_WriteU8(rw, bomb_count);
        SDL_WriteU8(rw, bgm_volume);
        SDL_WriteU8(rw, se_volume);
        SDL_WriteU8(rw, static_cast<uint8_t>(fullscreen_mode));
        SDL_WriteLE32(rw, joystick_buttons_map[Buttons::Shot]);
        SDL_WriteLE32(rw, joystick_buttons_map[Buttons::Bomb]);
        SDL_WriteLE32(rw, joystick_buttons_map[Buttons::Slow]);
        SDL_WriteLE32(rw, joystick_buttons_map[Buttons::Up]);
        SDL_WriteLE32(rw, joystick_buttons_map[Buttons::Down]);
        SDL_WriteLE32(rw, joystick_buttons_map[Buttons::Left]);
        SDL_WriteLE32(rw, joystick_buttons_map[Buttons::Right]);
        SDL_WriteLE32(rw, joystick_buttons_map[Buttons::Pause]);
        SDL_WriteLE32(rw, joystick_buttons_map[Buttons::Skip]);
        SDL_RWclose(rw);
    }
}

//ファイルからコンフィグの読み込み
void Config::Import(std::string base_path) {
    std::string cfgfile_path = base_path + "Touhou-Koumatou.cfg";
    SDL_RWops* rw = SDL_RWFromFile(cfgfile_path.c_str(), "r");
    if(!rw) 
        return;
    
    char readfile[33] = {0};
    SDL_RWread(rw, readfile, 1, SDL_strlen(config_file_info));
    if(SDL_strcmp(readfile, config_file_info) == 0) {
        player_count = SDL_ReadU8(rw);
        bomb_count = SDL_ReadU8(rw);
        bgm_volume = SDL_ReadU8(rw);
        se_volume = SDL_ReadU8(rw);
        fullscreen_mode = static_cast<FullScreenMODE>(SDL_ReadU8(rw));
        joystick_buttons_map[Buttons::Shot] = SDL_ReadLE32(rw);
        joystick_buttons_map[Buttons::Bomb] = SDL_ReadLE32(rw);
        joystick_buttons_map[Buttons::Slow] = SDL_ReadLE32(rw);
        joystick_buttons_map[Buttons::Up] = SDL_ReadLE32(rw);
        joystick_buttons_map[Buttons::Down] = SDL_ReadLE32(rw);
        joystick_buttons_map[Buttons::Left] = SDL_ReadLE32(rw);
        joystick_buttons_map[Buttons::Right] = SDL_ReadLE32(rw);
        joystick_buttons_map[Buttons::Pause] = SDL_ReadLE32(rw);
        joystick_buttons_map[Buttons::Skip] = SDL_ReadLE32(rw);
    } else {
        //コンフィグファイルのバージョンが違った際に警告を表示し、読み込まないようにする
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_WARNING, "Touhou-Koumatou", "The version of the configuration file is different.\nThe configuration file will not be loaded.", NULL);
    }

    SDL_RWclose(rw);
}