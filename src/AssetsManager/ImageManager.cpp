#include <string>
#if defined(__ANDROID__) && !defined(__TERMUX__)
#include <SDL.h>
#include <SDL_image.h>
#else
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#endif

#include "ImageManager.hpp"

ImageManager::ImageManager(SDL_Renderer* renderer_handle, std::string base_path) {
    //FilePathListに格納されたテクスチャファイルを読み込む(PNG)
    for(const auto& it : FilePathList) {
        SDL_Surface* sur = IMG_Load((base_path + it.second).c_str());
        SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer_handle , sur);
        if(sur == nullptr || tex == nullptr)
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_WARNING, "Touhou-Koumatou", (std::string("Failed to open texture file\n") + it.second).c_str(), nullptr);
        SDL_FreeSurface(sur);
        this->texture_map[it.first] = tex;
    }
}

ImageManager::~ImageManager() {
    //読み込まれたテクスチャを全解放する
    for(const auto& it : this->texture_map) {
        SDL_DestroyTexture(it.second);
    }
}

//引数に渡されたRectやalpha値や角度をもとにSDL_Rendererに描画する
void ImageManager::Render(SDL_Renderer* renderer_handle, ImageID image_id, const SDL_Rect* srcrect, const SDL_Rect* dstrect, uint8_t alpha, double angle, SDL_RendererFlip flip) {
    SDL_Texture* tmp = this->texture_map[image_id];
    SDL_SetTextureAlphaMod(tmp, alpha);
    SDL_RenderCopyEx(renderer_handle, tmp, srcrect, dstrect , angle, nullptr, flip);
}
