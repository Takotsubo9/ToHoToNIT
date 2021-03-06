#ifndef _IMAGE_MANAGER_H_
#define _IMAGE_MANAGER_H_

#include <SDL2/SDL.h>
#include <map>
#include "Const/ImageID.hpp"

//画像を管理するクラス
class ImageManager {
private:
    SDL_Texture* LoadTexture(std::string FilePath);
    std::map<ImageID, SDL_Texture*> texture_map;
public:
    ImageManager(SDL_Renderer* renderer_handle);
    virtual ~ImageManager();
    void Render(SDL_Renderer* renderer_handle, ImageID id, const SDL_Rect* srcrect, const SDL_Rect* dstrect);
    void Render(SDL_Renderer* renderer_handle, ImageID image_id, const SDL_Rect* srcrect, const SDL_Rect* dstrect, uint8_t alpha);
};

#endif /* _IMAGE_MANAGER_H_ */