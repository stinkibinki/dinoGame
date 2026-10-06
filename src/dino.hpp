#pragma once
#include <raylib.h>
#include <vector>

class Dino {
    public:
        Dino();
        ~Dino();
        void Draw();
        void Update();
        Rectangle hitbox;
    private:
        std::vector<Texture2D> runAnim;
        int currentFrame = 0;
        float frameTimer = 0;
        float frameTime = 0.1;

        const int def_pos_x = 100;
        const int def_pos_y = 300;
        Vector2 position;

        float velocity;
        const float gravity = 0.8;
        const float jumpForce = -20;
        bool isGrounded;
        bool isCrouching;
        bool crouchStart;
};