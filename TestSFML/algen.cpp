/**
  *@file genetica.cpp
  * @title Genetica
  * @brief Clase con el algoritmo genetico
*/

#include "algen.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <QVector>
#include <qvector.h>
using namespace std;

/**
 * @brief GeneticA::GeneticA Costrcutor principal de la clase
 */
alGen::alGen()
{

}
// VARIABLES///
int tam_pob = 20; // número de individuos en la población
int tam_torneo = 50; // tamaño del torneo
int generaciones = 500; // cantidad de generaciones
double prob_mut = 0.6; // probabilidad de mutacion
double prob_cruz = 0.9; // probabilidad de cruzamento
QVector<QVector<int> > poblacion;// poblacion del algoritmo


int alGen::Aleatorios(int tam){
    this->ListaNumeros.clear();
    this->ListaNumerosA.clear();

    for(int i=0; i<tam; i++){
       this->ListaNumeros.append(i);
    }

    for(int a = 0; a<tam; a++){
        int num = rand()% ListaNumeros.size();
        this->ListaNumerosA.append(ListaNumeros[num]);
        this->ListaNumeros.removeAt(num);
    }
    return 0;
}

void alGen::individuoM(){
    for(int i=0; i<this->tam_genes; i++){
       this->ListaNumerosM.append(i);
    }
}

void alGen::Individuo_E(int list[]){
    for(int j = 0; j < this->tam_genes; j++)
    {
        this->individuodado.push_back(list[j]); // inserta en el vector al individuo dado
    }
    poblacion.push_back(this->individuodado); //inserta en el vectorpoblación
}

/**
 * @brief GeneticA::PoblacionInicial Define la poblacion inicial
 */

// Creación de la Población inicial
void alGen::PoblacionInicial()
{
    for(int i = 0; i < tam_pob; i++)
    {
        QVector<int> individuo;// Se crean los nuevos individuos
        Aleatorios(this->tam_genes);

        for(int j = 0; j < this->tam_genes; j++)
        {
            individuo.push_back(ListaNumerosA[j]); // inserta en el vector individuo
        }

        poblacion.push_back(individuo); //inserta en el vector  población
    }
}

/**
 * @brief GeneticA::mostrarPoblacion Metodo para mostrar la poblacion del algoritmo
 */
void alGen::mostrarPoblacion()
{
    for(int i = 0; i < tam_pob; i++)
    {
        for(int j = 0; j < this->tam_genes; j++)
            cout << poblacion[i][j] << " ";
        cout << endl;
    }
}

// devuelve la puntuación del individuo
/**
 * @brief GeneticA::obtenerPuntuacion Mostrar la puntuacion del jugador
 * @param individuo Jugador con calificacion
 * @return Sumatoria de puntos
 */
int alGen::obtenerPuntuacion(QVector<int> individuo)
{
    // la puntuación es la suma de los valores de los genes
    int suma = 0;
    ListaNumerosM.clear();
    individuoM();
    for(int i = 0; i < this->tam_genes; i++){
        if (individuo[i] == this->ListaNumerosM[i]){
            suma++;
        }
     }
    return suma;
}


// realización de mutacion
/**
 * @brief GeneticA::mutacion Metodo para realizar una mutacion
 * @param individuo Individuo a realizar la mutacion
 */
void alGen::mutacion(QVector<int>& individuo)
{
    //elige dos genes alzar para intercambiarlo
    int gen1 = rand() % this->tam_genes;
    int gen2 ;
    do
    {
        gen2 = rand() % this->tam_genes;
    }
    while(gen1 == gen2);
       // modifica el valor del gen escogido
    int aux = individuo[gen1];
    individuo[gen1]= individuo[gen2];
    individuo[gen2]= aux;
}

// realización de los cruces
/**
 * @brief GeneticA::Cruzamiento Metodo para gener un cruzamiento
 * @param indice_padre1 Padre 1
 * @param indice_padre2 Padre 2
 * @param hijo Individuo hijo de Padre 1 y Padre 2
 */

void alGen::Cruzamiento(int indice_padre1, int indice_padre2, QVector<int>& hijo)
{
    // elige un punto al azar en el rango [0, tam_genes - 1]
    int punto = rand() % this->tam_genes;

    for(int i = 0; i <= punto; i++)
        hijo.push_back(poblacion[indice_padre1][i]);
    for(int i = punto + 1; i < this->tam_genes; i++)
        hijo.push_back(poblacion[indice_padre2][i]);
}

// devuelve el índice del mejor individuo de la población
/**
 * @brief GeneticA::obtenerMejor Obtiene el indice del mejor individuo de la poblacion
 * @return Individuo con mejor indice de la poblacion
 */
int alGen::obtenerMejor()
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
} // fin obtenerMejot

/**
 * @brief GeneticA::Principal Metodo principal
 */
int alGen::Principal(int cantidad){

    srand(time(NULL));

    int ListA[]={7,10,6,2,4,8,11,1,3,5,9,0};

    this->tam_genes = cantidad;
    cout << "********InICIO*********" << endl;

    Individuo_E(ListA);//Agrega el individuo dado a la población
    individuoM();

    PoblacionInicial();//Creación de la nueva población
    //mostrarPoblacion();


    for(int i = 0; i < generaciones; i++)
    {
        for(int j = 0; j < tam_pob; j++)
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

                QVector<int> hijo;


                // aplica un cruce de 1 punto
                Cruzamiento(indice_padre1, indice_padre2, hijo);


                // calcular la probabilidad de mutación
                prob = ((double) rand() / ((double)RAND_MAX + 1));

                if(prob < prob_mut){
                    mutacion(hijo);
                 }

                int score_padre = obtenerPuntuacion(poblacion[indice_padre1]);
                int score_hijo = obtenerPuntuacion(hijo);



                /*
                    si la puntuación del hijo fue mejor que la de padre1, reemplace el padre 1 con el hijo
                */
                if(score_hijo > score_padre)
                {
                    // hace la copia de los genes del hijo al padre
                    for(int k = 0; k < this->tam_genes; k++)
                        poblacion[indice_padre1][k] = hijo[k];
                }
            }

        }

        int generacion = i+1;
        cout << "Generacion " << generacion << endl;
        cout << "Mejor: ";


        QVector<int> mejor;

        int indice_mejor = obtenerMejor();

        mejor=poblacion[indice_mejor];
        int score_mejor = obtenerPuntuacion(mejor);


        for(int j = 0; j < this->tam_genes; j++)
        {
            cout << mejor[j] << " ";
        }

        cout << "\nPuntuación: " << score_mejor << "\n\n";


        //comprueba si encontró la solución global óptima
        if(score_mejor == tam_genes)
            break;

    }

    return 0;

}
