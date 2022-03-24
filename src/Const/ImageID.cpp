#include "ImageID.hpp"


const std::unordered_map<ImageID, std::string> FilePathList = {
    {ImageID::number, "image/number.png"},
    {ImageID::number_selected, "image/number_selected.png"},
    {ImageID::fps_text, "image/fps_text.png"},
    {ImageID::game_frame, "image/game/frame.png"},
    {ImageID::game_pause_menu, "image/game/pause_menu.png"},
    {ImageID::game_power_gauge, "image/game/power_gauge.png"},
    {ImageID::game_power_max_text, "image/game/power_max_text.png"},
    {ImageID::game_status, "image/game/status.png"},
    {ImageID::game_chara_marisa, "image/game/chara/marisa.png"},
    {ImageID::game_chara_reimu, "image/game/chara/reimu.png"},
    {ImageID::game_chara_satsuki, "image/game/chara/satsuki.png"},
    {ImageID::game_chara_test, "image/game/chara/test.png"},
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