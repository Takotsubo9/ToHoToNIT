#ifndef _IMAGEID_H_
#define _IMAGEID_H_

#include <map>
#include <string>

//画像のID
enum class ImageID {
    number,
    fps_text,
    title_items,
    title_selected_items,
};

//画像IDに対するファイルパス
const std::map<ImageID, std::string> FilePathList = {
    {ImageID::number, "image/number.bmp"},
    {ImageID::fps_text, "image/fps_text.bmp"},
    {ImageID::title_items, "image/title/title_items.bmp"},
    {ImageID::title_selected_items, "image/title/title_selected_items.bmp"}
};

#endif /* _IMAGEID_H_ */