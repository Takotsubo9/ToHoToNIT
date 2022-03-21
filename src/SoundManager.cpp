#include "SoundManager.hpp"
#include <iostream>

SoundManager::SoundManager(std::string base_path) {
    //SEFilePathListに記載されたSEをすべて読み込む
    for(std::unordered_map<SoundEffectID, std::string>::const_iterator it = SEFilePathList.begin(); it != SEFilePathList.end(); ++it) {
        Mix_Chunk* cnk = Mix_LoadWAV((base_path + it->second).c_str());
        this->se_map[it->first] = cnk;
    }
    //BGMFilePathListに記載されたBGMをすべて読み込む
    for(std::unordered_map<BGMID, std::string>::const_iterator it = BGMFilePathList.begin(); it != BGMFilePathList.end(); ++it) {
        Mix_Music* mus = Mix_LoadMUS((base_path + it->second).c_str());
        this->bgm_map[it->first] = mus;
    }
}

SoundManager::~SoundManager() {
    //読み込まれたSEを全解放する
    for(std::unordered_map<SoundEffectID, Mix_Chunk*>::iterator it = this->se_map.begin(); it != this->se_map.end(); ++it) {
        Mix_FreeChunk(it->second);
    }
    //読み込まれたBGMを全解放する
    for(std::unordered_map<BGMID, Mix_Music*>::iterator it = this->bgm_map.begin(); it != this->bgm_map.end(); ++it) {
        Mix_FreeMusic(it->second);
    }
}

void SoundManager::PlaySE(SoundEffectID se_id) {
    //チャンネルを自動割当でSEを再生する
    Mix_PlayChannel(-1, se_map[se_id], 0);
}

void SoundManager::SetSEVolume(int se_volume) {
    //読み込まれたすべてのSEに対してボリュームの割当をする
    //se_volumeの値は0~100
    for(std::unordered_map<SoundEffectID, Mix_Chunk*>::iterator it = this->se_map.begin(); it != this->se_map.end(); ++it) {
        if (it->second != NULL)
            Mix_VolumeChunk(it->second, se_volume * 128.0 / 100.0);
    }
}

void SoundManager::SetBGMVolume(int bgm_volume) {
    //BGM再生用チャンネルに対してボリュームの割当をする
    //bgm_volumeの値は0~100
    Mix_VolumeMusic(bgm_volume * 128.0 / 100.0);
}