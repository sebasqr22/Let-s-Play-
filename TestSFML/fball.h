#ifndef FBALL_H
#define FBALL_H

/**
 * @brief The FBall class encargada del movimiento del balon
 */
class FBall
{
private:
    /**
     * @brief Pos_x Posicion x de la bola
     */
    float Pos_x;
    /**
     * @brief Pos_y Posicion y de la bola
     */
    float Pos_y;
public:
    /**
     * @brief FBall Constructor
     */
    FBall();
    /**
     * @brief set_Position asignar posicion al balon
     * @param x Posicion x de la bola
     * @param y Posicion y de la bola
     */
    void set_Position(float x, float y);
    /**
     * @brief get_PositionX Obtener posicion x de la bola
     * @return Posicion x de la bola
     */
    float get_PositionX();
    /**
     * @brief get_PositionY Obtener posicion y de la bola
     * @return Posicion y de la bola
     */
    float get_PositionY();
    /**
     * @brief moveI Mover primer cuadrante
     */
    void moveI();
    /**
     * @brief moveII Mover segundo cuadrante
     */
    void moveII();
    /**
     * @brief moveIII Mover tercer cuadrante
     */
    void moveIII();
    /**
     * @brief moveIV Mover cuarto cuadrante
     */
    void moveIV();
    /**
     * @brief moveHV Mover por angulo cuadrantal
     * @param angle angulo cuadrantal
     */
    void moveHV(int angle);
    /**
     * @brief moveFast Moverse mas rapido en alguna direccion
     * @param component Componente x o y
     * @param quad Cuadrante
     */
    void moveFast(int component, int quad);
};

#endif // FBALL_H
