#include "fball.h"

FBall::FBall()
{

}
void FBall::set_Position(float x, float y){
    this->Pos_x = x;
    this->Pos_y = y;
}

float FBall::get_PositionX(){
    return this->Pos_x;
}

float FBall::get_PositionY(){
    return this->Pos_y;
}

void FBall::moveI(){
    this->Pos_x+=0.5f;
    this->Pos_y-=0.5f;
}

void FBall::moveII(){
    this->Pos_x-=0.5f;
    this->Pos_y-=0.5f;
}

void FBall::moveIII(){
    this->Pos_x-=0.5f;
    this->Pos_y+=0.5f;
}

void FBall::moveIV(){
    this->Pos_x+=0.5f;
    this->Pos_y+=0.5f;
}

void FBall::moveHV(int angle){
    if (angle == 360){
        this->Pos_y+=1.f;
    } else if (angle == 90) {
        this->Pos_x-=1.f;
    } else if (angle == 180) {
        this->Pos_y-=1.f;
    } else if (angle == 270) {
        this->Pos_x+=1.f;
    }
}

void FBall::moveFast(int component, int quad){

    if (component == 1){
        if (quad == 1 || quad == 4){
            this->Pos_x+=1.f;
        } else if (quad == 2 && quad == 3){
            this->Pos_x-=1.f;
        }

    } else if (component == 2) {
        if (quad == 1 || quad == 2){
            this->Pos_y-=1.f;
        } else if (quad == 3 && quad == 4){
            this->Pos_y+=1.f;
        }
    }
}
