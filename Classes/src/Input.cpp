#include "Input.h"

float Input::Get_Axis(SDL_Scancode positive, SDL_Scancode negative) {
    const bool *key_states = SDL_GetKeyboardState(nullptr);
    float direction = 0;
    if (key_states[positive]) {
        direction += 1;
    }
    if (key_states[negative]) {
        direction += -1;
    }
    return direction;
}


bool Input::Get_Button(SDL_Event* e, SDL_Scancode button) {

    if (e->type == SDL_EVENT_KEY_DOWN && e->key.scancode == button) return true;
    return false;
}