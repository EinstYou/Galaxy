#ifndef PLAYER_H
#define PLAYER_H

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_hints.h>
#include <iostream>

#include "Input.h"
#include "Time.h"

class Player {
public:
    SDL_Texture* texture;
    SDL_FRect rect;
    SDL_FRect collision;

    float speed;
    float velocityX;
    float velocityY;
    Player(SDL_Renderer* renderer);
    void Render(SDL_Renderer* renderer);
    void Event(SDL_Event * event);
    void Update(float deltaTime);

};

#endif