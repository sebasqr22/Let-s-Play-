#include "socketTCP.h"
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

int filas = 8;
int columnas = 11;
//function to print the solution matrix
void SocketTCP::printsolution()
{
    int i,j;
    for(i=0;i<filas;i++)
    {
        for(j=0;j<columnas;j++)
        {
            printf("%i",this->solution[i][j]);
            //cout << solution[i][j] << end;
            //printf("%dt",solution[i][j]);
        }
        cout << "nn" << endl;
        //printf("nn");
    }
}

//function to solve the maze
//using backtracking
int SocketTCP::Backtracking(int r, int c)
{
    //if destination is reached, maze is solved
    //destination is the last cell(maze[SIZE-1][SIZE-1])
    if((r==filas-4) && (c==columnas-1))  // Llegada
    {
        this->solution[r][c] = 1;
        return 1;
    }
    //checking if we can visit in this cell or not
    //the indices of the cell must be in (0,SIZE-1)
    //and solution[r][c] == 0 is making sure that the cell is not already visited
    //maze[r][c] == 0 is making sure that the cell is not blocked
    if(r>=0 && c>=0 && r<filas && c<columnas && this->solution[r][c] == 0 && this->matriz[r][c].z == 0)
    {
        //if safe to visit then visit the cell
        this->solution[r][c] = 1;

        //going right
        if(Backtracking(r, c+1))
            return 1;
        //going down
        if(Backtracking(r+1, c))
            return 1;
        //going up
        if(Backtracking(r-1, c))
            return 1;
        //going left
        if(Backtracking(r, c-1))
            return 1;
        //backtracking
        this->solution[r][c] = 0;
        return 0;
    }
    return 0;

}

int SocketTCP::executeBacktracking(){
    //making all elements of the solution matrix 0
    int i,j;
    for(i=0; i<filas; i++)
    {
        for(j=0; j<columnas; j++)
        {
            solution[i][j] = 0;
        }
    }
    if (Backtracking(1,1)) //partida
        printsolution();
    else
        printf("No solutionn");
    return 0;
}


SocketTCP::SocketTCP(bool connectionType,RectangleShape rects[88])
{
    int k = 0;
    for (int i = 0;i<8;i++){

        for (int j=0;j<11;j++){
            this->matriz[i][j].x = rects[k].getPosition().x;
            this->matriz[i][j].y = rects[k].getPosition().y;
            this->matriz[i][j].z = 0;
            //cout << this->matriz[i][j].x << " and " << this->matriz[i][j].y << endl;;
            k++;
        }

    }

    executeBacktracking();



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



    /*while(!done){
        cout << "n" << endl;

        if(mode=="s"){
            //getline(cin, text);
            text = "Okay";
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
                //////
                if(mode=="s"){
                    //getline(cin, text);
                    text="Correcto";
                    this->socket.send(text.c_str(), text.length() + 1);
                    mode = "r";
                //////



            }
        }
    }*/

}
