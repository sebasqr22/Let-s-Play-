#include <iostream>
#include <string>
#include <unistd.h>

using namespace std;

class path{
public:
    int h1;
    int h2;
    int h3;
    int costeDia = 2;

    bool finalizado = false;
    int i_final = 4;
    int j_final = 10;

    int i_actual = 0;
    int j_actual = 0;

    int hTemp = 0;
    bool calcH = true;

    int i_h = 0;
    int j_h = 0;

    int ocupados[100][100];

    string resultados;

    int matriz[8][11] = { //0 representa paso libre, 1 ocupado
      {0,0,1,0,0,0,0,0,0,0,0},
        {0,0,1,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0}, //aqui
        {0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,1,0,0,0,0,0,0,0},
        {0,0,1,1,0,0,0,0,0,0,0},
    };
    int mover(){
        int heu = 0;
        while(calcH){
            if(j_h != j_final){
                if(matriz[i_h][j_h+1] == 0){
                    j_h ++;
                    heu ++;
                }
                else{
                    cout << "Heu 4" << endl;
                    j_h ++;
                    /*
                    bool limpio = false;
                    int veces = 0;
                    while(limpio == false){
                        if(matriz[i_h][j_h+1] == 0){
                            veces ++;
                            limpio = true;
                            j_h += veces;
                        }
                        else{
                            j_h ++;
                        }
                    }
                    */
                    heu += 15;
                }
            }
            else{
                if(i_h > i_final){ //hacia arriba
                    if(matriz[i_h - 1][j_h] == 0){
                        i_h --;
                        heu ++;
                    }
                    else{
                        cout << "Heu 4" << endl;
                        i_h --;
                        heu += 15;
                    }
                }
                else{// hacia abajo
                    if(matriz[i_h + 1][j_h] == 0){
                        i_h ++;
                        heu ++;
                    }
                    else{
                        cout << "Heu 4" << endl;
                        i_h ++;
                        heu += 15;

                    }
                }
            }
            cout << i_h << " | " << j_h << endl;
            if(i_h == i_final && j_h == j_final){
                calcH = false;
            }
        }
        calcH = true;
        return heu;
    }
    void calcularH(){
        if(j_actual != 10){ //hacia la derecha
            i_h = i_actual;
            j_h = j_actual + 1;
            hTemp = mover();
            h1 = hTemp;
        }

        /*
        i_h = i_actual;
        if(j_actual != 10){
            j_h = j_actual + 1;
        }
        else{
            j_h = 10;
        }
        hTemp = mover();
        h1 = hTemp;
        */

        if(i_actual != 0 && i_actual != 3){ //hacia arriba
            i_h = i_actual - 1;
            j_h = j_actual;
            hTemp = mover();
            h2 = hTemp;
        }
        if(i_actual != 7){ //hacia abajo
            i_h = i_actual + 1;
            j_h = j_actual;
            hTemp = mover();
            h3 = hTemp;
        }
    }

    int determinarMenor(int type){
        int menor;
        if(type == 1){
            menor = h1;
        }
        else if(type == 2){
            menor = h2;
        }
        else if(type == 3){
            menor = h3;
        }
        else{
            menor = 0;
        }
        // termina tipos
        if(h1 < menor){
            if(h1 != 0){
                menor = h1;
            }
        }
        if(h2 < menor){
            if(h2 != 0){
                menor = h2;
            }
        }
        if(h3 < menor){
            if(h3 != 0){
                menor = h3;
            }
        }
        if(i_actual == 3 && j_actual == 10){
            return 1;
        }
        if(menor != 0){
            return menor;
        }
        else{
            return determinarMenor(type + 1);
        }

    }

    void imprimir(int menor){
        if(menor == h1){
            cout << "MENOR: H1" << endl;
        }
        else if(menor == h2){
            cout << "MENOR: H2" << endl;
        }
        else{
            cout << "MENOR: H3" << endl;
        }
        cout << "ACTUAL: " + to_string(i_actual) + "," + to_string(j_actual) << endl;

    }

    void calcular(){
        resultados += to_string(i_actual) + "," + to_string(j_actual) + "|";
        while(finalizado == false){
            calcularH();
            int menor = determinarMenor(1);
            cout << "MENOR: " << menor << endl;
            imprimir(menor);
            if(menor == 0){ //no se encontro respuesta
                resultados = "NO";
                break;
            }
            if(i_actual == 3 && j_actual == 10){
                i_actual ++;
            }
            else if (i_actual == 5 && j_actual == 10){
                i_actual --;
            }
            else{
                if (menor == h1){
                j_actual ++;
                }
                else if(menor == h2 and i_actual != 3){
                    i_actual --;
                }
                else{
                    i_actual += 1;
                }
            }

            cout << "AVANZA: " + to_string(i_actual) + "," + to_string(j_actual) << endl;
            resultados += to_string(i_actual) + "," + to_string(j_actual) + "|";
            //sleep(2);
            if(i_actual == i_final && j_actual == j_final){
                finalizado = true;
            }
        }
        finalizado = false;
    }


    void setOcupados(int ocu[10]){

    }
    int getH(int type){
        switch(type){
            case 1:{
                return h1;
            }
            case 2:{
                return h2;
            }
            case 3:{
                return h3;
            }
        }
    }
    string getResultado(){
        return resultados;
    }
    int getS(){
        //return matriz[i_actual][j_actual+1];
        return i_actual;
    }
};
