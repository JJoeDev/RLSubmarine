#ifndef PLAYER_H
#define PLAYER_H

#include <raylib.h>
#include <raymath.h>

typedef struct Player{
    Vector2 pos;
    Vector2 velocity;
    float maxVelocity;
    float acceleration;
    float friction;
} Player;

Player* CreatePlayer(Vector2 Position, float MaxVelocity, float Acceleration, float Friction);
void DestroyPlayer(Player* player);

void PlayerMovement(Player* player, float delta);
void RenderPlayer(const Player* player);

#endif