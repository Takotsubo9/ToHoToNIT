#ifndef _IMAGE_MANAGER_H_
#define _IMAGE_MANAGER_H_

#include <unordered_map>
#if defined(__ANDROID__) && !defined(__TERMUX__)
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

#include "../Const/ImageID.hpp"

//画像を管理するクラス
class ImageManager {
private:
    std::unordered_map<ImageID, SDL_Texture*> texture_map;
public:
    ImageManager(SDL_Renderer* renderer_handle, std::string base_path);
    virtual ~ImageManager();
    void Render(SDL_Renderer* renderer_handle, ImageID image_id, const SDL_Rect* srcrect, const SDL_Rect* dstrect);
    void Render(SDL_Renderer* renderer_handle, ImageID image_id, const SDL_Rect* srcrect, const SDL_Rect* dstrect, uint8_t alpha, double angle, SDL_RendererFlip flip);
};

#endif /* _IMAGE_MANAGER_H_ */