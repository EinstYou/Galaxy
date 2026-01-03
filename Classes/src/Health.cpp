#include "Health.h"

#include "Time.h"

Health::Health(SDL_Renderer *renderer) {
  health = 3;
  SDL_Surface* surface = IMG_Load("../Sprites/Hearth.png");
  texture = SDL_CreateTextureFromSurface(renderer, surface);
  SDL_SetTextureScaleMode(texture, SDL_SCALEMODE_NEAREST);
  SDL_DestroySurface(surface);
  rect = {0, 0, 16 * 2, 16 * 2};
}

void Health::RenderHealth(SDL_Renderer *renderer) {
  for (int i = 0; i < health; i++) {
    rect = {i * rect.w, 0, rect.w, rect.h};
    SDL_RenderTexture(renderer, texture, nullptr, &rect);
  }
}

void Health::Update() {
  if (health <= 0) {
    Time::timeScale = 0.0f;
    health = 0;
  }
}



