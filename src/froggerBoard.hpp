#pragma once
#include <string>
#include <vector>
#include <iostream>

struct Place{
    bool hasFrog;
    bool hasCar;
    bool hasLog;
    bool isSafe;
    bool isRoad;
    bool isRiver;
};


class FroggerBoard{
protected:
    const int height = 10;
    const int width = 13;
public:
    int lives = 3;
    int ffw = 0;
    std::vector<std::vector<Place>>board;
    FroggerBoard();
    void display();
    void placeInfo(int h, int w);
    bool frogDies(int h, int w);
    int getHeight() const;
    int getWidth() const;
};


