class Cuadro{
  private:
    bool estaBola = false;
    bool fueraCancha;
    int x1;
    int x2;
    int y1;
    int y2;
  public:
    void setPosicion(int x1, int x2, int y1, int y2){
        this->x1 = x1;
        this->x2 = x2;
        this->y1 = y1;
        this->y2 = y2;
    }
    void setFueraCancha(bool fuera){
        this->fueraCancha = fuera;
    }
    void setBola(bool estaBola){
        this->estaBola = estaBola;
    }
    int getPosicion(int pos){
        switch(pos){
        case 1:
            return this->x1;
        case 2:
            return this->x2;
        case 3:
            return this->y1;
        case 4:
            return this->y2;
        }
    }
};
