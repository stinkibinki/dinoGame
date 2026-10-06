#include "dino.hpp"

Dino::Dino()
{
    image = LoadTexture("graphics/dino_Left_Run.png");
    position.x = def_pos_x;
    position.y = def_pos_y;
    velocity = 0;
    isGrounded = true;
}

Dino::~Dino() {
    UnloadTexture(image);
}

void Dino::Draw() {
    DrawTextureV(image, position, WHITE);
}

void Dino::Update() {
    if ((IsKeyPressed(KEY_W) || IsKeyPressed(KEY_SPACE) ||
        IsKeyPressed(KEY_UP)) && isGrounded) {
        velocity = jumpForce;
        isGrounded = false;
    }

    velocity += gravity;
    position.y += velocity;

    if (position.y >= def_pos_y) {
        position.y = def_pos_y;
        velocity = 0;
        isGrounded = true;
    }

    hitbox = {position.x, position.y, (float)image.width, (float)image.height};

    if (IsKeyDown(KEY_S)) {}
}