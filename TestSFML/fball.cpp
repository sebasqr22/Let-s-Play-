/**
  *@file fball.cpp
  * @title FBall
  * @brief Clase que contiene las funcionalidades de la pelota
*/

#include "fball.h"
/**
 * @brief FBall::FBall Constructor de la clase
 */
FBall::FBall()
{

}
/**
 * @brief FBall::set_Position Metodo para establecer la posicion
 * @param x Posicion en el eje x
 * @param y Posicion en el eje y
 */
void FBall::set_Position(float x, float y){
    this->Pos_x = x;
    this->Pos_y = y;
}
/**
 * @brief FBall::get_PositionX Retorna la posicion en eje x
 * @return Posicion en eje x
 */
float FBall::get_PositionX(){
    return this->Pos_x;
}
/**
 * @brief FBall::get_PositionY Obtener posicion en eje y
 * @return Posicion en el eje y
 */
float FBall::get_PositionY(){
    return this->Pos_y;
}
/**
 * @brief FBall::moveI Establece el movimiento de tipo 1 de una bola
 */
void FBall::moveI(){
    this->Pos_x+=0.5f;
    this->Pos_y-=0.5f;
}
/**
 * @brief FBall::moveII Establece el movimiento de tipo 2 de una bola
 */
void FBall::moveII(){
    this->Pos_x-=0.5f;
    this->Pos_y-=0.5f;
}
/**
 * @brief FBall::moveIII Establece el movimiento de tipo 3 de una bola
 */
void FBall::moveIII(){
    this->Pos_x-=0.5f;
    this->Pos_y+=0.5f;
}
/**
 * @brief FBall::moveIV Establece el movimiento de tipo 4 de una bola
 */
void FBall::moveIV(){
    this->Pos_x+=0.5f;
    this->Pos_y+=0.5f;
}
/**
 * @brief FBall::moveHV Establece el movimiento de tipo 5 de una bola
 * @param angle Angulo de movimiento
 */
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
/**
 * @brief FBall::moveFast Establece el movimiento de tipo rapido de una bola
 * @param component Componente a mover
 * @param quad Posicion en matriz
 */
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
