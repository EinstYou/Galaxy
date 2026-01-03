#ifndef HEALTH_H
#define HEALTH_H
#include "SDL3/SDL_render.h"
#include "SDL3_image/SDL_image.h"

#include "Health.h"

class Health {
  public:
  int health;
  SDL_Texture* texture;
  SDL_FRect rect;
  Health(SDL_Renderer *renderer);
  void Update();
  void RenderHealth(SDL_Renderer* renderer);

};




#endif
