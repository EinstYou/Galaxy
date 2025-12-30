#include "Collision2D.h"


bool Collision2D::CheckCollision(SDL_FRect a, SDL_FRect b) {
    float aLeft = a.x;
    float aRight = a.x + a.w;
    float aTop = a.y;
    float aBottom = a.y + a.h;

    float bLeft = b.x;
    float bRight = b.x + b.w;
    float bTop = b.y;
    float bBottom = b.y + b.h;

    if (aLeft <= bRight && aRight >= bLeft && aTop <= bBottom && aBottom >= bTop) return true;
    return false;
}
