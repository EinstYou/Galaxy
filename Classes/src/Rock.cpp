#include "Rock.h"





Rock::Rock(SDL_Renderer *renderer) {
    SDL_Surface *surface = IMG_Load("../Sprites/Asteroid 01 - Base.png");
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_SetTextureScaleMode(texture, SDL_SCALEMODE_NEAREST);
    SDL_DestroySurface(surface);

    canSpawn = true;
    currentTime = 0;
    spawnTime = 1;
    
    firstSpeed = 100;
}

void Rock::Render(SDL_Renderer *renderer) {
    for(auto i : asteroids){
        SDL_RenderTexture(renderer, texture, nullptr, &i.transform);
    }
}

void Rock::Update(float dt) {
    if(canSpawn){
        Asteroid rock;
        rock.transform = {(float)(SDL_rand(1024 - (96 * 2))), -200, 96 * 2, 96 * 2};
        rock.speed = firstSpeed + (Score::score * 10);
        asteroids.push_back(rock);
        canSpawn = false;
    }
    else {
        currentTime += dt * Time::timeScale;
        if(currentTime >= spawnTime / ((Score::score / 10) + 1)){
            canSpawn = true;
            currentTime = 0;
        }
    }
    
    for (int i = 0; i < asteroids.size(); i++){
        asteroids[i].transform.y += asteroids[i].speed * dt * Time::timeScale;
        asteroids[i].collision = {asteroids[i].transform.x + 58, asteroids[i].transform.y + 62, 75, 70};
        if(asteroids[i].transform.y > 700){
            asteroids.erase(asteroids.begin() + i);
        }
    }
}