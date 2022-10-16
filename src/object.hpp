#pragma once
#include "froggerBoard.hpp"

class Object{
public:
virtual void movement() = 0;
virtual void goBack() = 0;
};
