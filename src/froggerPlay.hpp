#pragma once
#include "frog.hpp"
#include "vehicle.hpp"
#include "log.hpp"

class FroggerPlay {
private:
    FroggerBoard *board;
    std::vector<Object*>Objects;

public:
    explicit FroggerPlay(FroggerBoard &board);
    void play();
    void checkGame();
};


