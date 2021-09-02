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
    title_background,
    option_items,
    option_selected_items,
    option_fullscreen_mode,
    option_selected_fullscreen_mode,
    keyconfig_items,
    keyconfig_selected_items,
};

//画像IDに対するファイルパス
const std::map<ImageID, std::string> FilePathList = {
    {ImageID::number, "image/number.png"},
    {ImageID::number_selected, "image/number_selected.png"},
    {ImageID::fps_text, "image/fps_text.png"},
    {ImageID::title_items, "image/title/title_items.png"},
    {ImageID::title_selected_items, "image/title/title_selected_items.png"},
    {ImageID::title_background, "image/title/title_background.png"},
    {ImageID::option_items, "image/option/option_items.png"},
    {ImageID::option_selected_items, "image/option/option_selected_items.png"},
    {ImageID::option_fullscreen_mode, "image/option/option_fullscreen_mode.png"},
    {ImageID::option_selected_fullscreen_mode, "image/option/option_selected_fullscreen_mode.png"},
    {ImageID::keyconfig_items, "image/keyconfig/keyconfig_items.png"},
    {ImageID::keyconfig_selected_items, "image/keyconfig/keyconfig_selected_items.png"},
};

#endif /* _IMAGEID_H_ */