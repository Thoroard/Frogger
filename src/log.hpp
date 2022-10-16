#pragma once
#include "object.hpp"

class Log:public Object {
public:
    FroggerBoard *board;
    Log(FroggerBoard &logBoard, int startH, int startW, int speed);
    void movement() override;
    void goBack() override;
private:
    int startH;
    int startW;
    int speed;
};


