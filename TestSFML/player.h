#ifndef PLAYER_H
#define PLAYER_H


class Player
{
private:
    float Pos_x;
    float Pos_y;
public:
    Player();
    Player(float x, float y);
    void set_Position(float x, float y);
    float get_PositionX();
    float get_PositionY();
};

#endif // PLAYER_H
