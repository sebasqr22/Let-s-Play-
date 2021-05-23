#include "socketTCP.h"
#include <iostream>
using namespace std;

SocketTCP::SocketTCP(bool connectionType)
{
    string text = "Connected to: ";
    string mode;

    if (connectionType==1){
        cout << "yes" << endl;
        TcpListener listener;
        listener.listen(8000);
        listener.accept(this->socket);

        text += "Server";
        mode = "s";
        //cout << text << endl;

    } else if (connectionType==0){
        this->socket.connect(this->ip,2000);

        text += "Client";
        mode = "r";
    }

    this->socket.send(text.c_str(), text.length() + 1);

    this->socket.receive(this->buffer, sizeof(this->buffer), this->received);
    cout << this->buffer << endl;

    bool done = false;
    int cont = 0;
    while(!done && connectionType == 1){
        if(mode=="s"){
            getline(cin, text);
            this->socket.send(text.c_str(), text.length() + 1);
            mode = "r";
            cont +=1;
        } else if(mode=="r") {
            this->socket.receive(this->buffer, sizeof(this->buffer), this->received);
            if (received>0){
                cout << "Received: " << this->buffer << endl;
                string  msgR = this->buffer;

                if (msgR == "mensaje"){
                    cout << "funciona" << endl;
                }


                mode = "s";
                /*
                if(mode=="s"){
                    //getline(cin, text);
                    text="Correcto";
                    this->socket.send(text.c_str(), text.length() + 1);
                    mode = "r";
                }*/



            }
        }
    }

}
