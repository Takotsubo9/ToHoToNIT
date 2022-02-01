#ifndef _SOUND_MANAGER_H_
#define _SOUND_MANAGER_H_

#include "Const/SoundID.hpp"
#include <SDL2/SDL_mixer.h>
#include <map>

class SoundManager {
private:
    std::map<SoundEffectID, Mix_Chunk*> se_map;
    std::map<BGMID, Mix_Music*> bgm_map;
public:
    SoundManager(std::string base_path);
    virtual ~SoundManager();
    void PlaySE(SoundEffectID se_id);
};

#endif /* _SOUND_MANAGER_H_ */