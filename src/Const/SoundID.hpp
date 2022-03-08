#ifndef _SOUNDID_H_
#define _SOUNDID_H_

#include <unordered_map>
#include <string>

//SEのID
enum class SoundEffectID {
    decide,
    move,
    cancel,
};

//SEのIDに対するファイルパス
extern const std::unordered_map<SoundEffectID, std::string> SEFilePathList;

//BGMのID
enum class BGMID {

};

//BGMのIDに対するファイルパス
extern const std::unordered_map<BGMID, std::string> BGMFilePathList;

#endif /* _SOUNDID_H_ */