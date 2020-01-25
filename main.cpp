#include <iostream>
#include "Board.h"

using namespace std;

/******************** Global function prototypes ***********************/

// Requires: nothing
// Modifies: cout
// Effects: Commences the game of checkers, testing out the Board class
void playCheckers();

// Requires: nothing
// Modifies: cin, cout
// Effects: Gets and returns integer input from user
int getInput();

int main() {
    playCheckers();
    return 0;
}

/***************** Global function definitions *****************/

void playCheckers(){
    //Initialize variables for the start of the game, print instructions
    bool gameOver = false;
    bool hasMoved = false;
    int row, column, moveRow, moveColumn;
    string player = "black's";
    Board b1(8, 8);
    cout << "Ready for some checkers? Enter 0 for either of the piece selection inputs to quit the game" << endl;
    cout << "Also, if you select a piece but want to move a different one instead, enter 0 for either of the movement inputs" << endl;

    //Main game loop, repeats every turn
    while(gameOver == false){
        //Print the board, display a special message once a score reaches 12
        b1.printBoard();
        if (b1.getWhiteScore() == 12){
            cout << "*********************" << endl;
            cout << "WHITE TEAM HAS WON!!!" << endl;
            cout << "*********************" << endl;
            gameOver = true;
            break;
        }else if (b1.getBlackScore() == 12){
            cout << "*********************" << endl;
            cout << "BLACK TEAM HAS WON!!!" << endl;
            cout << "*********************" << endl;
            gameOver = true;
            break;
        }

        //Get input for the piece selection position, quit game if user inputs 0
        cout << "It is " + player + " turn."<< endl;
        
        cout << "\nPlease enter the row # of the piece you would like to select to move: ";
        row = getInput() - 1;

        cout << "\nPlease enter the column # of the piece you would like to select to move: ";
        column = getInput() - 1;

        if (row == -1 || column == -1){
            gameOver = true;
            break;
        }

        //Verify piece is at given position, if so enter the game movement loop
        if (b1.checkForPiece(row, column, player)){
            //Get input for the movement position, loop if player fails to supply a valid movement position
            while(!hasMoved){
                cout << "\nPlease enter the row # of the tile you would like to move to: ";
                moveRow = getInput() - 1;

                cout << "\nPlease enter the column # of the tile you would like to move to: ";
                moveColumn = getInput() - 1;

                //Attempt to move the piece using the given position, change player turn and exit loop if successful, display message otherwise
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
    //Get input, remove junk characters
    while (!(cin >> input))
        {
            cin.clear();
            string junk;
            getline(cin, junk);
        }
    return input;
}