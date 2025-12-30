#include "Score.h"


Score::Score(){
    score = 0;
    rect = {1024 / 2 - 50, 0, 100, 100};
    font = TTF_OpenFont("../Fonts/BBHHegarty-Regular.ttf", 24);
    if(font == nullptr) std::cout << "font is null: " << SDL_GetError() << std::endl;
    color = {255, 255, 255, 255};
}




void Score::Render(SDL_Renderer* renderer){
    sprintf(scoreText, "%d", this->score);
    SDL_Surface* surface = TTF_RenderText_Solid(font, scoreText, 0, color);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_SetTextureScaleMode(texture, SDL_SCALEMODE_NEAREST);
    SDL_DestroySurface(surface);
    SDL_RenderTexture(renderer, texture, nullptr, &rect);
    SDL_DestroyTexture(texture);
}