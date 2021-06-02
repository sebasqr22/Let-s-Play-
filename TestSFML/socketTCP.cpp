/**
  *@file socketTCP.cpp
  * @title socketTCP
  * @brief Clase para crear los sockets
*/
#include "socketTCP.h"
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

int filas = 8;
int columnas = 11;
//function to print the solution matrix

/**
 * @brief SocketTCP::printsolution Imprime la solucion de la matriz
 */
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
/**
 * @brief SocketTCP::Backtracking Aplicacion del backtracking
 * @param r Cantidad filas
 * @param c Cantidad columnas
 */
int SocketTCP::Backtracking(int r, int c)
{
    //if destination is reached, maze is solved
    //destination is the last cell(maze[SIZE-1][SIZE-1])
    if((r==4) && (c==0))  // Llegada
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
        if(Backtracking(r, c-1))
            return 1;
        //going down
        if(Backtracking(r+1, c))
            return 1;
        //going up
        if(Backtracking(r-1, c))
            return 1;
        //going left
        if(Backtracking(r, c+1))
            return 1;
        //backtracking
        this->solution[r][c] = 0;
        return 0;
    }
    return 0;

}
/**
 * @brief SocketTCP::executeBacktracking Metodo que ejecuta el backtracking
 */
void SocketTCP::executeBacktracking(int a,int b){

    //making all elements of the solution matrix 0
    int i,j;
    for(i=0; i<filas; i++)
    {
        for(j=0; j<columnas; j++)
        {
            solution[i][j] = 0;
        }
    }
    if (Backtracking(a,b)) //partida
        printsolution();
    else
        printf("No solutionn");
    //return 0;
}

/**
 * @brief SocketTCP::SocketTCP Metodo para la creacion del socket
 * @param connectionType Tipo de conexion
 * @param rects Array de rectangulos de la martiz
 */
SocketTCP::SocketTCP(bool connectionType,RectangleShape rects[88], int Mode)
{
    if (Mode == 1){


        string msg2 = "15.8.45.27.";
        string part;
        int cont2 = 0;
        /// GENERA LISTA DE OBSTACULOS
        for (int q = 0; q < msg2.length() ; q++){
            //cout << msg2[i] << endl;
            if (msg2[q]!='.'){
                part+=msg2[q];
                //cout << "No punto" << endl;
            } else {
                //cout << "QUE PASAAA " << endl;
                //this->obstacles[0] = 1;
                this->obstacles[cont2] = atoi(part.c_str());
                //cout << this->obstacles[cont2] << endl;
                part="";
                cont2 += 1;
            }

        }


        int k = 0;
        for (int i = 0;i<8;i++){

            for (int j=0;j<11;j++){

                this->matriz[i][j].z = 0;

                this->matriz[i][j].x = rects[k].getPosition().x;
                this->matriz[i][j].y = rects[k].getPosition().y;

                for (int w = 0; w<20; w++){
                    if (this->obstacles[w] == k){
                        cout << "k>>>>" << k << endl;
                        this->matriz[i][j].z = 1;
                    }
                }

                cout << this->matriz[i][j].x << " and " << this->matriz[i][j].y << " and " << this->matriz[i][j].z << endl;
                k++;
            }

        }

        //executeBacktracking(7,10);

        string text = "Connected to: ";
        string mode;

        if (connectionType==1){
            cout << "yes" << endl;
            TcpListener listener;
            listener.listen(8080);
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
        string  msgR = this->buffer;
        cout << msgR << endl;

        bool done = false;
        int cont = 0;
        cont2 = 0;
        /// GENERA LISTA DE OBSTACULOS
        for (int q = 0; q < msgR.length() ; q++){
            //cout << msg2[i] << endl;
            if (msgR[q]!='.'){
                part+=msgR[q];
                //cout << "No punto" << endl;
            } else {
                //cout << "QUE PASAAA " << endl;
                //this->obstacles[0] = 1;
                this->obstacles[cont2] = atoi(part.c_str());
                //cout << this->obstacles[cont2] << endl;
                part="";
                cont2 += 1;
            }

        }


        k = 0;
        for (int i = 0;i<8;i++){

            for (int j=0;j<11;j++){

                this->matriz[i][j].z = 0;

                this->matriz[i][j].x = rects[k].getPosition().x;
                this->matriz[i][j].y = rects[k].getPosition().y;

                for (int w = 0; w<20; w++){
                    if (this->obstacles[w] == k){
                        //cout << "k>>>>" << k << endl;
                        this->matriz[i][j].z = 1;
                    }
                }

                cout << this->matriz[i][j].x << " and " << this->matriz[i][j].y << " and " << this->matriz[i][j].z << endl;
                k++;
            }

        }
        //executeBacktracking(7,7);

        int cont3 = 0;
        int cont4 = 0;
        while(!done){
            //cout << "n" << endl;

            if(mode=="s"){

                if(1 == 1){                   //// CORREGIR AQUI
                    //getline(cin, text);
                    cout << " HE AHI EL ERROR " << endl;
                    if (this->Algoriythm==2){
                        text = "";
                        cout << "FALLO 2 " << cont3 << " Y " << cont4 << endl;
                        cout << this->posBacktracking.x << " A VER  " << this->posBacktracking.y;
                        executeBacktracking(cont3,cont4);
                        int v = 0;
                        for (int p = 0;p<8;p++){
                            for (int q = 0;q<11;q++){
                                if (this->solution[p][q] == 1){
                                    text+= to_string(v)+".";
                                }
                                v+=1;
                            }
                        }

                    }

                    this->socket.send(text.c_str(), text.length() + 1);
                    mode = "r";
                }



            } else if(mode=="r") {
                this->socket.receive(this->buffer, sizeof(this->buffer), this->received);
                if (received>0){
                    cout << "Received: " << this->buffer << endl;
                    string  msgR = this->buffer;

                    if (msgR == "mensaje"){
                        cout << "funciona" << endl;
                    }
                    mode = "s";


                    for (int q = 0; q < msgR.length() ; q++){
                        //cout << msg2[i] << endl;
                        if (msgR[q]!='.'){
                            if (q == 0){
                                string alg;
                                alg +=  msgR[q];
                                this->Algoriythm = atoi(alg.c_str());

                            } else {
                                part+=msgR[q];
                            }
                            //cout << "No punto" << endl;
                        } else {
                            if (q > 1 && q < 4){
                                this->posBacktracking.x = atoi(part.c_str());
                                cout << this->posBacktracking.x << " es el x " << endl;
                                cont3 = this->posBacktracking.x;
                            } else if (q >= 4 ){
                                this->posBacktracking.y = atoi(part.c_str());
                                cout << this->posBacktracking.y << " es el y " << endl;
                                cont4 = this->posBacktracking.y;
                                text="";

                                if(mode=="s" && this->Algoriythm == 2){
                                    //getline(cin, text);
                                    cout << "FALLO 2" << endl;
                                    this->matriz[cont3][cont4].z = 0;


                                    executeBacktracking(this->posBacktracking.x,this->posBacktracking.y);
                                    this->matriz[cont3][cont4].z = 1;
                                    int v = 0;
                                    for (int p = 0;p<8;p++){
                                        for (int q = 0;q<11;q++){

                                            if (this->solution[p][q] == 1){
                                                text+= to_string(v)+".";
                                            }
                                            v+=1;
                                        }
                                    }
                                    cout << "EL TEXTO ES " << text << endl;
                                    this->socket.send(text.c_str(), text.length() + 1);
                                    mode = "r";
                                }
                                break;
                            }
                            //cout << "QUE PASAAA " << endl;
                            //this->obstacles[0] = 1;
                            //this->obstacles[cont2] = atoi(part.c_str());
                            //cout << this->obstacles[cont2] << endl;
                            part="";
                            cont2 += 1;
                        }

                    }



                    //////


                    //////



                }
            }
        }
    }
}
