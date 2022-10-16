#pragma once
#include "object.hpp"
#include "log.hpp"
#include <string>

class Frog: public Object{
public:
    FroggerBoard *board;
    explicit Frog(FroggerBoard &frogBoard);
    void movement() override;
    void goBack() override;
private:
    std::string moveDirection;
    std::string wDirection = "Podano zly kierunek wybierz ponownie";
    int startH = 9;
    int startW = 6;


};

