#ifndef STRENGTH_H
#define STRENGTH_H
#include <iostream>
using namespace std;
/**
 * @brief The Strength class Clase de la potencia de lanzamiento
 */
class Strength
{
private:
    /**
     * @brief value valor de la Potencia
     */
    int value;
    /**
     * @brief img Imagen que demuestra la potencia
     */
    string img;

public:
    /**
     * @brief Strength Constructor
     */
    Strength();
    /**
     * @brief set_Value Asignar valor a la potencia
     * @param value Valor
     */
    void set_Value(int value);
    /**
     * @brief updateImg Actualizar sprite segun valor
     * @param value Valor
     */
    void updateImg(int value);
    /**
     * @brief set_Img Asignar una imagen a la barra de potencia
     * @param msg
     */
    void set_Img(string msg);
    //int set_Value(int value);
    //void updateImg(int value);
    //void set_Img(string msg);
};

#endif // STRENGTH_H
