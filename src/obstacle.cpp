#include "obstacle.hpp"

Obstacle::Obstacle()
{
    image = LoadTexture("graphics/1cactus.png");
    position.x = def_pos_x;
    position.y = def_pos_y;
}

Obstacle::~Obstacle() {
    UnloadTexture(image);
}

void Obstacle::Draw() {
    DrawTextureV(image, position, WHITE);
}

void Obstacle::Update() {
    if (position.x < -100) position.x = GetScreenWidth();
    position.x -= speed;
    hitbox = {position.x, position.y, (float)image.width, (float)image.height};
}