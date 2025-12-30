#include "Fire.h"

#include "Input.h"

Fire::Fire() {
    canFire = true;
    cooldown = 0;
    speedY = 800;
}


void Fire::FireBullet(SDL_Event* e, float posX, float posY) {
    if (Input::Get_Button(e, SDL_SCANCODE_J) && canFire) {
        SDL_FRect bullet = {posX, posY, 6, 25};
        bullets.push_back(bullet);
        canFire = false;
    }
}

void Fire::Render(SDL_Renderer *renderer) {
    for (auto b : bullets) {
        SDL_SetRenderDrawColor(renderer, 255, 50, 50, 255);
        SDL_RenderFillRect(renderer, &b);
    }
}


void Fire::Update(float deltaTime) {
    if (!canFire) {
        cooldown += deltaTime;
        if (cooldown >= 0.1) {
            canFire = true;
            cooldown = 0;
        }
    }
    for (int i = 0; i < bullets.size(); i++) {
        bullets[i].y -= speedY * deltaTime;
        if (bullets[i].y < -50) {
            bullets.erase(bullets.begin() + i);
        }
    }
}
