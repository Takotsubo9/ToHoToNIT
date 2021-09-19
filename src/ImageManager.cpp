#include "ImageManager.hpp"
#include <SDL2/SDL_image.h>

ImageManager::ImageManager(SDL_Renderer* renderer_handle, std::string base_path) {
    for(std::map<ImageID, std::string>::const_iterator it = FilePathList.begin(); it != FilePathList.end(); ++it) {
        SDL_Surface* sur = IMG_Load((base_path + it->second).c_str());
        SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer_handle ,sur);
        SDL_FreeSurface(sur);
        this->texture_map[it->first] = tex;
    }
}

ImageManager::~ImageManager() {
    for(std::map<ImageID, SDL_Texture*>::iterator it = this->texture_map.begin(); it != this->texture_map.end(); ++it) {
        SDL_DestroyTexture(it->second);
    }
}

void ImageManager::Render(SDL_Renderer* renderer_handle, ImageID image_id, const SDL_Rect* srcrect, const SDL_Rect* dstrect, uint8_t alpha, double angle) {
    SDL_Texture* tmp = this->texture_map[image_id];
    SDL_SetTextureAlphaMod(tmp, alpha);
    SDL_RenderCopyEx(renderer_handle, tmp, srcrect, dstrect , angle, NULL, SDL_FLIP_NONE);
}