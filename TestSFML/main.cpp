#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <socketTCP.h>
#include <fball.h>

using namespace std;
using namespace sf;


int main()
{
    //RenderWindow window(VideoMode(800, 560), "SFML tutorial : part 1",Style::Close | Style::Resize);

    RectangleShape rects[88];
    int i = 26, j = 7, l = 0, jump = 0;
    const sf::Color colorArray[9]={Color::Cyan, Color::Blue, Color::Green, Color::Red, Color::Yellow, Color::Black, Color::White, Color::Magenta, Color::Cyan };
    srand(time(NULL));
    for (l; l<sizeof(rects) / sizeof(rects[0]); l++){
        rects[l].setFillColor(colorArray[rand()%9]);
    }




    string mode;

    bool runMode = 0;
    if (runMode==1){

        SocketTCP sokket(runMode);

    } else {

        //socket.connect(ip, 8080);

        //SocketTCP sokket2(runMode);

        //string text;





        /////////////////////////////////// COMENTAR ESTO PARA NO EJECUTAR LA CONEXION //////////////
        TcpSocket socket;
        IpAddress ip = IpAddress::getLocalAddress();
        char buffer[2000];
        size_t received;

        string text = "Connected to: ";
        //string mode;
        socket.connect(ip,8000);
        text += "Client";
        mode = "r";
        socket.send(text.c_str(), text.length() + 1);
        socket.receive(buffer, sizeof(buffer), received);
        cout << buffer << endl;
        /////////////////////////////////// COMENTAR ESTO PARA NO EJECUTAR LA CONEXION //////////////









        // Create a new 200x200 pixels window with a title
        RenderWindow window(VideoMode(800, 560), "SFML tutorial : part 1",Style::Close | Style::Resize);
        //RenderWindow mainMenu(VideoMode(500, 350), "SFML tutorial : part 1",Style::Close);


        Time time;
        Clock clock;

        // Create a green circle with a radius of 100. pixels
        CircleShape teamPlayer(34.f);
        teamPlayer.setPosition(296.f,211.f);
        //teamPlayer.setFillColor(Color::Red);
        CircleShape Ball(25.f);
        //Ball.setFillColor(Color(22,34,677,255));



        RectangleShape player(Vector2f(100.f,150.f));
        //player.setFillColor(sf::Color::Blue);
        //player.setOrigin(50.0f,50.0f);
        RectangleShape backg(Vector2f(800.f,560.f));
        RectangleShape arrow(Vector2f(35.f,75.f));
        RectangleShape force(Vector2f(35,130));




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

        player.setTexture(&playerTexture);
        backg.setTexture(&Background);
        teamPlayer.setTexture(&teamTexture);
        arrow.setTexture(&arrowTexture);
        Ball.setTexture(&ballTexture);
        mySprite.setTexture(arrowTexture);
        force.setTexture(&forceTexture);

        // VARIABLES
        bool selected = false;
        int moving = 0;
        Vector2i T2mousePos;
        int counterM = 0;

        FBall fball;

        // Main loop, while the window is open
        while (window.isOpen())
        {
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
                    } else if(teamPlayer.getGlobalBounds().contains(translated_pos)){




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

            /////////////////////////////// MOVIMIENTO DE LA BOLA //////////////////////////////////////////
            if (moving% 90 == 0 && moving != 0){
                if (counterM!=300){
                    fball.moveHV(moving);
                    counterM+=1;
                } else {
                    moving = 0;
                    counterM=0;
                }
            } else if (moving == 4){
                if (counterM!=400){
                    fball.moveIV();
                    counterM+=1;
                } else {
                    moving = 0;
                    counterM=0;
                }
            } else if (moving == 3){
                if (counterM!=400){
                    fball.moveIII();
                    counterM+=1;
                } else {
                    moving = 0;
                    counterM=0;
                }
            } else if (moving == 2){
                if (counterM!=400){
                    fball.moveII();
                    counterM+=1;
                } else {
                    moving = 0;
                    counterM=0;
                }
            } else if (moving == 1){
                if (counterM!=400){
                    fball.moveI();
                    counterM+=1;
                } else {
                    moving = 0;
                    counterM=0;
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

            for (l;l<sizeof(rects) / sizeof(rects[0]);l++){
                rects[l].setSize(sf::Vector2f(67,67));
                rects[l].setPosition(i, j);
                window.draw(rects[l]);
                jump++;
                i += 68;
                if (jump==11){
                    j+=68;
                    i = 26;
                    jump=0;
                }
            }
            l=0;
            i = 26;
            j = 7;
            jump = 0;



            window.draw(teamPlayer);
            //window.draw(player);
            window.draw(arrow);
            window.draw(Ball);
            //window.draw(mySprite);
            window.draw(force);
            window.display();
        }

        // End of application


    }
    return 0;

}
