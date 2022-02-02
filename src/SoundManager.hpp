#ifndef _SOUND_MANAGER_H_
#define _SOUND_MANAGER_H_

#include "Const/SoundID.hpp"
#include <SDL2/SDL_mixer.h>
#include <unordered_map>

class SoundManager {
private:
    std::unordered_map<SoundEffectID, Mix_Chunk*> se_map;
    std::unordered_map<BGMID, Mix_Music*> bgm_map;
public:
    SoundManager(std::string base_path);
    virtual ~SoundManager();
    void PlaySE(SoundEffectID se_id);
    void SetSEVolume(int se_volume);
    void SetBGMVolume(int bgm_volume);
};

#endif /* _SOUND_MANAGER_H_ */