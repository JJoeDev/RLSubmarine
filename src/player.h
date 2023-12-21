#pragma once

#include <raylib.h>

class Player{
public:
    Player(Vector2 Pos, float Acceleration, float MaxSpeed, float Friction);
    ~Player();

    void PlayerUpdate(const float deltaT);
    void PlayerRender() const;

    inline Vector2 GetPlayerPos() const { return _pos; }
    inline Vector2& GetPlayerVelocity() { return _velocity; }
    inline float& GetPlayerAcceleration() { return _acceleration; }

private:
    Vector2 _pos;
    Vector2 _velocity{0, 0};
    float _acceleration;
    float _maxSpeed;
    float _friction;
};