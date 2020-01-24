#include <iostream>
#include "Board.h"

using namespace std;

void playCheckers();
int getInput();

int main() {
    playCheckers();
    return 0;
}

void playCheckers(){
    bool gameOver = false;
    bool hasMoved = false;
    int row, column, moveRow, moveColumn;
    string player = "black's";
    Board b1(8, 8, 24);
    cout << "Welcome to checkers, enter 0 to quit the game at any time" << endl;

    while(gameOver == false){
        b1.printBoard();
        //Check if game is over, if so break

        cout << "It is " + player + " turn."<< endl;
        
        cout << "\nPlease enter the row # of the piece you would like to select to move: ";
        row = getInput() - 1;

        cout << "\nPlease enter the column # of the piece you would like to select to move: ";
        column = getInput() - 1;

        if (row == -1 || column == -1){
            gameOver = true;
            break;
        }

        if (b1.checkForPiece(row, column, player)){
            while(!hasMoved){
                cout << "\nPlease enter the row # of the tile you would like to move to: ";
                moveRow = getInput() - 1;

                cout << "\nPlease enter the column # of the tile you would like to move to: ";
                moveColumn = getInput() - 1;

            
                hasMoved = b1.movePiece(row, column, moveRow, moveColumn, player);
                if (hasMoved){
                    if (player == "black's"){
                        player = "white's";
                    }
                    if (player == "white's"){
                        player = "black's";
                    }
                }
            }
        }
    }
}

int getInput(){
    int input;
    while (!(cin >> input))
        {
            cin.clear();
            string junk;
            getline(cin, junk);
        }
    return input;
}