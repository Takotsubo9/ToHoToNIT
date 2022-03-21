#ifndef _IMAGEID_H_
#define _IMAGEID_H_

#include <unordered_map>
#include <string>

//画像のID
enum class ImageID {
    number,
    number_selected,
    fps_text,
    game_frame,
    game_pause_menu,
    game_power_gauge,
    game_power_max_text,
    game_status,
    title_items,
    title_selected_items,
    title_background,
    title_logo,
    option_items,
    option_selected_items,
    option_fullscreen_mode,
    option_selected_fullscreen_mode,
    keyconfig_items,
    keyconfig_selected_items,
    musicroom_background,
};

//画像IDに対するファイルパス
extern const std::unordered_map<ImageID, std::string> FilePathList;

#endif /* _IMAGEID_H_ */