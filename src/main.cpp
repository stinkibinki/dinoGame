#include <iostream>
#include <raylib.h>
#include "dino.hpp"
#include "obstacle.hpp"

int main() 
{
    constexpr int screenWidth = 1200;
    constexpr int screenHeight = 800;

    bool gameover = false;
        
    InitWindow(screenWidth, screenHeight, "dino");
    SetTargetFPS(60);

    Dino dino;
    Obstacle cactus;
    
    while (!WindowShouldClose())
    {
        if (!gameover) {
        dino.Update();
        cactus.Update();
        }
        if (!gameover && CheckCollisionRecs(dino.hitbox, cactus.hitbox)) {
            std::cout << "game over\n";
            gameover = true;
        }
                  
        BeginDrawing();
            ClearBackground(WHITE);
            dino.Draw();
            cactus.Draw();
        EndDrawing();
        
    }
    
    CloseWindow();
}