#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <socketTCP.h>
using namespace std;
using namespace sf;


int main()
{
    //RenderWindow window(VideoMode(800, 560), "SFML tutorial : part 1",Style::Close | Style::Resize);

    RectangleShape rects[88];
    int i = 20, j = 7, l = 0, jump = 0;
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
        CircleShape teamPlayer(25.f);
        teamPlayer.setPosition(300.f,200.f);
        //teamPlayer.setFillColor(Color::Red);
        CircleShape Ball(25.f);
        //Ball.setFillColor(Color(22,34,677,255));



        RectangleShape player(Vector2f(100.f,150.f));
        //player.setFillColor(sf::Color::Blue);
        //player.setOrigin(50.0f,50.0f);
        RectangleShape backg(Vector2f(800.f,560.f));
        RectangleShape arrow(Vector2f(35.f,75.f));





        arrow.setPosition(100.f,100.f);
        //arrow.rotate(-90.f);
        //arrow.setOrigin(50.0f,50.0f);

        Sprite mySprite;


        Texture playerTexture;
        playerTexture.loadFromFile("Imags/Im1.jpeg");

        Texture teamTexture;
        teamTexture.loadFromFile("Imags/Barca1.png");

        Texture arrowTexture;
        arrowTexture.loadFromFile("Imags/flecha.png");

        Texture Background;
        Background.loadFromFile("Imags/Campo.png");

        Texture ballTexture;
        ballTexture.loadFromFile("Imags/bola.png");

        player.setTexture(&playerTexture);
        backg.setTexture(&Background);
        teamPlayer.setTexture(&teamTexture);
        arrow.setTexture(&arrowTexture);
        Ball.setTexture(&ballTexture);
        mySprite.setTexture(arrowTexture);


        // VARIABLES
        bool selected = false;

        // Main loop, while the window is open
        while (window.isOpen())
        {

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
                    if(teamPlayer.getGlobalBounds().contains(translated_pos)){


                        Ball.setPosition((float)mousePos.x+25,(float)mousePos.y);

                        arrow.setPosition((float)Ball.getPosition().x-40,(float)Ball.getPosition().y+10);
                        selected = true;
                        arrow.rotate(15.f);



                        ///////////////////////////////////////////// COMENTAR ESTO TAMBIEN PARA NO EJECUTAR LA CONEXION
                        //getline(cin, text);
                        text = " mensaje ";
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



            }

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

            window.display();
        }

        // End of application


    }
    return 0;

}
