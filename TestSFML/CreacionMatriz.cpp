#include "cuadro.cpp"

using namespace std;

class CreacionMatriz{
private:
    Cuadro matriz[88];
    int x1 = 0;
    int x2 = 26;
    int y1 = 0;
    int y2 = 26;
    void setMatriz(){
        for(int i=0; i<=88; i++){
            Cuadro cuadro;
            cuadro.setPosicion(x1, x2, y1, y2);
            x1 += 26;
            x2 += 26;
            y1 += 26;
            y2 += 26;
        }
    }
public:
};
