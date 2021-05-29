#ifndef PLAYER_H
#define PLAYER_H

/**
 * @brief The Player class Clase que controla el posicionamiento de los jugadores de cada equipo
 */
class Player
{
private:
    /**
     * @brief Pos_x Posicion x del jugador
     */
    float Pos_x;
    /**
     * @brief Pos_y Posicion y del jugador
     */
    float Pos_y;
    /**
     * @brief team Equipo de cada jugador
     */
    int team;
public:
    /**
     * @brief Player Constructor
     */
    Player();
    /**
     * @brief Player Constructor 2
     * @param x Posicion x del jugador
     * @param y Posicion y del jugador
     */
    Player(float x, float y);
    /**
     * @brief set_Position Asignar posicion a jugador
     * @param x Posicion x del jugador
     * @param y Posicion y del jugador
     */
    void set_Position(float x, float y);
    /**
     * @brief set_Team Aignar equipo a un jugador
     * @param team Equipo
     */
    void set_Team(int team);
    /**
     * @brief get_PositionX Obtener posicion x del jugador
     * @return Posicion x del jugador
     */
    float get_PositionX();
    /**
     * @brief get_PositionY Obtener posicion y del jugador
     * @return Posicion y del jugador
     */
    float get_PositionY();
    /**
     * @brief get_Team Obtener equipo de un jugador
     * @return Equipo
     */
    int get_Team();
};

#endif // PLAYER_H
