#ifndef SOCKETTCP_H
#define SOCKETTCP_H
#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;
/**
 * @brief The SocketTCP class Clase Servidor encargada de las operaciones principales y manejo de algoritmos
 */
class SocketTCP
{
public:
    /**
     * @brief Path Ruta a eguir
     */
    bool Path[20];
    /**
     * @brief matriz matriz de juego
     */
    Vector3f matriz[8][11];
    /**
     * @brief solution Matriz de solucion
     */
    int solution[8][11];
    int maze[8][11] = {
        {0,1,0,1,1,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,0,0,0},
        {0,1,0,0,0,1,0,0,1,1,0},
        {0,1,0,0,0,0,0,1,0,0,0},
        {0,1,0,0,0,1,0,0,0,1,0},
        {0,1,0,1,1,0,0,1,0,0,0},
        {0,1,0,1,1,0,0,1,0,0,0},
        {0,1,0,1,1,0,0,0,0,0,0}
    };
    /**
     * @brief socket Soquet de conexion
     */
    TcpSocket socket;
    /**
     * @brief ip Direcion ip
     */
    IpAddress ip = IpAddress::getLocalAddress();
    /**
     * @brief buffer Mensaje
     */
    char buffer[2000];
    /**
     * @brief received tamanio de mensaje recivido
     */
    size_t received;

    int obstacles[20];

    int Algoriythm;

    Vector2i posBacktracking;

public:
    /**
     * @brief Backtracking Algoritmo backtracking
     * @param r Fila en la matriz
     * @param c Columna en la matriz
     * @return La solucion o path
     */
    int Backtracking(int r, int c);
    /**
     * @brief isEmpty Si un cuadro esta vacio
     * @param position Posicion en la matriz
     * @return Si esta vacio o no
     */
    bool isEmpty(Vector2f position);
    /**
     * @brief printsolution Imprime el path solucion
     */
    void printsolution();
    /**
     * @brief executeBacktracking ejecuta el Backtracking
     * @return La solucion
     */
    void executeBacktracking(int a, int b);
    /**
     * @brief SocketTCP Socket Servidor
     * @param connectionType Tipo de conexion
     * @param rects Array de rectangulos de la interfaz
     */
    SocketTCP(bool connectionType, RectangleShape rects[88], int Mode);


};

#endif // SOCKETTCP_H
