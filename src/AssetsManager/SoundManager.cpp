#if defined(__ANDROID__) && !defined(__TERMUX__)
#include <SDL.h>
#include <SDL_mixer.h>
#else
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#endif

#include "SoundManager.hpp"

SoundManager::SoundManager(std::string base_path) {
    //SEFilePathListに記載されたSEをすべて読み込む
    for(const auto& it : SEFilePathList) {
        Mix_Chunk* cnk = Mix_LoadWAV((base_path + it.second).c_str());
        if(cnk == nullptr)
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_WARNING, "Touhou-Koumatou", (std::string("Failed to open sound file\n") + it.second).c_str(), nullptr);
        this->se_map[it.first] = cnk;
    }
    //BGMFilePathListに記載されたBGMをすべて読み込む
    for(const auto& it : BGMFilePathList) {
        Mix_Music* mus = Mix_LoadMUS((base_path + it.second).c_str());
        if(mus == nullptr)
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_WARNING, "Touhou-Koumatou", (std::string("Failed to open music file\n") + it.second).c_str(), nullptr);
        this->bgm_map[it.first] = mus;
    }
}

SoundManager::~SoundManager() {
    //読み込まれたSEを全解放する
    for(const auto& it : this->se_map) {
        Mix_FreeChunk(it.second);
    }
    //読み込まれたBGMを全解放する
    for(const auto& it : this->bgm_map) {
        Mix_FreeMusic(it.second);
    }
}

void SoundManager::PlaySE(SoundEffectID se_id) {
    //チャンネルを自動割当でSEを再生する
    Mix_PlayChannel(-1, se_map[se_id], 0);
}

void SoundManager::SetSEVolume(int se_volume) {
    //読み込まれたすべてのSEに対してボリュームの割当をする
    //se_volumeの値は0~100
    for(const auto& it : this->se_map) {
        if (it.second != nullptr)
            Mix_VolumeChunk(it.second, se_volume * 128.0 / 100.0);
    }
}

void SoundManager::SetBGMVolume(int bgm_volume) {
    //BGM再生用チャンネルに対してボリュームの割当をする
    //bgm_volumeの値は0~100
    Mix_VolumeMusic(bgm_volume * 128.0 / 100.0);
}