#pragma once
#include <raylib.h>

class Obstacle {
    public:
        Obstacle();
        ~Obstacle();
        void Draw();
        void Update();
        Rectangle hitbox = {position.x, position.y, (float)image.width, (float)image.height};
    private:
        Texture2D image;
        const int def_pos_x = GetScreenWidth() + 100;
        const int def_pos_y = 300;
        Vector2 position;
        int speed = 10;
};