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
    Board b1(8, 8);
    cout << "Ready for some checkers? Enter 0 for either of the piece selection inputs to quit the game" << endl;
    cout << "Also, if you select a piece but want to move a different one instead, enter 0 for either of the movement inputs" << endl;

    while(gameOver == false){
        b1.printBoard();

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
                if (hasMoved && moveRow != -1 && moveColumn != -1){
                    if (player == "black's"){
                        player = "white's";
                    }
                    else if (player == "white's"){
                        player = "black's";
                    }
                }else if(!hasMoved && moveRow != -1 && moveColumn != -1){
                    b1.printBoard();
                    cout << "Your move could not be performed, please attempt to move to a different tile" << endl;
                    cout << "if you mistakenly selected a piece, enter 0 for either of the movement inputs to select a different one" << endl;
                }
            }
        }
        hasMoved = false;
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