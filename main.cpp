#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_ttf/SDL_ttf.h>

#include "Background.h"
#include "Collision2D.h"
#include "Fire.h"
#include "Health.h"
#include "Player.h"
#include "Rock.h"
#include "Score.h"

int main(int argc, char* argv[]) {

    if (!SDL_Init(SDL_INIT_VIDEO)) {
        std::cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    int width = 1024;
    int height = 576;
    SDL_Window* window = SDL_CreateWindow("Hello", width, height, 0);
    if (!window) {
        std::cout << "Could not create window! SDL Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, nullptr);
    if (!renderer) {
        std::cout << "Could not create renderer! SDL Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    if(!TTF_Init()){
        std::cout << "TTF could not initialize! SDL Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    TTF_TextEngine* textEngine = TTF_CreateRendererTextEngine(renderer);
    if(textEngine == nullptr){
        std::cout << "Could not create TextEngine! SDL Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    Uint64 lastFrame = SDL_GetPerformanceCounter();
    double deltaTime = 0;
    Uint64 currentFrame = lastFrame;


    Background background(renderer);
    Player player(renderer);
    Fire fire;
    Rock rock(renderer);
    Score score;
    Health health(renderer);


    bool running = true;
    SDL_Event e;
    while (running) {
        lastFrame = SDL_GetPerformanceCounter();
        deltaTime = ((double)lastFrame - (double)currentFrame) / (double)SDL_GetPerformanceFrequency();
        currentFrame = lastFrame;

        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) running = false;
            player.Event(&e);
            fire.FireBullet(&e, player.rect.x + (player.rect.w / 2) - 3, player.rect.y);
        }


        player.Update(deltaTime);
        fire.Update(deltaTime);
        rock.Update(deltaTime);
        health.Update();


        for(int x = rock.asteroids.size() - 1; x >= 0; x--) {
            if (Collision2D::CheckCollision(rock.asteroids[x].collision, player.collision)) {
                health.health--;
                rock.asteroids.erase(rock.asteroids.begin() + x);
                break;
            }
            for(int y = fire.bullets.size() - 1; y >= 0; y--) {
                if (Collision2D::CheckCollision(rock.asteroids[x].collision, fire.bullets[y])) {
                    rock.asteroids.erase(rock.asteroids.begin() + x);
                    fire.bullets.erase(fire.bullets.begin() + y);
                    score.score++;
                    break;
                }
            }
        }


        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        background.Render(renderer);

        fire.Render(renderer);

        player.Render(renderer);

        rock.Render(renderer);

        score.Render(renderer);

        health.RenderHealth(renderer);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}