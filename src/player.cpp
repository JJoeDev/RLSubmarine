#include "player.h"

#include <iostream>
#include <raymath.h>
#include <raylib.h>

Player::Player(Vector2 Pos, float Acceleration, float MaxSpeed, float Friction){
    _pos = Pos;
    _acceleration = Acceleration;
    _maxSpeed = MaxSpeed;
    _friction = Friction;
}

Player::~Player(){
    
}

void Player::PlayerUpdate(const float deltaT){
    float xDir = IsKeyDown(KEY_D) - IsKeyDown(KEY_A);
    float yDir = IsKeyDown(KEY_S) - IsKeyDown(KEY_W);

    _velocity.x += xDir * _acceleration * deltaT;
    _velocity.y += yDir * _acceleration * deltaT;

    _velocity.x = Clamp(_velocity.x, -_maxSpeed, _maxSpeed);
    _velocity.y = Clamp(_velocity.y, -_maxSpeed, _maxSpeed);

    _pos.x += _velocity.x * deltaT;
    _pos.y += _velocity.y * deltaT;

    if(_velocity.x > 0.3f) _velocity.x -= _friction * deltaT;
    else if(_velocity.x < -0.3f) _velocity.x += _friction * deltaT;

    if(_velocity.y > 0.3f) _velocity.y -= _friction * deltaT;
    else if(_velocity.y < -0.3f) _velocity.y += _friction * deltaT;
}

void Player::PlayerRender() const {
    DrawCircle(_pos.x, _pos.y, 10, GREEN);
    DrawLine(_pos.x, _pos.y, _pos.x + _velocity.x, _pos.y + _velocity.y, YELLOW);
}