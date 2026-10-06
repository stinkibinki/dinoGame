#include "obstacle.hpp"

Obstacle::Obstacle()
{
    image = LoadTexture("graphics/1cactus.png");
    position.x = def_pos_x;
    position.y = def_pos_y;
    hitbox = {position.x, position.y, (float)image.width, (float)image.height};
}

Obstacle::~Obstacle() {
    UnloadTexture(image);
}

void Obstacle::Draw() {
    DrawTextureV(image, position, WHITE);
}

void Obstacle::Update(bool gameover) {
    if (position.x < -100 || gameover) position.x = GetScreenWidth() + 100;
    position.x -= speed;
    hitbox = {position.x, position.y, (float)image.width, (float)image.height};
}