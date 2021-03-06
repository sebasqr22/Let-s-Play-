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
#include <QDebug>
#include <vector>
#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include <QDomProcessingInstruction>
#include <QtXml>
#include <QDir>
#include <QString>
using namespace std;

struct Generation{
   QString gen;
   QString list;
};

vector <struct Generation > mVec;
/**
 * @brief GeneticA::GeneticA Costrcutor principal de la clase
 */
alGen::alGen()
{

}

void alGen::Write(QString gen, QString lista ){
    struct Generation Gen;
    QString myMsg = "Mensaje ,";
    Gen.gen = gen;
    Gen.list = lista ;
    mVec.push_back(Gen);

}
void alGen::CreateXMLFile(int i){

    string D = "XML" + to_string(i) + ".xml";
    //cout << D << endl;
    QString nameD = QString::fromLocal8Bit(D.c_str());

    QFile mfile (nameD);
    if (!mVec.empty()){
        //cout << mVec.size() << "  Dates saved" << endl;
        //Create Documen
        QDomDocument myDoc;
        QDomProcessingInstruction pi;
        pi= myDoc.createProcessingInstruction("xml","version =\"1.0\" encoding=\"utf-8\" ");
        myDoc.appendChild(pi);

        //Add root node
        QDomElement root;
        root = myDoc.createElement("root");
        myDoc.appendChild(root);


        for(auto it = mVec.begin(); it != mVec.end(); it ++)
        {
           QDomElement generacion = myDoc.createElement("generacion");

           QDomElement gen = myDoc.createElement("Numerodegeneracion");
           QDomText tGen = myDoc.createTextNode(it->gen);
           gen.appendChild(tGen);
           generacion.appendChild(gen);

           QDomElement list = myDoc.createElement("Lista");
           QDomText tList = myDoc.createTextNode(it->list);
           list.appendChild(tList);
           generacion.appendChild(list);

           root.appendChild(generacion);

        }

        if(mfile.open(QIODevice::WriteOnly | QIODevice::Text)){

            QTextStream out(&mfile);
            out << myDoc.toString();

            mVec.clear();
            mfile.flush();
            mfile.close();
        }
    }

}
// VARIABLES///
int tam_pob = 20; // n??mero de individuos en la poblaci??n
int tam_torneo = 50; // tama??o del torneo
int generaciones = 1000; // cantidad de generaciones
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
    poblacion.push_back(this->individuodado); //inserta en el vectorpoblaci??n
}

// Creaci??n de la Poblaci??n inicial
/**
 * @brief GeneticA::PoblacionInicial Define la poblacion inicial
 */
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

        poblacion.push_back(individuo); //inserta en el vector  poblaci??n
    }
}


void alGen::mostrarPoblacion()
{
    for(int i = 0; i < tam_pob; i++)
    {
        for(int j = 0; j < this->tam_genes; j++)
            cout << poblacion[i][j] << " ";
        cout << endl;
    }
}
/**
 * @brief GeneticA::mutacion Metodo para realizar una mutacion
 * @param individuo Individuo a realizar la mutacion
 */
// metodo de mutacion
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

// metodo donde se realizan los cruces
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
// devuelve la puntuaci??n del individuo
/**
 * @brief GeneticA::obtenerPuntuacion Mostrar la puntuacion del jugador
 * @param individuo Jugador con calificacion
 * @return Sumatoria de puntos
 */
int alGen::obtenerPuntuacion(QVector<int> individuo)
{
    // la puntuaci??n es la suma de los valores de los genes
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
/**
 * @brief GeneticA::obtenerMejor Obtiene el indice del mejor individuo de la poblacion
 * @return Individuo con mejor indice de la poblacion
 */
// devuelve el ??ndice del mejor individuo de la poblaci??n
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

    Individuo_E(ListA);//Agrega el individuo dado a la poblaci??n
    individuoM();

    PoblacionInicial();//Creaci??n de la nueva poblaci??n
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


                // calcular la probabilidad de mutaci??n
                prob = ((double) rand() / ((double)RAND_MAX + 1));

                if(prob < prob_mut){
                    mutacion(hijo);
                 }

                int score_padre = obtenerPuntuacion(poblacion[indice_padre1]);
                int score_hijo = obtenerPuntuacion(hijo);



                /*
                    si la puntuaci??n del hijo fue mejor que la de padre1, reemplace el padre 1 con el hijo
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

        string genX = to_string(i);
        QString genXM = QString::fromLocal8Bit(genX.c_str());

        QVector<int> mejor;

        int indice_mejor = obtenerMejor();

        mejor=poblacion[indice_mejor];
        int score_mejor = obtenerPuntuacion(mejor);

        string listX;


        for(int j = 0; j < this->tam_genes; j++)
        {
            cout << mejor[j] << " ";
            listX += to_string(mejor[j]);

        }
        QString listXM = QString::fromLocal8Bit(listX.c_str());
        Write(genXM,listXM);
        CreateXMLFile(generacion);

        cout << "\nPuntuaci??n: " << score_mejor << "\n\n";



        //comprueba si encontr?? la soluci??n global ??ptima
        if(score_mejor == tam_genes)
            break;


    }

    return 0;

}

