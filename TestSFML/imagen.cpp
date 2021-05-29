/**
  *@file imagen.cpp
  * @title Imagen
  * @brief Clase para el manejo de la imagen del segundo juego
*/
#include "imagen.h"
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "imagen.h"
using namespace sf;
using namespace std;
/**
 * @brief Imagen::Imagen Constrcutor de la clase imagen
 */
Imagen::Imagen()
{
    Sprite imagen;
}
/**
 * @brief Imagen::ObtenerImagen Obtiene una imagen
 * @param Nimagen nombre de la imagen
 */
void Imagen::ObtenerImagen(String Nimagen)
{
  this->nameI = Nimagen;
  CargarImagen();


}
/**
 * @brief Imagen::CargarImagen Metodo para cargar una imagen
 */
void Imagen::CargarImagen()
{
    if (!pTexture.loadFromFile(nameI/*, sf::IntRect(100,0,100,150)*/))
         cout << "Error al cargar la imagen" << std::endl;

     this->imagen.setTexture(pTexture);
     this->imagen.setPosition(25,25);

}
/**
 * @brief Imagen::DivisionImagen4x4 Realiza una division de una imagen
 */
String Imagen::DivisionImagen4x4()
{
    enum Fila {First,Second,Third,Quarte};
    Vector2i source (1,First);

    NULL;
}
/**
 * @brief Imagen::DibujarImagen Metodo para realizar el dibujo de una imagen
 * @return Imagen dibujada
 */
Sprite Imagen::DibujarImagen()
{
    return this->imagen;
}
