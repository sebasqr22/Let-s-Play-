#ifndef IMAGEN_H
#define IMAGEN_H
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "imagen.h"
using namespace sf;
using namespace std;
/**
 * @brief The Imagen class Clase de control de imagenes para el algoritmo genetico
 */
class Imagen
{
public:
    Imagen();
    Texture pTexture;
    Sprite imagen;
    String nameI;
    void CargarImagen();
    String DivisionImagen4x4();
    Sprite DibujarImagen();
    void ObtenerImagen(String Nimagen);
private:


};

#endif // IMAGEN_H
