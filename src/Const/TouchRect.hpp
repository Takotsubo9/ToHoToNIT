#ifndef _TOUCH_RECT_H_
#define _TOUCH_RECT_H_

#include "Buttons.hpp"

#ifdef __ANDROID__
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

#include "Buttons.hpp"
#include <unordered_map>

extern std::unordered_map<Buttons, const SDL_Rect> TouchRectList;

#endif