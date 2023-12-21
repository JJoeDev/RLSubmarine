#include <raylib.h>
#include <memory>

#include "ShaderManager.h"
#include "player.h"
#include "defines.h"

constexpr unsigned short winWidth = 800;
constexpr unsigned short winHeight = 450;

int main(){
    const Vector2 winSize{winWidth, winHeight};
    float time = 0;

    InitWindow(winWidth, winHeight, "Submarine game");

    SetTargetFPS(144);
    
    std::unique_ptr<fragMgr::waterShader> water = std::make_unique<fragMgr::waterShader>("src/shaders/water.fs");
    std::unique_ptr<Player> player = std::make_unique<Player>((Vector2){400.0f, 225.0f}, 45.0f, 60.0f, 10.0f);

    Camera2D cam;
    cam.target = player->GetPlayerPos();
    cam.offset = {400, 225};
    cam.rotation = 0.0f;
    cam.zoom = 1.0f;

    while (!WindowShouldClose()) {
        float delta = GetFrameTime();
        player->PlayerUpdate(delta);

        time += delta;
        
        BeginDrawing(); // STATIC RENDER
        ClearBackground(BLACK);
        DrawFPS(10, 10);

        water->RenderShader(delta);

        BeginMode2D(cam); // BEGIN WORLD RENDER

        DrawRectangle(50.0f, 98.0f, 10.0f, 62.0f, RED);

        player->PlayerRender();
        cam.target = player->GetPlayerPos();

        EndMode2D();
        EndDrawing();
    }

    water->ManualUnloadShader();

    CloseWindow();
}