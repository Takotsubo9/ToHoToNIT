#ifndef _IMAGEID_H_
#define _IMAGEID_H_

#include <map>
#include <string>

//画像のID
enum class ImageID {
    number,
    number_selected,
    fps_text,
    title_items,
    title_selected_items,
    option_items,
    option_selected_items,
    option_fullscreen_mode,
    option_selected_fullscreen_mode,
};

//画像IDに対するファイルパス
const std::map<ImageID, std::string> FilePathList = {
    {ImageID::number, "image/number.bmp"},
    {ImageID::number_selected, "image/number_selected.bmp"},
    {ImageID::fps_text, "image/fps_text.bmp"},
    {ImageID::title_items, "image/title/title_items.bmp"},
    {ImageID::title_selected_items, "image/title/title_selected_items.bmp"},
    {ImageID::option_items, "image/option/option_items.bmp"},
    {ImageID::option_selected_items, "image/option/option_selected_items.bmp"},
    {ImageID::option_fullscreen_mode, "image/option/option_fullscreen_mode.bmp"},
    {ImageID::option_selected_fullscreen_mode, "image/option/option_selected_fullscreen_mode.bmp"}
};

#endif /* _IMAGEID_H_ */