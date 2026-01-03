#include "Player.h"



Player::Player(SDL_Renderer* renderer) {
    SDL_Surface* surface = IMG_Load("../Sprites/Main Ship - Base - Full health.png");
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_SetTextureScaleMode(texture, SDL_SCALEMODE_NEAREST);
    SDL_DestroySurface(surface);
    rect = {(1024 / 2) - ((48 * 2) / 2), 500, 48 * 2, 48 * 2};

    velocityX = 0;
    velocityY = 0;

    speed = 500;
}

void Player::Render(SDL_Renderer *renderer) {
    SDL_RenderTexture(renderer, texture, nullptr, &rect);
}
void Player::Event(SDL_Event * event) {
    velocityX = Input::Get_Axis(SDL_SCANCODE_D, SDL_SCANCODE_A) * speed;
}
void Player::Update(float deltaTime) {

    float oldX = rect.x;
    float oldY = rect.y;
    rect.x += velocityX * deltaTime * Time::timeScale;
    rect.y += velocityY * deltaTime * Time::timeScale;
    collision = {rect.x + 15, rect.y + 20, 65,55};
    if (collision.x + collision.w > 1024 || collision .x < 0) {
        rect.x = oldX;
        rect.y = oldY;
    }
}
