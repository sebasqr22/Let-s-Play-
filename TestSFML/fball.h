#ifndef FBALL_H
#define FBALL_H


class FBall
{
private:
    float Pos_x;
    float Pos_y;
public:
    FBall();
    void set_Position(float x, float y);
    float get_PositionX();
    float get_PositionY();
    void moveI();
    void moveII();
    void moveIII();
    void moveIV();

    void moveHV(int angle);

    void moveFast(int component, int quad);
};

#endif // FBALL_H
