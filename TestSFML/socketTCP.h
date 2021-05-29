#ifndef SOCKETTCP_H
#define SOCKETTCP_H
#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;

class SocketTCP
{
public:
    bool Path[20];
    Vector3f matriz[8][11];

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

    TcpSocket socket;
    IpAddress ip = IpAddress::getLocalAddress();
    char buffer[2000];
    size_t received;

public:

    int Backtracking(int r, int c);
    bool isEmpty(Vector2f position);
    void printsolution();
    int executeBacktracking();

    SocketTCP(bool connectionType, RectangleShape rects[88]);


};

#endif // SOCKETTCP_H
