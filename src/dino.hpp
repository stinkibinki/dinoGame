#pragma once
#include <raylib.h>

class Dino {
    public:
        Dino();
        ~Dino();
        void Draw();
        void Update();
        Rectangle hitbox = {position.x, position.y, image.width, image.height};
    private:
        Texture2D image;
        const int def_pos_x = 100;
        const int def_pos_y = 300;
        Vector2 position;
        float velocity;
        const float gravity = 0.8;
        const float jumpForce = -20;
        bool isGrounded;
};