#include "dino.hpp"

Dino::Dino() {
    runAnim.push_back(LoadTexture("graphics/dino_Left_Run.png"));
    runAnim.push_back(LoadTexture("graphics/dino_Right_Run.png"));
    runAnim.push_back(LoadTexture("graphics/dino_Left_Duck.png"));
    runAnim.push_back(LoadTexture("graphics/dino_Right_Duck.png"));
    position.x = def_pos_x;
    position.y = def_pos_y;
    hitbox = {position.x, position.y, (float) runAnim[0].width, (float) runAnim[0].height};
    velocity = 0;
    isGrounded = true;
    isCrouching = false;
    crouchStart = false;
}

Dino::~Dino() {
    for (auto& tex : runAnim) {
        UnloadTexture(tex);
    }
}

void Dino::Draw() {
    DrawTextureV(runAnim[currentFrame], position, WHITE);
}

void Dino::Update() {
    if ((IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) && isGrounded) {
            isCrouching = true;
            if (IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN))
                crouchStart = true;
        } else isCrouching = false;
    
    if ((IsKeyPressed(KEY_W) || IsKeyPressed(KEY_SPACE) ||
        IsKeyPressed(KEY_UP)) && isGrounded) {
        velocity = jumpForce;
        isGrounded = false;
    }

    velocity += gravity;
    position.y += velocity;

    if (position.y >= def_pos_y && !isCrouching) {
        position.y = def_pos_y;
        velocity = 0;
        isGrounded = true;
    }
    if (isCrouching) {
        position.y = def_pos_y + runAnim[0].height - runAnim[2].height;
    }

    frameTimer += GetFrameTime();
    if (frameTimer >= frameTime || crouchStart) {
        frameTimer = 0;
        currentFrame = (currentFrame + 1) % 2;
        crouchStart = false;
        if (isCrouching) {
            currentFrame += 2;
        }
    }

    hitbox = {position.x, position.y, (float) runAnim[currentFrame].width, (float) runAnim[currentFrame].height};
}