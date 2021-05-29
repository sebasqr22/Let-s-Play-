#include "imagen.h"
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "imagen.h"
using namespace sf;
using namespace std;

Imagen::Imagen()
{
    Sprite imagen;
}
void Imagen::ObtenerImagen(String Nimagen)
{
  this->nameI = Nimagen;
  CargarImagen();


}

void Imagen::CargarImagen()
{
    if (!pTexture.loadFromFile(nameI/*, sf::IntRect(100,0,100,150)*/))
         cout << "Error al cargar la imagen" << std::endl;

     this->imagen.setTexture(pTexture);
     this->imagen.setPosition(25,25);

}
String Imagen::DivisionImagen4x4()
{
    enum Fila {First,Second,Third,Quarte};
    Vector2i source (1,First);

    NULL;
}

Sprite Imagen::DibujarImagen()
{
    return this->imagen;
}
