#ifndef SCORE_H
#define SCORE_H

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <iostream>

class Score{
    public:
    static int score;
    char scoreText[4];
    SDL_FRect rect;
    SDL_Color color;
    TTF_Font* font;
    Score();
    void Render(SDL_Renderer* renderer);

};









#endif