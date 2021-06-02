#include <iostream>
#include <string>
#include <unistd.h>

using namespace std;

class path{
private:
    int h1;
    int h2;
    int h3;
    int costeDia = 2;

    bool finalizado = false;
    int i_final = 4;
    int j_final = 10;

    int i_pasado = 0;
    int j_pasado = 0;
    int pasado = 0;

    int i_actual = 2;
    int j_actual = 0;

    int hTemp = 0;
    bool calcH = true;

    int movimientoEspe;

    int i_h = 0;
    int j_h = 0;

    int ocupados[100][100];

    string resultados;

    int matriz[8][11] = { //0 representa paso libre, 1 ocupado
        {0,0,0,1,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,1,0,0},
        {0,0,0,1,0,0,0,1,0,0,0},
        {0,1,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,1,0,0,0,0}, //aqui
        {0,0,1,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,1,0,0,0,0,0,0,0},
                 //
    };
    int matrizEnvio[8][11] = { //0 representa paso libre, 1 ocupado
        {0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0}, //aqui
        {0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0},
                 //
    };
    void cambiarEnvio(int i, int j){
        matrizEnvio[i][j] = 1;
    }

    void imprimirEnvio(){
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 11; j++){
                cout << matrizEnvio[i][j];
            }
            cout << "\n";
        }
    }

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
    int calcularHespe(int pos){
        if(pos == 2){
            if(i_actual != 0 && i_actual != 3){ //hacia arriba
                i_h = i_actual - 1;
                j_h = j_actual;
                hTemp = mover();
                return hTemp;
            }
        }
        else if(pos == 3){
            if(i_actual != 7){ //hacia abajo
                i_h = i_actual + 1;
                j_h = j_actual;
                hTemp = mover();
                return hTemp;
            }
        }
        else{
            if(j_actual != 10){ //hacia la derecha
                i_h = i_actual;
                j_h = j_actual + 1;
                hTemp = mover();
                return hTemp;
            }
        }
    }

    bool verificacion(int menor){
        if(menor == h1 && h1 != 0){
            return false;
        }
        else if(menor == h2 && h2 != 0){
            if(pasado == 3){
                return true;
                movimientoEspe = 2;
            }
            else{
                return false;
            }
        }
        else if(menor == h3 && h3 != 0){
            if(pasado == 2){
                return true;
                movimientoEspe = 3;
            }
            else{
                return false;
            }
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
        /*if(matriz[i_actual][j_actual + 1] != 0){
            return -1;
        }*/
        if(menor != 0){
            if(menor == h1){
                return menor;
            }
            else if(verificacion(menor) == true){
                return -1;
            }
            else{
                return menor;
            }
            
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
public: 
    void calcular(){
        int contador;
        resultados += to_string(i_actual) + "," + to_string(j_actual) + "|";
        cambiarEnvio(i_actual, j_actual);
        while(finalizado == false){
            calcularH();
            int menor = determinarMenor(1);
            cout << "MENOR: " << menor << endl;
            imprimir(menor);
            if(menor == 0){ //no se encontro respuesta
                resultados = "NO";
                break;
            }
            else{
                if(i_actual == 3 && j_actual == 10){
                    i_pasado = i_actual;
                    j_pasado = j_actual;
                    pasado = 3;
                    i_actual ++;
                }
                else if (i_actual == 5 && j_actual == 10){
                    i_pasado = i_actual;
                    j_pasado = j_actual;
                    i_actual --;
                    pasado = 2;
                }
                else if(i_actual == 4 && j_actual == 9){
                    i_pasado = i_actual;
                    j_pasado = j_actual;
                    j_actual ++;
                    pasado = 1;
                }
                else if(menor == -1){
                    if(movimientoEspe == 2){
                        int temp = calcularHespe(1);
                        int temp2 = calcularHespe(3);
                        if(temp < temp2 && temp != 0){
                            if(matriz[i_actual][j_actual+1] == 0){
                                j_actual ++;
                                pasado = 1;
                            }
                            else if(matriz[i_actual+1][j_actual] == 0){
                                i_actual ++;
                                pasado = 3;
                            }
                            else{
                                resultados = "NO";
                                break;
                            }
                        }
                        else if(temp2 < temp && temp2 != 0){
                            if(matriz[i_actual+1][j_actual] == 0){
                                i_actual ++;
                                pasado = 3;
                            }
                            else if(matriz[i_actual][j_actual+1] == 0){
                                j_actual ++;
                                pasado = 1;
                            }
                            else{
                                resultados = "NO";
                                break;
                            }
                        }
                        else{
                            resultados = "NO";
                            break;
                        }

                    }
                    else{
                        int temp = calcularHespe(1);
                        int temp2 = calcularHespe(2);

                        if(temp < temp2 && temp != 0){
                            if(matriz[i_actual][j_actual+1] == 0){
                                j_actual ++;
                                pasado = 1;
                            }
                            else if(matriz[i_actual-1][j_actual] == 0){
                                i_actual --;
                                pasado = 2;
                            }
                            else{
                                resultados = "NO";
                                break;
                            }
                        }
                        else if(temp2 < temp && temp2 != 0){
                            if(matriz[i_actual-1][j_actual] == 0){
                                i_actual --;
                                pasado = 2;
                            }
                            else if(matriz[i_actual][j_actual+1] == 0){
                                j_actual ++;
                                pasado = 1;
                            }
                            else{
                                resultados = "NO";
                                break;
                            }
                        }
                        else{
                            resultados = "NO";
                            break;
                        }
                        
                    }
                }
                else{
                    if (menor == h1){ //h1 menor
                        if(matriz[i_actual][j_actual+1] == 0){
                            i_pasado = i_actual;
                            j_pasado = j_actual;
                            j_actual ++;
                            pasado = 1;
                        }
                        else{
                            int temp = calcularHespe(2);
                            int temp2 = calcularHespe(3);

                            if(temp != 0 && temp2 !=0){
                                if(temp < temp2){
                                    if(matriz[i_actual-1][j_actual] == 0){
                                        i_pasado = i_actual;
                                        j_pasado = j_actual;
                                        i_actual --;
                                        pasado = 2;
                                    }
                                    else if(matriz[i_actual+1][j_actual] == 0){
                                        i_pasado = i_actual;
                                        j_pasado = j_actual;
                                        i_actual ++;
                                        pasado = 3;
                                    }
                                    else{
                                        resultados = "NO";
                                        break;
                                    }
                                }
                                else{
                                    if(matriz[i_actual+1][j_actual] == 0){
                                        i_pasado = i_actual;
                                        j_pasado = j_actual;
                                        i_actual ++;
                                        pasado = 3;
                                    }
                                    else if(matriz[i_actual-1][j_actual] == 0){
                                        i_pasado = i_actual;
                                        j_pasado = j_actual;
                                        i_actual --;
                                        pasado = 2;
                                    }
                                    else{
                                        resultados = "NO";
                                        break;
                                    }
                                }
                            }
                            else if(temp != 0){
                                if(matriz[i_actual-1][j_actual] == 0){
                                    i_pasado = i_actual;
                                    j_pasado = j_actual;
                                    i_actual --;
                                    pasado = 2;
                                }
                                else{
                                    resultados = "NO";
                                    break;
                                }
                            }
                            else if(temp2 != 0){
                                cout << "POS: " << i_actual << "|" << j_actual << "|" << matriz[i_actual+1][j_actual] << endl;
                                if(matriz[i_actual+1][j_actual] == 0){
                                    i_pasado = i_actual;
                                    j_pasado = j_actual;
                                    i_actual ++;
                                    pasado = 3;
                                }
                                else{
                                    resultados = "NO";
                                    cout << "ENTRO AQUI H1" << endl;
                                    break;
                                }
                            }
                            else{
                                resultados = "NO";
                                break;
                            }
                        }
                    }
                    else if(menor == h2 and i_actual != 3){ //h2 menor
                        if(matriz[i_actual-1][j_actual] == 0){
                            i_pasado = i_actual;
                            j_pasado = j_actual;
                            pasado = 2;
                            i_actual --;
                        }
                        else{
                            int temp = calcularHespe(1);
                            int temp2 = calcularHespe(3);

                            if(temp != 0 && temp2 != 0){
                                if(temp < temp2){
                                    if(matriz[i_actual][j_actual+1] == 0){
                                        i_pasado = i_actual;
                                        j_pasado = j_actual;
                                        j_actual ++;
                                        pasado = 1;
                                    }
                                    else if(matriz[i_actual + 1][j_actual] == 0){
                                        i_pasado = i_actual;
                                        j_pasado = j_actual;
                                        i_actual ++;  
                                        pasado = 3; 
                                    }
                                    else{
                                        resultados = "NO";
                                        break;
                                    }
                                }
                                else{
                                    if(matriz[i_actual + 1][j_actual] == 0){
                                        i_pasado = i_actual;
                                        j_pasado = j_actual;
                                        i_actual ++; 
                                        pasado = 3;  
                                    }
                                    else if(matriz[i_actual][j_actual+1] == 0){
                                        i_pasado = i_actual;
                                        j_pasado = j_actual;
                                        j_actual ++;
                                        pasado = 1;
                                    }
                                    else{
                                        resultados = "NO";
                                        break;
                                    }
                                }
                            }
                            else if(temp != 0){
                                if(matriz[i_actual + 1][j_actual] == 0){
                                    i_pasado = i_actual;
                                    j_pasado = j_actual;
                                    i_actual ++;  
                                    pasado = 3; 
                                }
                                else{
                                    resultados = "NO";
                                    break;
                                }
                            }
                            else if(temp2 != 0){
                                if(matriz[i_actual][j_actual+1] == 0){
                                    i_pasado = i_actual;
                                    j_pasado = j_actual;
                                    j_actual ++;
                                    pasado = 1;
                                }
                                else{
                                    resultados = "NO";
                                    break;
                                }
                            }
                            else{
                                resultados = "NO";
                                break;
                            }
                        }
                        
                    }
                    else{ //h3 menor
                        if(matriz[i_actual + 1][j_actual] == 0){
                            i_pasado = i_actual;
                            j_pasado = j_actual;
                            i_actual ++;
                            pasado = 3;
                        }
                        else{
                            int temp = calcularHespe(1);
                            int temp2 = calcularHespe(2);

                            if(temp !=0 && temp2 != 0){
                                if(temp < temp2){
                                    if(matriz[i_actual][j_actual+1] == 0){
                                        i_pasado = i_actual;
                                        j_pasado = j_actual;
                                        j_actual ++;
                                        pasado = 1;
                                    }
                                    else if(matriz[i_actual-1][j_actual]==0){
                                        i_pasado = i_actual;
                                        j_pasado = j_actual;
                                        i_actual --;
                                        pasado = 2;
                                    }
                                    else{
                                        resultados = "NO";
                                        break;
                                    }
                                }
                                else{
                                    if(matriz[i_actual-1][j_actual]==0){
                                        i_pasado = i_actual;
                                        j_pasado = j_actual;
                                        i_actual --;
                                        pasado = 2;
                                    }
                                    else if(matriz[i_actual][j_actual+1] == 0){
                                        i_pasado = i_actual;
                                        j_pasado = j_actual;
                                        j_actual ++;
                                        pasado = 1;
                                    }
                                    else{
                                        resultados = "NO";
                                        break;
                                    }
                                }
                            }
                            else if(temp != 0){
                                if(matriz[i_actual][j_actual+1] == 0){
                                    i_pasado = i_actual;
                                    j_pasado = j_actual;
                                    j_actual ++;
                                    pasado = 1;
                                }
                                else{
                                    resultados = "NO";
                                    break;
                                }
                            }
                            else if(temp2 != 0){
                                if(matriz[i_actual-1][j_actual]==0){
                                    i_pasado = i_actual;
                                    j_pasado = j_actual;
                                    i_actual --;
                                    pasado = 2;
                                }
                                else{
                                    resultados = "NO";
                                    break;
                                }
                            }
                            else{
                                resultados = "NO";
                                break;
                            }
                        }
                    }
                }
            }
            
            
            cout << "AVANZA: " + to_string(i_actual) + "," + to_string(j_actual) << endl;
            resultados += to_string(i_actual) + "," + to_string(j_actual) + "|";
            cambiarEnvio(i_actual, j_actual);
            //sleep(2);
            if(i_actual == i_final && j_actual == j_final){
                finalizado = true;
            }
        }
        finalizado = false;
        imprimirEnvio();
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
    string get(){
        string resultado;
        int contador = 0;
        for(int p = 0; p<8; p++){
            for(int q=0;  q<11; q++){
                if(matrizEnvio[p][q] == 1){
                    resultado += to_string(contador) + ".";
                }
                contador ++;
            }
        }
        return resultado;
    }
    int getMatriz(int i, int j){
        return matrizEnvio[i][j];
    }
};

