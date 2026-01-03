#ifndef FIRE_H
#define FIRE_H

#include <iostream>
#include <vector>
#include <SDL3/SDL.h>

#include "Time.h"
class Fire {
  public:
  std::vector<SDL_FRect> bullets;
  float speedY;
  float cooldown;
  bool canFire;
  Fire();
  void FireBullet(SDL_Event* e, float posX, float posY);
  void Update(float deltaTime);
  void Render(SDL_Renderer* renderer);
};

#endif