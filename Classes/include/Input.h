#ifndef INPUT_H
#define INPUT_H

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <iostream>

#include "Input.h"

class Input {
public:
    static float Get_Axis(SDL_Scancode positive, SDL_Scancode negative);
    static bool Get_Button(SDL_Event* e, SDL_Scancode button);
};




#endif