#include "TouchRect.hpp"

std::unordered_map<Buttons, const SDL_Rect> TouchRectList = {
    {Buttons::Shot, {760, 580, 100, 100}},
    {Buttons::Bomb, {860, 580, 100, 100}},
    {Buttons::Pause, {860, 0, 100, 100}},
    {Buttons::Slow, {860, 480, 100, 100}},
    {Buttons::Skip, {760, 480, 100, 100}}
};
