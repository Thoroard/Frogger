#include "froggerBoard.hpp"
FroggerBoard::FroggerBoard() {

    //Generowanie Planszy
    for (int h=0; h<height;h++){
        board.emplace_back();
        for (int w=0; w<width; w++)
            board[h].emplace_back();
    }
    //Ustalenie typów pól rzeka, droga, pole bezpieczne
    for (int iw=0; iw<width; iw++) {
        board[9][iw].isSafe = true;
        board[8][iw].isRoad = true;
        board[7][iw].isRoad = true;
        board[6][iw].isRoad = true;
        board[5][iw].isSafe = true;
        board[4][iw].isRiver = true;
        board[3][iw].isRiver = true;
        board[2][iw].isRiver = true;
        board[1][iw].isSafe = true;
        board[0][iw].isSafe = true;
    }

}

void FroggerBoard::display() {
    std::cout << "Saved Frogs:" << ffw << "/3";
    std::cout << " Lives:" << lives << "/3";
    for (int h=0; h<height;h++){
        std::cout << std::endl;
        for (int w=0; w<width; w++)
            placeInfo(h,w);
    }
}

void FroggerBoard::placeInfo(int h, int w) {
    if (board[h][w].hasFrog)
        std::cout << "& ";
    else if (board[h][w].hasCar)
        std::cout << "* ";
    else if (board[h][w].hasLog)
        std::cout << "# ";
    else if (board[h][w].isSafe)
        std::cout << "^ ";
    else if (board[h][w].isRoad)
        std::cout << "- ";
    else if (board[h][w].isRiver)
        std::cout << "~ ";
}


bool FroggerBoard::frogDies(int h,int w) {
    if (board[h][w].hasFrog && (board[h][w].hasCar || (board[h][w].isRiver && !board[h][w].hasLog)))
        return true;
    else
        return false;
}

//Gettery
int FroggerBoard::getHeight() const {
    return height;
}
int FroggerBoard::getWidth() const {
    return width;
}
