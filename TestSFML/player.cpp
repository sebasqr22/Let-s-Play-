/**
  *@file player.cpp
  * @title Player
  * @brief Clase con los atributos de un jugador
*/
#include "player.h"
/**
 * @brief Player::Player Constructor de la clase
 */
Player::Player()
{

}
/**
 * @brief Player::Player Establece la posicion del jugador
 * @param x Posicion en el eje x
 * @param y Posicion en el eje y
 */
Player::Player(float x, float y)
{
    this->Pos_x = x;
    this->Pos_y = y;

}
/**
 * @brief Player::set_Position Establece la posicion del jugador
 * @param x Posicion en el eje x
 * @param y Posicion en el eje y
 */
void Player::set_Position(float x, float y){
    this->Pos_x = x;
    this->Pos_y = y;
}
/**
 * @brief Player::set_Team Establece el equipo del jugador
 * @param team Equipo del jugador
 */
void Player::set_Team(int team){
    this->team = team;
}
/**
 * @brief Player::get_PositionX Obtener posicion en el eje x
 * @return Posicion en el eje x
 */
float Player::get_PositionX(){
    return this->Pos_x;
}
/**
 * @brief Player::get_PositionY Obtener posicion en el eje y
 * @return Posicion en el eje y
 */
float Player::get_PositionY(){
    return this->Pos_y;
}
/**
 * @brief Player::get_Team Obtener el equipo del jugador
 * @return Equipo del jugador
 */
int Player::get_Team(){
    return this->team;
}
