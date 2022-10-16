#include "vehicle.hpp"

Vehicle::Vehicle(FroggerBoard &carBoard, int startH, int startW,int speed):board (&carBoard),startH(startH),startW(startW),speed(speed) {
    board->board[startH][startW].hasCar = true;
}
void Vehicle::movement() {
    board->board[startH][startW].hasCar = false;
    startW = (startW + speed + board->getWidth())%board->getWidth();
    board->board[startH][startW].hasCar = true;

}
void Vehicle::goBack() {
    movement();
}
