#ifndef ROCK_H
#define ROCK_H

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>
#include <iostream>
#include <vector>

#include "Collision2D.h"
#include "Score.h"

class Rock {
public:
    struct Asteroid {
        SDL_FRect transform;
        SDL_FRect collision;
        float speed;
    };
    std::vector <Asteroid> asteroids;
    float firstSpeed;

    bool canSpawn;
    float spawnTime;
    float currentTime;


    SDL_Texture* texture;

    Rock(SDL_Renderer* renderer);
    void Render(SDL_Renderer* renderer);
    void Update(float dt);
};


#endif