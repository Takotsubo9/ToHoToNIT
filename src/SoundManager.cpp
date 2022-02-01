#include "SoundManager.hpp"
#include <iostream>

SoundManager::SoundManager(std::string base_path) {
    for(std::unordered_map<SoundEffectID, std::string>::const_iterator it = SEFilePathList.begin(); it != SEFilePathList.end(); ++it) {
        Mix_Chunk* cnk = Mix_LoadWAV((base_path + it->second).c_str());
        this->se_map[it->first] = cnk;
    }
    for(std::unordered_map<BGMID, std::string>::const_iterator it = BGMFilePathList.begin(); it != BGMFilePathList.end(); ++it) {
        Mix_Music* mus = Mix_LoadMUS((base_path + it->second).c_str());
        this->bgm_map[it->first] = mus;
    }
}

SoundManager::~SoundManager() {
    for(std::unordered_map<SoundEffectID, Mix_Chunk*>::iterator it = this->se_map.begin(); it != this->se_map.end(); ++it) {
        Mix_FreeChunk(it->second);
    }
    for(std::unordered_map<BGMID, Mix_Music*>::iterator it = this->bgm_map.begin(); it != this->bgm_map.end(); ++it) {
        Mix_FreeMusic(it->second);
    }
}

void SoundManager::PlaySE(SoundEffectID se_id) {
    Mix_PlayChannel(-1, se_map[se_id], 0);
}