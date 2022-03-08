#include "ImageID.hpp"


const std::unordered_map<ImageID, std::string> FilePathList = {
    {ImageID::number, "image/number.png"},
    {ImageID::number_selected, "image/number_selected.png"},
    {ImageID::fps_text, "image/fps_text.png"},
    {ImageID::game_frame, "image/game/frame.png"},
    {ImageID::game_pause_menu, "image/game/pause_menu.png"},
    {ImageID::title_items, "image/title/title_items.png"},
    {ImageID::title_selected_items, "image/title/title_selected_items.png"},
    {ImageID::title_background, "image/title/title_background.png"},
    {ImageID::title_logo, "image/title/title_logo.png"},
    {ImageID::option_items, "image/option/option_items.png"},
    {ImageID::option_selected_items, "image/option/option_selected_items.png"},
    {ImageID::option_fullscreen_mode, "image/option/option_fullscreen_mode.png"},
    {ImageID::option_selected_fullscreen_mode, "image/option/option_selected_fullscreen_mode.png"},
    {ImageID::keyconfig_items, "image/keyconfig/keyconfig_items.png"},
    {ImageID::keyconfig_selected_items, "image/keyconfig/keyconfig_selected_items.png"},
    {ImageID::musicroom_background, "image/musicroom/musicroom_background.png"},
};