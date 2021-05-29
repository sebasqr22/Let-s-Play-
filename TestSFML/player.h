#ifndef PLAYER_H
#define PLAYER_H


class Player
{
private:
    float Pos_x;
    float Pos_y;
    int team;
public:
    Player();
    Player(float x, float y);
    void set_Position(float x, float y);
    void set_Team(int team);
    float get_PositionX();
    float get_PositionY();
    int get_Team();
};

#endif // PLAYER_H
