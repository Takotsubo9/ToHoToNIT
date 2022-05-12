#ifndef _TOUCH_RECT_H_
#define _TOUCH_RECT_H_

#include "Buttons.hpp"

#if defined(__ANDROID__) && !defined(__TERMUX__)
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

#include "Buttons.hpp"
#include <unordered_map>

extern std::unordered_map<Buttons, const SDL_Rect> TouchRectList;

#endif