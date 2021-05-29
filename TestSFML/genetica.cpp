#include "genetica.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;

GeneticA::GeneticA()
{
    // Variables de algoritmo genético
    int tam_genes = 12; // cantidad de genes
    int tam_pob = 50; // número de individuos en la población
    int tam_torneo = 20; // tamaño del torneo
    int generaciones = 100; // cantidad de generaciones
    double prob_mut = 0.6; // probabilidad de mutacion
    double prob_cruz = 0.9; // probabilidad de cruzamento

 }
// poblacion
vector<vector<int> > poblacion;

void GeneticA::PoblacionInicial()
{
    for(int i = 0; i < tam_pob; i++)
    {
        vector<int> individuo;

        for(int j = 0; j < tam_genes; j++)
        {
            int num = rand() % 2; // elija un número en el rango [0.1]crear arreglo
            individuo.push_back(num); // inserta en el vector individuo
        }

        poblacion.push_back(individuo); //inserta en el vector  población
    }
}

void GeneticA::mostrarPoblacion()
{
    for(int i = 0; i < tam_pob; i++)
    {
        for(int j = 0; j < tam_genes; j++)
            cout << poblacion[i][j] << " ";
        cout << endl;
    }
}

// devuelve la puntuación del individuo
int GeneticA::obtenerPuntuacion(vector<int> individuo)
{
    // la puntuación es la suma de los valores de los genes
    int suma = 0;

    for(int i = 0; i < tam_genes; i++)
        suma += individuo[i];
    return suma;
}


// realización de mutacion
void GeneticA::mutacion(vector<int>& individuo)
{
    //elige un gen al azar en el rango [0, tam_genes - 1]
    int gene = rand() % tam_genes;

    // modifica el valor del gen escogido
    if(individuo[gene] == 0)
        individuo[gene] = 1;
}
// realización de los cruces
void GeneticA::Cruzamiento(int indice_padre1, int indice_padre2, vector<int>& hijo)
{
    // elige un punto al azar en el rango [0, tam_genes - 1]
    int punto = rand() % tam_genes;

    for(int i = 0; i <= punto; i++)
        hijo.push_back(poblacion[indice_padre1][i]);
    for(int i = punto + 1; i < tam_genes; i++)
        hijo.push_back(poblacion[indice_padre2][i]);
}

// devuelve el índice del mejor individuo de la población
int GeneticA::obtenerMejor()
{
    int indice_mejor = 0;
    int score_mejor = obtenerPuntuacion(poblacion[0]);

    for(int i = 1; i < tam_pob; i++)
    {
        int score = obtenerPuntuacion(poblacion[i]);
        if(score > score_mejor)
        {
            indice_mejor = i;
            score_mejor = score;
        }
    }

    return indice_mejor;
}

int GeneticA::Principal()
{
srand(time(NULL));

PoblacionInicial();

int PuzzleOrden[]= {1,2,3,4,5,6,7,8,9,10,11,12};

for(int i = 0; i < generaciones; i++)
{
    for(int j = 0; j < tam_torneo; j++)
    {

        // calcula las probabilidades de cruzamiento
        double prob = ((double) rand() / ((double)RAND_MAX + 1));

        if(prob < prob_cruz)
        {
            // elige dos padres
            int indice_padre1 = rand() % tam_pob;
            int indice_padre2;

            // asegura que las calificaciones de los padres no sean las mismas
            do
            {
                indice_padre2 = rand() % tam_pob;
            }
            while(indice_padre1 == indice_padre2);

            vector<int> hijo;

            // aplica un cruce de 1 punto
            Cruzamiento(indice_padre1, indice_padre2, hijo);

            // calcular la probabilidad de mutación
            prob = ((double) rand() / ((double)RAND_MAX + 1));

            if(prob < prob_mut)
                mutacion(hijo);

            int score_padre = obtenerPuntuacion(poblacion[indice_padre1]);
            int score_hijo = obtenerPuntuacion(hijo);

            /*
                si la puntuación del hijo fue mejor que la de padre1, reemplace el padre 1 con el hijo
            */
            if(score_hijo > score_padre)
            {
                // hace la copia de los genes del hijo al padre
                for(int k = 0; k < tam_genes; k++)
                    poblacion[indice_padre1][k] = hijo[k];
            }
        }
    }

    cout << "Generacion " << i + 1 << endl;
    cout << "Mejor: ";

    int indice_mejor = obtenerMejor();
    int score_mejor = obtenerPuntuacion(poblacion[indice_mejor]);

    for(int j = 0; j < tam_genes; j++)
        cout << poblacion[indice_mejor][j] << " ";

    cout << "\nPuntuación: " << score_mejor << "\n\n";

    //comprueba si encontró la solución global óptima
    if(score_mejor == tam_genes)
        break;
}

return 0;
}
