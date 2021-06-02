/**
  *@file main.cpp
  * @title Main
  * @brief Clase que inicializa los principales elementos del juego
*/

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <socketTCP.h>
#include <fball.h>
#include <player.h>
#include <imagen.h>
#include <genetica.h>
#include <strength.h>

using namespace std;
using namespace sf;

int GenericPuzzle(){

    // Creación de la ventana
    RectangleShape GPBackG(Vector2f(850.f,650.f));

    Texture GPBackground;
    GPBackground.loadFromFile("Imags/Genetic.png");

    GPBackG.setTexture(&GPBackground);

    RenderWindow Window(sf::VideoMode(850, 650), "Genetic Puzzle ");

    Window.setKeyRepeatEnabled(false);



    String nameI;
    Text textimage;
    textimage.setString(nameI);
    textimage.setCharacterSize(20);
    textimage.setColor(Color::Black);
    textimage.setPosition(445.f,138.f);

    //Variable de Escritura
    bool writeNameI = true;

    //Object Imagen

    Imagen imag ;

    // Main loop, while the window is open
    while (Window.isOpen())
    {
        // Event loop
        Event event;
        while (Window.pollEvent(event))
        {
            switch (event.type)
            {
            case Event::TextEntered:
                if (writeNameI == true)
                {
                    if (event.text.unicode >= 32 && event.text.unicode <=126){
                    nameI += (char)event.text.unicode;
                }
                    else if (event.text.unicode == 8 && nameI.getSize() > 0)
                    {
                    nameI.erase(nameI.getSize() - 1, nameI.getSize());
                    }
                textimage.setString(nameI);
                break;
                }
            case Event::Closed:
                Window.close();
                break;
            case Event::MouseButtonPressed:
                cout << 1 << endl;
                Vector2i mousePos = Mouse::getPosition(Window);
                cout << mousePos.x << " " << mousePos.y << endl;
                if (mousePos.x > 441 &&  mousePos.x < 850 && mousePos.y > 121 && mousePos.y < 151)
                {
                    writeNameI = true;
                }
                else if (mousePos.x > 550 &&  mousePos.x < 742 && mousePos.y > 170  && mousePos.y < 205)
                {
                    writeNameI = false;
                    nameI = "/home/rachel10/GenericPuzzle/Imagen.jpg";
                    imag.ObtenerImagen(nameI);
                    //Cargar la imagen
                }
                else if (mousePos.x > 595 &&  mousePos.x < 681 && mousePos.y > 288 && mousePos.y < 334)
                {
                    writeNameI = false;
                    NULL;//Divivdir 4x4
                }
                else if (mousePos.x > 206 &&  mousePos.x < 293 && mousePos.y > 272 && mousePos.y < 308)
                {
                    writeNameI = false;
                    NULL;//Divivdir 4x2
                }
                else if (mousePos.x > 206 &&  mousePos.x < 293 && mousePos.y > 272 && mousePos.y < 308)
                {
                    writeNameI = false;
                    NULL;//Divivdir 4x6
                }
                else if (mousePos.x > 549 &&  mousePos.x < 739 && mousePos.y > 371 && mousePos.y < 411)
                {
                    writeNameI = false;
                    NULL;//Llamar al algoritmo
                }
                else
                {
                    writeNameI = false;
                    break;
                }
              }
        }


        Window.clear();
        Window.draw(GPBackG);
        Window.draw(textimage);
        Sprite imagen;
        imagen = imag.DibujarImagen();
        Window.draw(imagen);
        Window.display();
    }
    // End of application
    return 0;


}

/**
 * @brief BPGame Metodo que inicializa el juego
 * @param Splayers string de jugadores
 * @param Sgoal string del sgoal
 */
int BPGame(String Splayers, String Sgoal, int Mode)
{
    //RenderWindow window(VideoMode(800, 560), "SFML tutorial : part 1",Style::Close | Style::Resize);
    string splayers = Splayers;
    string sgoal = Sgoal;
    int players = atoi(splayers.c_str());
    int goal = atoi(sgoal.c_str());


    RectangleShape rects[88];
    bool notEmpty[88];
    int i = 26, j = 7, l = 0, jump = 0;
    const sf::Color colorArray[9]={Color::Cyan, Color::Blue, Color::Green, Color::Red, Color::Yellow, Color::Black, Color::White, Color::Magenta, Color::Cyan };
    srand(time(NULL));

    for (l; l<sizeof(rects) / sizeof(rects[0]); l++){
        rects[l].setSize(sf::Vector2f(67,67));
        rects[l].setFillColor(colorArray[rand()%9]);
        rects[l].setPosition(i, j);
        i += 68;
        jump++;
        if (jump==11){
            j+=68;
            i = 26;
            jump=0;
        }

    }



    // 26
    //

    /// TEAMS ///
    float randomX[11] = {26,94,162,230,298,366,434,502,570,638,706};
    float randomX1[4] = {94,162,230,298};
    float randomX2[4] = {434,502,570,638};
    float randomY[9] = {7,75,143,211,279,347,415,483,279};

    CircleShape circles[players];
    Texture team1Texture;
    team1Texture.loadFromFile("Imags/playerBlue.png");
    Texture team2Texture;
    team2Texture.loadFromFile("Imags/playerRed.png");
    for (int k = 0; k<players; k++)
    {
        circles[k].setRadius(34.f);
        if (k < players/2){

            circles[k].setTexture(&team1Texture);
        } else {
            circles[k].setTexture(&team2Texture);;
        }
    }

    Player totalPlayers[players];
    for (int k = 0; k<players; k++)
    {
        if (k < players/2) {
            totalPlayers[k].set_Team(1);
            if ( k==0 || k%2==0 ) {
                totalPlayers[k].set_Position(randomX1[rand()%4],randomY[rand()%9]);

                circles[k].setPosition(totalPlayers[k].get_PositionX(),totalPlayers[k].get_PositionY());
            } else {
                totalPlayers[k].set_Position(randomX2[rand()%4],randomY[rand()%9]);

                circles[k].setPosition(totalPlayers[k].get_PositionX(),totalPlayers[k].get_PositionY());
            }

        } else if (k >= players/2) {
            totalPlayers[k].set_Team(2);
            if ( k==0 || k%2==0 ) {
                totalPlayers[k].set_Position(randomX1[rand()%4],randomY[rand()%9]);

                circles[k].setPosition(totalPlayers[k].get_PositionX(),totalPlayers[k].get_PositionY());
            } else {
                totalPlayers[k].set_Position(randomX2[rand()%4],randomY[rand()%9]);

                circles[k].setPosition(totalPlayers[k].get_PositionX(),totalPlayers[k].get_PositionY());
            }

        }

    }


    /// TEAMS ///


    string mode;

    bool runMode = 0;
    if (runMode==1){

        SocketTCP sokket(runMode, rects, Mode);

    } else {

        //socket.connect(ip, 8080);

        //SocketTCP sokket2(runMode);

        //string text;





        /////////////////////////////////// COMENTAR ESTO PARA NO EJECUTAR LA CONEXION //////////////
        TcpSocket socket;
        IpAddress ip = IpAddress::getLocalAddress();
        char buffer[2000];
        size_t received;

        string text;// = "Connected to: ";
        //string mode;
        socket.connect(ip,8080);
        //text += "Client";
        mode = "r";



        text = "";

        for (int i = 0; i<88; i++){

            for (int j = 0; j<players; j++){
                if (circles[j].getPosition() == rects[i].getPosition()){
                    notEmpty[i] = 1;
                    cout << "Obstacle :" << notEmpty[i] << endl;
                    string s = to_string(i)+".";
                    text+=s;
                }
            }
        }
        socket.send(text.c_str(), text.length() + 1);
        socket.receive(buffer, sizeof(buffer), received);
        cout << buffer << endl;
        cout << text << endl;
        /////////////////////////////////// COMENTAR ESTO PARA NO EJECUTAR LA CONEXION //////////////









        // Create a new 200x200 pixels window with a title
        RenderWindow window(VideoMode(800, 620), "Let's Play",Style::Close | Style::Resize);
        //RenderWindow mainMenu(VideoMode(500, 350), "SFML tutorial : part 1",Style::Close);


        Time time;
        Clock clock;


        FBall fball;
        // Create a green circle with a radius of 100. pixels
        CircleShape teamPlayer(34.f);

        teamPlayer.setPosition(circles[0].getPosition());
        //teamPlayer.setFillColor(Color::Red);
        CircleShape Ball(25.f);
        //Ball.setFillColor(Color(22,34,677,255));

        fball.set_Position((float)teamPlayer.getPosition().x+9,(float)teamPlayer.getPosition().y+9); // 9 = 34 - 25

        Ball.setPosition(fball.get_PositionX(),fball.get_PositionY());


        RectangleShape player(Vector2f(100.f,150.f));
        //player.setFillColor(sf::Color::Blue);
        //player.setOrigin(50.0f,50.0f);
        RectangleShape backg(Vector2f(800.f,560.f));
        RectangleShape arrow(Vector2f(35.f,75.f));
        RectangleShape force(Vector2f(35,130));
        force.setPosition(170,573);
        force.setRotation(90);
        Strength strengthBar;
        strengthBar.set_Value(3);



        arrow.setPosition(100.f,100.f);
        //arrow.rotate(-90.f);
        //arrow.setOrigin(50.0f,50.0f);

        Sprite mySprite;


        Texture playerTexture;
        playerTexture.loadFromFile("Imags/Im1.jpeg");

        Texture teamTexture;
        teamTexture.loadFromFile("Imags/playerBlue.png");

        Texture arrowTexture;
        arrowTexture.loadFromFile("Imags/flecha.png");

        Texture Background;
        Background.loadFromFile("Imags/Campo.png");

        Texture ballTexture;
        ballTexture.loadFromFile("Imags/bola.png");

        Texture forceTexture;
        forceTexture.loadFromFile("Imags/fuerza3.png");
        Texture forceTexture2;
        forceTexture2.loadFromFile("Imags/fuerza2.png");
        Texture forceTexture3;
        forceTexture3.loadFromFile("Imags/fuerza.png");



        player.setTexture(&playerTexture);
        backg.setTexture(&Background);
        teamPlayer.setTexture(&teamTexture);
        arrow.setTexture(&arrowTexture);
        Ball.setTexture(&ballTexture);
        mySprite.setTexture(arrowTexture);
        force.setTexture(&forceTexture3);

        Font font;
        font.loadFromFile("Fonts/ThanksBunnyFree.ttf");
        String sTurn = " Player 1's turn ";
        Text textTurn(sTurn,font,36);
        textTurn.setColor(Color::Blue);
        textTurn.setPosition(550.f,565.f);

        String sP1Score = "P1 ";
        Text textP1Score(sP1Score,font,36);
        textP1Score.setColor(Color::Blue);
        textP1Score.setPosition(275.f,565.f);

        String sP2Score = "P2 ";
        Text textP2Score(sP2Score,font,36);
        textP2Score.setColor(Color::Red);
        textP2Score.setPosition(375.f,565.f);


        // VARIABLES
        bool selected = false;
        int moving = 0;
        Vector2i T2mousePos;
        int counterM = 0;
        bool wall = false;
        int turn = 1;

        int P1Score = 0;
        int P2Score = 0;
        bool BackT = false;
        string messageR;
        int path[50];

        // Main loop, while the window is open
        while (window.isOpen())
        {
            sP1Score = "P1 "+to_string(P1Score);
            textP1Score.setString(sP1Score);

            sP2Score = "P2 "+to_string(P2Score);
            textP2Score.setString(sP2Score);


            Ball.setPosition(fball.get_PositionX(),fball.get_PositionY());

            // Event loop
            Event event;
            while (window.pollEvent(event))
            {


                //window.setKeyRepeatEnabled(false);
                switch (event.type)
                {
                case Event::Closed:
                    window.close();
                    break;
                case Event::Resized:
                    cout << event.size.width << " " << event.size.height << endl;
                case Event::TextEntered:
                    cout << (char)event.text.unicode << endl;
                    break;

                case Event::MouseButtonPressed:
                    cout << turn << endl;
                    cout << 1 << endl;
                    time = clock.getElapsedTime();
                    cout << time.asSeconds() << endl;
                    clock.restart();

                    Vector2i mousePos = Mouse::getPosition(window);

                    cout << mousePos.x << " " << mousePos.y << endl;

                    //if (selected == true){

                    //}

                    auto translated_pos = window.mapPixelToCoords(mousePos); // Mouse position translated into world coordinates
                    if (selected==true){
                        BackT = false;
                        switch((int)arrow.getRotation()){
                            case 0:
                                selected = false;
                                T2mousePos = Mouse::getPosition(window);
                                moving = 360;
                                break;
                            case 90:
                                selected = false;
                                T2mousePos = Mouse::getPosition(window);
                                moving = 90;
                                break;
                            case 180:
                                selected = false;
                                T2mousePos = Mouse::getPosition(window);
                                moving = 180;
                                break;
                            case 270:
                                selected = false;
                                T2mousePos = Mouse::getPosition(window);
                                moving = 270;
                                break;

                            case 315:
                                selected = false;
                                T2mousePos = Mouse::getPosition(window);
                                moving = 4;
                                break;
                            case 45:
                                selected = false;
                                T2mousePos = Mouse::getPosition(window);
                                moving = 3;
                                break;
                            case 135:
                                selected = false;
                                T2mousePos = Mouse::getPosition(window);
                                moving = 2;
                                break;
                            case 225:
                                selected = false;
                                T2mousePos = Mouse::getPosition(window);
                                moving = 1;
                                break;
                        }

                    } else if(mousePos.x > 43 && mousePos.x < 83 && mousePos.y > 574 && mousePos.y < 608){
                        strengthBar.set_Value(1);
                        force.setTexture(&forceTexture);
                    } else if(mousePos.x > 83 && mousePos.x < 123 && mousePos.y > 574 && mousePos.y < 608){
                        strengthBar.set_Value(2);
                        force.setTexture(&forceTexture2);
                    } else if(mousePos.x > 123 && mousePos.x < 168 && mousePos.y > 574 && mousePos.y < 608){
                        strengthBar.set_Value(3);
                        force.setTexture(&forceTexture3);

                    } else if(teamPlayer.getGlobalBounds().contains(translated_pos)){

                        if (turn%2 == 1){

                            fball.set_Position((float)teamPlayer.getPosition().x+9,(float)teamPlayer.getPosition().y+9); // 9 = 34 - 25

                            Ball.setPosition(fball.get_PositionX(),fball.get_PositionY());


                            arrow.setPosition((float)teamPlayer.getPosition().x+34,(float)teamPlayer.getPosition().y+34);

                            selected = true;
                            //arrow.rotate(45.f);



                            ///////////////////////////////////////////// COMENTAR ESTO TAMBIEN PARA NO EJECUTAR LA CONEXION
                            //getline(cin, text);
                            text = "mensaje";
                            socket.send(text.c_str(), text.length() + 1);
                            mode = "r";
                            if(mode=="r") {
                                socket.receive(buffer, sizeof(buffer), received);
                                if (received>0){
                                    cout << "Received: " << buffer << endl;
                                    mode = "s";
                                }
                            }
                            /////////////////////////////////////////////////////////////////////////////////////////////////

                        } else {
                            fball.set_Position((float)teamPlayer.getPosition().x+9,(float)teamPlayer.getPosition().y+9); // 9 = 34 - 25
                            Ball.setPosition(fball.get_PositionX(),fball.get_PositionY());
                            arrow.setPosition((float)teamPlayer.getPosition().x+34,(float)teamPlayer.getPosition().y+34);

                            int rc = 0;

                            for (int r = 0;r<8;r++){
                                cout << "QUE SUCEDE " << endl;
                                for (int c = 0;c<11;c++){
                                    cout << c << endl;
                                    if (teamPlayer.getPosition() == rects[rc].getPosition()){
                                        cout << r << " es r y " << c << " es c " << endl;
                                        text = "2."+to_string(r)+"."+to_string(c)+".";
                                    }

                                    rc+=1;
                                }

                            }



                            socket.send(text.c_str(), text.length() + 1);
                            mode = "r";
                            if(mode=="r") {
                                socket.receive(buffer, sizeof(buffer), received);
                                messageR = buffer;
                                if (received>0 and messageR != "Connected to: Server"){
                                    cout << "Received: " << buffer << endl;
                                    BackT = true;

                                    mode = "s";
                                } else {
                                    while(messageR == "Connected to: Server"){
                                        socket.receive(buffer, sizeof(buffer), received);
                                        messageR = buffer;
                                        BackT = true;

                                        mode = "s";
                                    }
                                }
                            }



                        }
                    }


                    //player.setPosition((float)mousePos.x-100,(float)mousePos.y);
                    //player.rotate(10.f);
                    cout << arrow.getPosition().x << " andddd " << arrow.getPosition().y << endl;
                    if (arrow.getRotation()<90 || arrow.getRotation()>270){
                        cout << "-y" << endl;
                    }
                    //cout << arrow.getRotation() << endl;

                }

            }



            switch (strengthBar.get_Value()) {
            case 1:
                strengthBar.set_Pxls(150);

                break;
            case 2:
                strengthBar.set_Pxls(300);
                break;
            case 3:
                strengthBar.set_Pxls(450);
                break;
            }

            if (selected == true){
                Vector2i TmousePos = Mouse::getPosition(window);
                if (TmousePos.x > arrow.getPosition().x-34 && TmousePos.x < arrow.getPosition().x+34 && TmousePos.y > arrow.getPosition().y){
                    arrow.setRotation(0);

                }else if(TmousePos.x > arrow.getPosition().x-34 && TmousePos.x < arrow.getPosition().x+34 && TmousePos.y < arrow.getPosition().y){
                    arrow.setRotation(180);
                }else if(TmousePos.y > arrow.getPosition().y-34 && TmousePos.y < arrow.getPosition().y+34 && TmousePos.x < arrow.getPosition().x){
                    arrow.setRotation(90);
                }else if(TmousePos.y > arrow.getPosition().y-34 && TmousePos.y < arrow.getPosition().y+34 && TmousePos.x > arrow.getPosition().x){
                    arrow.setRotation(270);
                }else if(TmousePos.x > arrow.getPosition().x && TmousePos.y > arrow.getPosition().y){
                    arrow.setRotation(315);
                } else if(TmousePos.x < arrow.getPosition().x && TmousePos.y > arrow.getPosition().y){
                    arrow.setRotation(45);
                } else if(TmousePos.x < arrow.getPosition().x && TmousePos.y < arrow.getPosition().y){
                    arrow.setRotation(135);
                } else if(TmousePos.x > arrow.getPosition().x && TmousePos.y < arrow.getPosition().y){
                    arrow.setRotation(225);
                }

            }
            //cout << turn << endl;
            //cout << wall << endl;
            /////////////////////////////// MOVIMIENTO DE LA BOLA //////////////////////////////////////////


            if (moving == 0 && turn%2==0){  // CAMBIAR EQUIPOOOO
                for (int f=0;f<players;f++){
                    if (fball.get_PositionX()>=totalPlayers[f].get_PositionX()-68-32 && fball.get_PositionX()<totalPlayers[f].get_PositionX()+68+32 && fball.get_PositionY()>=totalPlayers[f].get_PositionY()-68-32 && fball.get_PositionY()<totalPlayers[f].get_PositionY()+68+32 && totalPlayers[f].get_Team() == 2){
                        fball.set_Position(totalPlayers[f].get_PositionX()+9,totalPlayers[f].get_PositionY()+9);
                        teamPlayer.setPosition(totalPlayers[f].get_PositionX(),totalPlayers[f].get_PositionY());
                        teamPlayer.setTexture(&team2Texture);

                        sTurn = "Player 2's turn";
                        textTurn.setString(sTurn);
                        textTurn.setColor(Color::Red);

                    }

                }
                //turn+=1;
            }

            if (moving == 0 && turn%2==1){  // CAMBIAR EQUIPOOOO
                for (int f=0;f<players;f++){
                    if (fball.get_PositionX()>=totalPlayers[f].get_PositionX()-68-32 && fball.get_PositionX()<totalPlayers[f].get_PositionX()+68+32 && fball.get_PositionY()>=totalPlayers[f].get_PositionY()-68-32 && fball.get_PositionY()<totalPlayers[f].get_PositionY()+68+32 && totalPlayers[f].get_Team() == 1){
                        fball.set_Position(totalPlayers[f].get_PositionX()+9,totalPlayers[f].get_PositionY()+9);
                        teamPlayer.setPosition(totalPlayers[f].get_PositionX(),totalPlayers[f].get_PositionY());
                        teamPlayer.setTexture(&team1Texture);

                        sTurn = "Player 1's turn";
                        textTurn.setString(sTurn);
                        textTurn.setColor(Color::Blue);
                    }

                }
                //turn+=1;
            }
            //cout << moving << endl;
            /*
            if (fball.get_PositionY()>211 && fball.get_PositionY()<347 && fball.get_PositionX()<27){
                turn = 2;
                P2Score+=1;
                moving = 0;
                /*
                for (int z=0;z<players;z++){
                    if (totalPlayers[z].get_Team() == 1){
                        fball.set_Position(totalPlayers[z].get_PositionX()+9,totalPlayers[z].get_PositionY()+9);
                        teamPlayer.setPosition(totalPlayers[z].get_PositionX(),totalPlayers[z].get_PositionY());
                        //teamPlayer.setTexture(&team2Texture);
                        //turn+=1;
                        //moving = 15;
                        break;

                    }

                }

            }
            if (fball.get_PositionY()>211 && fball.get_PositionY()<347 && fball.get_PositionX()>726){
                turn = 1;
                P1Score+=1;
                moving = 0;


                for (int z=0;z<players;z++){
                    if (totalPlayers[z].get_Team() == 2){
                        fball.set_Position(totalPlayers[z].get_PositionX()+9,totalPlayers[z].get_PositionY()+9);
                        teamPlayer.setPosition(totalPlayers[z].get_PositionX(),totalPlayers[z].get_PositionY());
                        //teamPlayer.setTexture(&team2Texture);
                        //turn+=1;
                        //moving = 15;
                        break;

                    }

                }
            }*/


            if (wall == true && moving<5){

                if (moving == 2){
                    if (fball.get_PositionY()<=4.f){
                        fball.set_Position(fball.get_PositionX(),fball.get_PositionY()+1);
                        moving = 3;
                    } else if (fball.get_PositionX()<=25.f){
                        fball.set_Position(fball.get_PositionX()+1,fball.get_PositionY());
                        moving = 1;
                    }

                } else if (moving == 3){
                    if (fball.get_PositionY()>=505.f){
                        fball.set_Position(fball.get_PositionX(),fball.get_PositionY()-1);
                        moving = 2;
                    } else if (fball.get_PositionX()<=25.f){
                        fball.set_Position(fball.get_PositionX()+1,fball.get_PositionY());
                        moving = 4;
                    }

                } else if (moving == 1){
                    if (fball.get_PositionY()<=4.f){
                        fball.set_Position(fball.get_PositionX(),fball.get_PositionY()+1);
                        moving = 4;
                    } else if (fball.get_PositionX()>=727.f){
                        fball.set_Position(fball.get_PositionX()-1,fball.get_PositionY());
                        moving = 2;
                    }

                } else if (moving == 4){
                    if (fball.get_PositionY()>=505.f){
                        fball.set_Position(fball.get_PositionX(),fball.get_PositionY()-1);
                        moving = 1;
                    } else if (fball.get_PositionX()>=727.f){
                        fball.set_Position(fball.get_PositionX()-1,fball.get_PositionY());
                        moving = 3;
                    }
                }

                wall = false;

            } else if (moving% 90 == 0 && moving != 0){
                for (int a = 0; a<players; a++){

                    if (fball.get_PositionX()+34>=circles[a].getPosition().x && fball.get_PositionX()+34<circles[a].getPosition().x+67 && fball.get_PositionY()+34>=circles[a].getPosition().y && fball.get_PositionY()+34<circles[a].getPosition().y+67 && counterM>80){
                        cout << "COLISION" << endl;
                        moving = 0;
                        counterM = 0;
                        turn+=1;

                    }

                }
                if (counterM!=strengthBar.get_Pxls()-50){
                    if (wall==true){
                        if (moving == 180){
                            fball.moveHV(360);
                        } else if (moving == 360){
                            fball.moveHV(180);
                        } else if (moving == 90){
                            fball.moveHV(270);
                        } else if (moving == 270){
                            fball.moveHV(90);
                        }
                        counterM+=1;


                    } else if (fball.get_PositionY()<=4.f || fball.get_PositionY()>=505.f || fball.get_PositionX()<=25.f || fball.get_PositionX()>=727.f){
                        wall = true;

                    } else {
                        fball.moveHV(moving);
                        counterM+=1;
                    }

                } else {
                    moving = 0;
                    counterM=0;
                    wall = false;
                    turn+=1;
                }
            //// CUARTO
            } else if (moving == 4){

                if (counterM!=strengthBar.get_Pxls()+50){
                    for (int a = 0; a<players; a++){
                        if (fball.get_PositionX()+34>=circles[a].getPosition().x && fball.get_PositionX()+34<circles[a].getPosition().x+67 && fball.get_PositionY()+34>=circles[a].getPosition().y && fball.get_PositionY()+34<circles[a].getPosition().y+67 && counterM>120){
                            cout << "COLISION" << endl;
                            moving = 0;
                            counterM = 0;
                            turn+=1;

                        }

                    }
                    if (fball.get_PositionY()<=4.f || fball.get_PositionY()>=505.f || fball.get_PositionX()<=25.f || fball.get_PositionX()>=727.f){

                        wall = true;
                    } else {
                        fball.moveIV();
                        counterM+=1;
                    }
                } else {
                    moving = 0;
                    counterM=0;
                    turn+=1;


                }
            //// TERCER
            } else if (moving == 3){
                if (counterM!=strengthBar.get_Pxls()+50){
                    for (int a = 0; a<players; a++){
                        if (fball.get_PositionX()+34>=circles[a].getPosition().x && fball.get_PositionX()+34<circles[a].getPosition().x+67 && fball.get_PositionY()+34>=circles[a].getPosition().y && fball.get_PositionY()+34<circles[a].getPosition().y+67 && counterM>120){
                            cout << "COLISION" << endl;
                            moving = 0;
                            counterM = 0;
                            turn+=1;

                        }

                    }
                    if (fball.get_PositionY()<=4.f || fball.get_PositionY()>=505.f || fball.get_PositionX()<=25.f || fball.get_PositionX()>=727.f){

                        wall = true;
                    } else {
                        fball.moveIII();
                        counterM+=1;
                    }
                } else {
                    moving = 0;
                    counterM=0;
                    turn+=1;

                }
            //// SEGUNDO
            } else if (moving == 2){
                if (counterM!=strengthBar.get_Pxls()+50){
                    for (int a = 0; a<players; a++){
                        if (fball.get_PositionX()+34>=circles[a].getPosition().x && fball.get_PositionX()+34<circles[a].getPosition().x+67 && fball.get_PositionY()+34>=circles[a].getPosition().y && fball.get_PositionY()+34<circles[a].getPosition().y+67 && counterM>120){
                            cout << "COLISION" << endl;
                            moving = 0;
                            counterM = 0;
                            turn+=1;

                        }

                    }

                    if (fball.get_PositionY()<=4.f || fball.get_PositionY()>=505.f || fball.get_PositionX()<=25.f || fball.get_PositionX()>=727.f){
                        wall = true;
                    } else {
                        fball.moveII();
                        counterM+=1;
                    }
                } else {
                    moving = 0;
                    counterM=0;
                    turn+=1;

                }
            //// PRIMER
            } else if (moving == 1){
                if (counterM!=strengthBar.get_Pxls()+50){
                    for (int a = 0; a<players; a++){

                        if (fball.get_PositionX()+34>=circles[a].getPosition().x && fball.get_PositionX()+34<circles[a].getPosition().x+67 && fball.get_PositionY()+34>=circles[a].getPosition().y && fball.get_PositionY()+34<circles[a].getPosition().y+67 && counterM>120){
                            cout << "COLISION" << endl;
                            moving = 0;
                            counterM = 0;
                            turn+=1;

                        }

                    }
                    if (fball.get_PositionY()<=4.f || fball.get_PositionY()>=505.f || fball.get_PositionX()<=25.f || fball.get_PositionX()>=727.f){

                        wall = true;
                    } else {
                        fball.moveI();
                        counterM+=1;
                    }
                } else {
                    moving = 0;
                    counterM=0;
                    turn+=1;

                }
            }




            ////////////////////////////////////////////////////////////////////////////////////////////////



            /*
            if(mode=="r") {
                socket.receive(buffer, sizeof(buffer), received);
                if (received>0){
                    cout << "Received: " << buffer << endl;
                    mode = "s";
                }
            }*/


            if (Keyboard::isKeyPressed(Keyboard::Key::A)){
                player.move(-0.1,0.0);
            }
            if (Keyboard::isKeyPressed(Keyboard::Key::D)){
                player.move(0.1,0.0);
            }
            if (Keyboard::isKeyPressed(Keyboard::Key::S)){
                player.move(0.0,0.1);
            }
            if (Keyboard::isKeyPressed(Keyboard::Key::W)){
                player.move(0.0,-0.1);
            }
            /*
            if (Mouse::isButtonPressed(Mouse::Left)){
                Vector2i mousePos = Mouse::getPosition(window);
                cout << mousePos.x << " " << mousePos.y << endl;

                auto translated_pos = window.mapPixelToCoords(mousePos); // Mouse position translated into world coordinates
                if(teamPlayer.getGlobalBounds().contains(translated_pos)){
                    cout << "yeaahhhh" << endl;
                }


                player.setPosition((float)mousePos.x-100,(float)mousePos.y);
            }*/

            // Display sequence : clear screen, draw circle and update display


            /*
            if(mode=="s"){
                getline(cin, text);
                sokket2.socket.send(text.c_str(), text.length() + 1);

                mode = "r";
            } else if(mode=="r") {
                sokket2.socket.receive(sokket2.buffer, sizeof(sokket2.buffer), sokket2.received);
                if (sokket2.received > 0){
                    cout << "Received: " << sokket2.buffer << endl;
                    mode = "s";
                }
                mode = "s";
            }*/

            window.clear();
            window.draw(backg);

            for (l=0;l<sizeof(rects) / sizeof(rects[0]);l++){
                //rects[l].setFillColor(colorArray[rand()%9]);
                //if (rects[l].getPosition().y != 211 && rects[l].getPosition().x != 26 && rects[l].getPosition().y != 279){
                //window.draw(rects[l]);
                //}
            }

            if (BackT == true){
                int cont2 = 0;
                string part;
                /// GENERA LISTA DE OBSTACULOS
                for (int q = 0; q < messageR.length() ; q++){
                    //cout << msg2[i] << endl;
                    if (messageR[q]!='.'){
                        part+=messageR[q];
                        //cout << "No punto" << endl;
                    } else {
                        //cout << "QUE PASAAA " << endl;
                        //this->obstacles[0] = 1;
                        path[cont2] = atoi(part.c_str());
                        //cout << this->obstacles[cont2] << endl;
                        part="";
                        cont2 += 1;
                    }

                }
                for (int y = 0;y<50;y++){
                    for (int u = 0; u<88; u++){
                        if (path[y] != 0 && path[y]==u){
                            rects[u].setFillColor(Color::Black);
                            window.draw(rects[u]);
                        }
                    }

                }
                if (fball.get_PositionY()>211 && fball.get_PositionY()<347){
                    arrow.setRotation(90);
                    selected = true;
                } else if (fball.get_PositionY()<211){
                    arrow.setRotation(45);
                    selected = true;
                } else if (fball.get_PositionY()>347){
                    arrow.setRotation(135);
                    selected = true;
                }

            }



            for (int k = 0; k<players; k++)
            {
               window.draw(circles[k]);

            }



            window.draw(teamPlayer);
            //window.draw(player);
            window.draw(arrow);
            window.draw(Ball);
            //window.draw(mySprite);
            window.draw(force);
            window.draw(textTurn);
            window.draw(textP1Score);
            window.draw(textP2Score);
            window.display();
        }

        // End of application


    }
    return 0;

}
/**
 * @brief BPselectionMenu Metodo que crea el menu de seleccion
 */
int BPselectionMenu(int Mode){

    RectangleShape menuBackg(Vector2f(500.f,400.f));

    Texture menuBackground;
    menuBackground.loadFromFile("Imags/bpMenu.png");

    menuBackg.setTexture(&menuBackground);


    RenderWindow mainMenu(VideoMode(500, 400), "Let's Play MENU",Style::Close | Style::Resize);

    Font font;
    if (font.loadFromFile("Fonts/ThanksBunnyFree.ttf")){
        cout << "Font loaded" << endl;
    }
    String players;
    Text textPlayers(players,font,30);
    textPlayers.setColor(Color::Black);
    textPlayers.setPosition(232.f,174.f);

    String goal;
    Text textGoal(goal,font,30);
    textGoal.setColor(Color::Black);
    textGoal.setPosition(232.f,221.f);

    /// VARIABLES ///
    bool write1 = false;
    bool write2 = false;

    while (mainMenu.isOpen())
    {

        // Event loop
        Event event;
        while (mainMenu.pollEvent(event))
        {
            //window.setKeyRepeatEnabled(false);
            switch (event.type)
            {
            case Event::TextEntered:
                if (write1 == true){

                    if (event.text.unicode >= 32 && event.text.unicode <=126){
                        players += (char)event.text.unicode;
                    } else if (event.text.unicode == 8 && players.getSize() > 0){
                        players.erase(players.getSize() - 1, players.getSize());
                    }
                    textPlayers.setString(players);
                    break;

                } else if (write2 == true){

                    if (event.text.unicode >= 32 && event.text.unicode <=126){
                        goal += (char)event.text.unicode;
                    } else if (event.text.unicode == 8 && goal.getSize() > 0){
                        goal.erase(goal.getSize() - 1, goal.getSize());
                    }
                    textGoal.setString(goal);
                    break;
                }


            case Event::Closed:
                mainMenu.close();
                break;
            case Event::MouseButtonPressed:
                string splayers = players;
                cout << 1 << endl;

                Vector2i mousePos = Mouse::getPosition(mainMenu);

                cout << mousePos.x << " " << mousePos.y << endl;
                if (mousePos.x > 206 &&  mousePos.x < 293 && mousePos.y > 176 && mousePos.y < 209){
                    write1 = true;
                    write2 = false;
                } else if (mousePos.x > 206 &&  mousePos.x < 293 && mousePos.y > 223 && mousePos.y < 258){
                    write2 = true;
                    write1 = false;

                } else if (mousePos.x > 206 &&  mousePos.x < 293 && mousePos.y > 272 && mousePos.y < 308 && atoi(splayers.c_str()) <= 20 && atoi(splayers.c_str())%2==0){
                    write2 = true;
                    write1 = false;
                    mainMenu.close();
                    return BPGame(players, goal, 1);

                } else {
                    write1 = false;
                    write2 = false;
                }
                break;

            }

        }

        mainMenu.clear();
        mainMenu.draw(menuBackg);
        mainMenu.draw(textPlayers);
        mainMenu.draw(textGoal);
        mainMenu.display();
    }

}
/**
 * @brief main Inicializa los principales parametros
 * @return
 */
int main(){

    RectangleShape menuBackg(Vector2f(570.f,400.f));

    Texture menuBackground;
    menuBackground.loadFromFile("Imags/mainMenu.png");

    menuBackg.setTexture(&menuBackground);


    RenderWindow mainMenu(VideoMode(570, 400), "Let's Play MENU",Style::Close | Style::Resize);
    while (mainMenu.isOpen())
    {

        // Event loop
        Event event;
        while (mainMenu.pollEvent(event))
        {
            //window.setKeyRepeatEnabled(false);
            switch (event.type)
            {
            case Event::Closed:
                mainMenu.close();
                break;
            case Event::MouseButtonPressed:
                cout << 1 << endl;

                Vector2i mousePos = Mouse::getPosition(mainMenu);

                //cout << mousePos.x << " " << mousePos.y << endl;
                if (mousePos.x > 372 &&  mousePos.x < 500 && mousePos.y > 90 && mousePos.y < 170){
                    mainMenu.close();
                    return BPselectionMenu(1);
                }
            }
        }

        mainMenu.clear();
        mainMenu.draw(menuBackg);
        mainMenu.display();
    }

}
