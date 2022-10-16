#include "froggerPlay.hpp"
#include <cstdlib>

FroggerPlay::FroggerPlay(FroggerBoard &board):board (&board) {
    Objects.push_back(new Frog(board));

    Objects.push_back(new Vehicle(board,8,11,1));
    Objects.push_back(new Vehicle(board,8,6,1));
    Objects.push_back(new Vehicle(board,8,2,1));

    Objects.push_back(new Vehicle(board,7,10,-1));
    Objects.push_back(new Vehicle(board,7,11,-1));
    Objects.push_back(new Vehicle(board,7,12,-1));

    Objects.push_back(new Vehicle(board,6,1,2));
    Objects.push_back(new Vehicle(board,6,5,2));
    Objects.push_back(new Vehicle(board,6,9,2));

    Objects.push_back(new Log(board,4,5,1));
    Objects.push_back(new Log(board,4,4,1));

    Objects.push_back(new Log(board,4,1,1));
    Objects.push_back(new Log(board,4,0,1));

    Objects.push_back(new Log(board,3,2,-1));
    Objects.push_back(new Log(board,3,3,-1));
    Objects.push_back(new Log(board,3,4,-1));

    Objects.push_back(new Log(board,3,7,-1));
    Objects.push_back(new Log(board,3,8,-1));
    Objects.push_back(new Log(board,3,9,-1));

    Objects.push_back(new Log(board,2,8,1));
    Objects.push_back(new Log(board,2,7,1));

    Objects.push_back(new Log(board,2,3,1));
    Objects.push_back(new Log(board,2,2,1));
}
void FroggerPlay::checkGame()
{
    for (int i =0; i<board->getHeight(); i++)
    {
        for (int j = 0; j<board->getWidth(); j++)
        {
            if (board->frogDies(i,j))
            {
                for (auto & Object : Objects){Object->goBack();}
                board->lives--;
            }
            if (board->board[1][j].hasFrog)
            {
                for (auto & Object : Objects){Object->goBack();}
                board->ffw++;
            }

        }
    }

}
void FroggerPlay::play()
{

    while (true)
    {
        system ("clear");
        board->display();
        for (auto & Object : Objects){Object->movement();}
        checkGame();
        //Warunek na wygrana
        if (board->lives == 0)
        {
            system ("clear");
            board->display();
            std::cout << std::endl << "YOU KILLED ALL FROGS!" << std::endl << "GAME OVER!" << std::endl;
            break;
        }
        //Warunek na przegrana
        if (board->ffw == 3)
        {
            system ("clear");
            board->display();
            std::cout << std::endl << "YOU SAVED ALL FROGS!" << std::endl << "YOU WIN!" << std::endl;
            break;
        }
    }
}
