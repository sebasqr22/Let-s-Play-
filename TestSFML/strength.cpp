#include "strength.h"
#include <iostream>
using namespace std;
Strength::Strength()
{

}

void Strength::set_Value(int value){
    this->value = value;
}
void Strength::set_Img(string img){
    this->img = img;
}
void Strength::set_Pxls(int units){
    this->pxls = units;
}
void Strength::updateImg(int value){
    if (value == 1){
        this->value = 1;
        this->img = "Imags/fuerza3.png";
    } else if (value == 2){
        this->value = 2;
        this->img = "Imags/fuerza2.png";
    } else if (value == 3){
        this->value = 3;
        this->img = "Imags/fuerza.png";
    }
}
string Strength::get_Img(){
    return this->img;
}
int Strength::get_Value(){
    return this->value;
}
int Strength::get_Pxls(){
    return this->pxls;
}
