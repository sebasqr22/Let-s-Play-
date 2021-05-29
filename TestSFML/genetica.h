#ifndef GENETICA_H
#define GENETICA_H
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;


class GeneticA
{
public:
    GeneticA();
    int tam_genes;
    int tam_pob;
    int tam_torneo;
    int generaciones;
    double prob_mut;
    double prob_cruz;
    void PoblacionInicial();
    void mostrarPoblacion();
    int obtenerPuntuacion(vector<int> individuo);
    void mutacion(vector<int>& individuo);
    void Cruzamiento(int indice_padre1, int indice_padre2, vector<int>& hijo);
    int obtenerMejor();
    int Principal();

};

#endif // GENETICA_H
