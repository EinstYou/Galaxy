#ifndef COLLISION2D_H
#define COLLISION2D_H

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>


class Collision2D {
public:
    static bool CheckCollision(SDL_FRect a, SDL_FRect b);
};




#endif //GAMEENGINE_COLLISION2D_H