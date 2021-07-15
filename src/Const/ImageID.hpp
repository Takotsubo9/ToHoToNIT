#ifndef _IMAGEID_H_
#define _IMAGEID_H_

#include <map>
#include <string>

//画像のID
enum class ImageID {
    Number,
    FPSText
};

//画像IDに対するファイルパス
const std::map<ImageID, std::string> FilePathList = {
    {ImageID::Number, "image/Number.bmp"},
    {ImageID::FPSText, "image/FPS.bmp"}
};

#endif /* _IMAGEID_H_ */