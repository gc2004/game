#include <raylib.h>

#include <string>

int main() {
    SetConfigFlags(FLAG_VSYNC_HINT);
    InitWindow(640, 480, "Game");

    float deltaTime = 0.0;

    Rectangle player = {0.0, 0.0, 50.0, 50.0};
    bool up, down, left, right;

    const float SPEED = 500.0;

    while (!WindowShouldClose()) {
        deltaTime = GetFrameTime();

        {
            up = IsKeyDown(KEY_UP);
            down = IsKeyDown(KEY_DOWN);
            left = IsKeyDown(KEY_LEFT);
            right = IsKeyDown(KEY_RIGHT);

            if (up) player.y += -SPEED * deltaTime;
            if (down) player.y += SPEED * deltaTime;
            if (left) player.x += -SPEED * deltaTime;
            if (right) player.x += SPEED * deltaTime;
        }

        ClearBackground(BLACK);

        BeginDrawing();
        {
            // render
            DrawRectanglePro(player, (Vector2){0.0, 0.0}, 0.0F, RED);

            DrawFPS(10, 10);
        }
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
