#ifndef STRENGTH_H
#define STRENGTH_H
#include <iostream>
using namespace std;

class Strength
{
private:
    int value;
    string img;

public:
    Strength();
    void set_Value(int value);
    void updateImg(int value);
    void set_Img(string msg);
    //int set_Value(int value);
    //void updateImg(int value);
    //void set_Img(string msg);
};

#endif // STRENGTH_H
