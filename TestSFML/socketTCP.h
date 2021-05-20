#ifndef SOCKETTCP_H
#define SOCKETTCP_H
#include <SFML/Network.hpp>
using namespace sf;

class SocketTCP
{
public:
    TcpSocket socket;
    IpAddress ip = IpAddress::getLocalAddress();
    char buffer[2000];
    size_t received;

public:
    SocketTCP(bool connectionType);


};

#endif // SOCKETTCP_H
