#include "frog.hpp"

Frog::Frog(FroggerBoard &frogBoard):board(&frogBoard) {
    board->board[startH][startW].hasFrog = true;
}
void Frog::movement() {
    std::cout << std::endl << "Wcisnij przycisk aby sie poruszyc [W,A,S,D,X]:" << std::endl;
    std::cin >> moveDirection;
    
    if (moveDirection == "w" || moveDirection == "W"){
        board->board[startH][startW].hasFrog = false;
        startH--;
        board->board[startH ][startW].hasFrog = true;}

    else if (moveDirection == "s" || moveDirection == "S"){
        board->board[startH][startW].hasFrog = false;
        startH++;
        if (startH > ((board->getHeight())-1)){
            std::cout << std::endl <<"Tam nie da sie isc !";
            startH--;
            movement();}
        else
        board->board[startH][startW].hasFrog = true;}

    else if (moveDirection == "a" || moveDirection == "A"){
        board->board[startH][startW].hasFrog = false;
        startW = (startW - 1 + board->getWidth())%board->getWidth();
        board->board[startH][startW].hasFrog = true;}

    else if (moveDirection == "d" || moveDirection == "D"){
        board->board[startH][startW].hasFrog = false;
        startW = (startW + 1 + board->getWidth())%board->getWidth();
        board->board[startH][startW].hasFrog = true;}

    else if (moveDirection == "x" || moveDirection == "X") {
        board->board[startH][startW].hasFrog = true;
    }

    else {
        std::cout << wDirection;
        movement();}

}
void Frog::goBack() {
    board->board[startH][startW].hasFrog = false;
    startH = 9;
    startW = 6;
    board->board[startH][startW].hasFrog = true;
}
