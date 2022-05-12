#ifndef _SOUND_MANAGER_H_
#define _SOUND_MANAGER_H_

#include <unordered_map>
#if defined(__ANDROID__) && !defined(__TERMUX__)
#include <SDL_mixer.h>
#else
#include <SDL2/SDL_mixer.h>
#endif

#include "../Const/SoundID.hpp"

class SoundManager {
private:
    //SEを格納する用のmap
    std::unordered_map<SoundEffectID, Mix_Chunk*> se_map;
    //BGMを格納する用のmap
    std::unordered_map<BGMID, Mix_Music*> bgm_map;
public:
    SoundManager(std::string base_path);
    virtual ~SoundManager();
    void PlaySE(SoundEffectID se_id);
    void SetSEVolume(int se_volume);
    void SetBGMVolume(int bgm_volume);
};

#endif /* _SOUND_MANAGER_H_ */