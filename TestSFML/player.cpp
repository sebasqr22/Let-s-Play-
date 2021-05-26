#include "player.h"

Player::Player()
{

}
Player::Player(float x, float y)
{
    this->Pos_x = x;
    this->Pos_y = y;

}

void Player::set_Position(float x, float y){
    this->Pos_x = x;
    this->Pos_y = y;
}

float Player::get_PositionX(){
    return this->Pos_x;
}

float Player::get_PositionY(){
    return this->Pos_y;
}
