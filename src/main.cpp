#include <iostream>
#include <raylib.h>
#include "dino.hpp"
#include "obstacle.hpp"

int main() 
{
    constexpr int screenWidth = 1200;
    constexpr int screenHeight = 800;

    bool gameover = true;
        
    InitWindow(screenWidth, screenHeight, "dino");
    SetTargetFPS(60);

    Dino dino;
    Obstacle cactus;
    
    while (!WindowShouldClose())
    {
        if (gameover) {
            const char *play = "press space to play";
            int fontSize = 30;
            DrawText(play, screenWidth/2 - MeasureText(play, fontSize)/2, 100, fontSize, WHITE);
            if (IsKeyPressed(KEY_SPACE)) {
                cactus.Update(gameover);
                gameover = false;
            }
        }
        if (!gameover) {
            dino.Update();
            cactus.Update(gameover);
        }
        if (!gameover && CheckCollisionRecs(dino.hitbox, cactus.hitbox)) {
            std::cout << "game over\n";
            gameover = true;
        }
                  
        BeginDrawing();
            ClearBackground(BLACK);
            dino.Draw();
            cactus.Draw();
        EndDrawing();
        
    }
    
    CloseWindow();
}