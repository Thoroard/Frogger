#include "log.hpp"
Log::Log(FroggerBoard &carBoard, int startH, int startW,int speed):board (&carBoard),startH(startH),startW(startW),speed(speed) {
    board->board[startH][startW].hasLog = true;
}
void Log::movement() {
    board->board[startH][startW].hasLog = false;
    startW = (startW + speed + board->getWidth())%board->getWidth();
    board->board[startH][startW].hasLog = true;
}
void Log::goBack() {
    movement();
}
