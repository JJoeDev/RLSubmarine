#include <raylib.h>
#include <raymath.h>
#include <stdio.h>
#include <stdlib.h>

#include "player.h"

Player* CreatePlayer(Vector2 Position, float MaxVelocity, float Acceleration, float Friction){
    Player* player = (Player*)malloc(sizeof(Player));
    if(player != NULL){
        player->pos = Position;
        player->velocity = (Vector2){0.0f, 0.0f};
        player->maxVelocity = MaxVelocity;
        player->acceleration = Acceleration;
        player->friction = Friction;
    }

    return player;
}

void DestroyPlayer(Player *player){
    free(player);
}

void PlayerMovement(Player *player, float delta){
    float xDir = IsKeyDown(KEY_D) - IsKeyDown(KEY_A);
    float yDir = IsKeyDown(KEY_S) - IsKeyDown(KEY_W);

    player->velocity.x += player->acceleration * xDir * delta;
    player->velocity.y += player->acceleration * yDir * delta;

    player->velocity.x = Clamp(player->velocity.x, -player->maxVelocity, player->maxVelocity);
    player->velocity.y = Clamp(player->velocity.y, -player->maxVelocity, player->maxVelocity);

    player->pos.x += player->velocity.x * delta;
    player->pos.y += player->velocity.y * delta;

    if (player->velocity.x > 0.3f) player->velocity.x -= player->friction * delta;
    else if(player->velocity.x < -0.3f) player->velocity.x += player->friction * delta;

    if (player->velocity.y > 0.3f) player->velocity.y -= player->friction * delta;
    else if(player->velocity.y < -0.3f) player->velocity.y += player->friction * delta;
}

void RenderPlayer(const Player *player){
    DrawCircle(player->pos.x, player->pos.y, 5, GREEN);
}