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
    int pxls;

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
    void set_Img(string img);
    void set_Pxls(int units);
    int get_Value();
    //void updateImg(int value);
    string get_Img();
    int get_Pxls();
};

#endif // STRENGTH_H
