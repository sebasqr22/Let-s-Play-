#ifndef ALGEN_H
#define ALGEN_H
#include <QList>
#include <iostream>
#include <QVector>
#include <stdlib.h>
#include <time.h>



class alGen
{
public:
    alGen();
    int tam_genes ; // cantidad de genes
    QList<int> ListaNumeros;
    QList<int> ListaNumerosA;
    QList<int> ListaNumerosM;
    QVector<int> individuodado;
    int Aleatorios(int tam_genes);
    void PoblacionInicial();
    void mostrarPoblacion();
    void Individuo_E(int list[]);
    int obtenerPuntuacion(QVector<int> individuo);
    void mutacion(QVector<int>& individuo);
    void Cruzamiento(int indice_padre1, int indice_padre2, QVector<int>& hijo);
    int obtenerMejor();
    void individuoM();
    int Principal(int cantidad);
    void CreateXMLFile(int i);
    void Write(QString gen, QString lista);
};

#endif // ALGEN_H
