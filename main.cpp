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
    int row;
    int column;
    string player = "black's";
    Board b1(8, 8, 24);
    cout << "Welcome to checkers, enter -1 to quit the game at any time" << endl;

    while(gameOver == false){
        b1.printBoard();
        //Check if game is over, if so break

        cout << "It is " + player + " turn."<< endl;
        
        cout << "Please enter the row # of the piece you would like to select: " << endl;
        row = getInput();

        cout << "Please enter the column # of the piece you would like to select: " << endl;
        column = getInput();

        if (row == -1 || column == -1){
            gameOver = true;
            break;
        }
        cout << b1.checkForPiece(row, column, player) << endl;
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