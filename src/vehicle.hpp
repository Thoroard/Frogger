#pragma once
#include "object.hpp"

class Vehicle: public Object {
public:
    FroggerBoard *board;
    Vehicle(FroggerBoard &carBoard,int startH,int startW,int speed);
    void movement() override;
    void goBack() override;
private:
    int startH;
    int startW;
    int speed;
};
