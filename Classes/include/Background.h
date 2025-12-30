#ifndef BACKGROUND_H
#define BACKGROUND_H
#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>




class Background {
public:
    SDL_Texture* texture;
    SDL_FRect rect;


    Background(SDL_Renderer* renderer);
    void Render(SDL_Renderer* renderer);

};





#endif