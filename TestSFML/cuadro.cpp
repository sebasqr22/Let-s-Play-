/**
 * @brief The Cuadro class Clase para identificar las partes de la matriz
 */
class Cuadro{
  private:
    bool estaBola = false;
    bool fueraCancha;
    int x1;
    int x2;
    int y1;
    int y2;
  public:
    /**
     * @brief setPosicion Establece la posicion del cuadro
     * @param x1 Posicion x1
     * @param x2 Posicion x2
     * @param y1 Posicion y1
     * @param y2 Posicion y2
     */
    void setPosicion(int x1, int x2, int y1, int y2){
        this->x1 = x1;
        this->x2 = x2;
        this->y1 = y1;
        this->y2 = y2;
    }
    /**
     * @brief setFueraCancha Establece si el cuadro no se encuentra en la zona de juego
     * @param fuera Bool con informacion sobre la posicion
     */
    void setFueraCancha(bool fuera){
        this->fueraCancha = fuera;
    }
    /**
     * @brief setBola Establece si la bola se encuentra en el cuadro
     * @param estaBola Bool que dice si contiene la bola
     */
    void setBola(bool estaBola){
        this->estaBola = estaBola;
    }
    /**
     * @brief getPosicion Obtener posicion del cuadro
     * @param pos Establece la coordena que desea obtener
     * @return
     */
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
