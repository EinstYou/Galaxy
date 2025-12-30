#include "Background.h"


Background::Background(SDL_Renderer* renderer) {
    SDL_Surface* surface = IMG_Load("../Sprites/Blue_Nebula_08-1024x1024.png");
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_DestroySurface(surface);
    rect = {0, 0, 1024, 1024};
}

void Background::Render(SDL_Renderer* renderer) {
    SDL_RenderTexture(renderer, texture, nullptr, &rect);
}
