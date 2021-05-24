#include "cuadro.cpp"

class Matriz{
private:
    Cuadro matriz[80];
    int x1 = 0;
    int x2 = 10;
    int y1 = 0;
    int y2 = 10;

public:
    void generarMatriz(){
        for(int i=0; i<=80; i++){
            x1 += 10;
            x2 += 10;
            y1 += 10;
            y2 += 10;
            Cuadro nuevoCuadro;
            nuevoCuadro.setPosicion(x1, x2, y1, y2);
            matriz[i] = nuevoCuadro;
        }
    }
    Cuadro getMatriz(int pos){
        return matriz[pos];
    }
};
