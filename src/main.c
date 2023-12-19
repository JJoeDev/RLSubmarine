#include <raylib.h>

#include "player.h"

#define WIN_WIDTH 800 * 2
#define WIN_HEIGHT 450 * 2

int main(){
    InitWindow(WIN_WIDTH, WIN_HEIGHT, "Submarine game");
    SetTargetFPS(60);

    Player* plr = CreatePlayer((Vector2){800, 450}, 50, 45, 10);

    Camera2D cam;
    cam.target = plr->pos;
    cam.offset = (Vector2){800 , 450 };
    cam.zoom = 1.0f;

    while (!WindowShouldClose()) {
        float delta = GetFrameTime();

        PlayerMovement(plr, delta);

        //// RENDER ////

        BeginDrawing();
        ClearBackground(DARKGRAY);
        DrawFPS(10, 10);

        BeginMode2D(cam);

        RenderPlayer(plr);
        DrawCircle(260, 235, 5, RED);

        EndMode2D();

        EndDrawing();
    }

    DestroyPlayer(plr);

    CloseWindow();
    return 0;
}