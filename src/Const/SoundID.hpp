#ifndef _SOUNDID_H_
#define _SOUNDID_H_

#include <map>
#include <string>

//SEのID
enum class SoundEffectID {
    decide,
    move,
    cancel,
};

//SEのIDに対するファイルパス
const std::map<SoundEffectID, std::string> SEFilePathList = {
    {SoundEffectID::decide, "sound/se/decide.mp3"},
    {SoundEffectID::move, "sound/se/move.mp3"},
    {SoundEffectID::cancel, "sound/se/cancel.mp3"},
};

//BGMのID
enum class BGMID {

};

//BGMのIDに対するファイルパス
const std::map<BGMID, std::string> BGMFilePathList = {
    
};

#endif /* _SOUNDID_H_ */