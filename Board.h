#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#ifndef CBProject1_BOARD_H
#define CBProject1_BOARD_H

class Board{
private:
    int length;
    int width;
    int blackScore;
    int whiteScore;

    vector<vector<int>> grid;

public:

    // Constructor
    // Requires: non-negative input
    // Modifies: length, width, blackScore, whiteScore
    // Effects: Initializes fields, runs buildGrid function
    Board(int length, int width){
        this->length = length;
        this->width = width;
        blackScore = 0;
        whiteScore = 0;
        buildGrid();
    }

    // Requires: nothing
    // Modifies: grid
    // Effects: populates grid vector with vectors of integers to represent the checker pieces and tiles
    void buildGrid(){
        //Populates grid with vectors containing integer values of 0 to represent an empty tile
        vector<int> tempPieces;
        for (int i = 0; i < length; ++i){
            grid.push_back(tempPieces);
            for (int j = 0; j < width; ++j){
                grid[i].push_back(0);
            }
        }

        //Change some default integers in grid to 1 or -1 to represent black and white pieces
        for (int i = 0; i < length/2-1; ++i){
            for (int j = 0; j < width; ++j){
                if (((i+1) % 2) != ((j+1) % 2)){
                    grid[i][j] = -1;
                }
            }
        }
        for (int i = length/2+1; i < length; ++i){
            for (int j = 0; j < width; ++j){
                if (((i+1) % 2) != ((j+1) % 2)){
                    grid[i][j] = 1;
                }
            }
        }
    }

    // Requires: nothing
    // Modifies: cout
    // Effects: translates the integer values contained in the grid vector to strings for the board display
    void printBoard(){
        //Display team scores
        cout << "\nBLACK TEAM SCORE: " << blackScore << endl;
        cout << "WHITE TEAM SCORE: " << whiteScore << endl;

        //Translate integers in grid to strings to clarify board contents when printed to console
        for (int i = 0; i < length; ++i){
            for (int j = 0; j < width; ++j){
                
                if (grid[i][j] != 0){
                    if (grid[i][j] == -1){
                        cout << "W ";
                    }
                    else if (grid[i][j] == 1){
                        cout << "B ";
                    }
                }else{
                    if (((i+1) % 2) == ((j+1) % 2)){
                        cout << "- ";
                    }else{
                        cout << "- ";
                    }
                }
                
            }
            cout << endl;
        } 
    }

    // Requires: non-negative input between 1 and 8, string with a value of either "white's" or "black's"
    // Modifies: blackScore, whiteScore, grid, cout
    // Effects: rearranges and replaces integers contained within the grid to represent piece movement, and skipping
    bool movePiece(int row, int column, int moveRow, int moveColumn, string player){
        //Initialize boolean variables based on nearby pieces/tiles
        bool hasMoved = false;
        bool isBlackPiece = checkForPiece(moveRow, moveColumn, "black's");
        bool isWhitePiece = checkForPiece(moveRow, moveColumn, "white's");
        bool isEmptyTile = !checkForPiece(moveRow, moveColumn, "white's") && !checkForPiece(moveRow, moveColumn, "black's");
        bool isValid;
        bool isValidSkip;

        //Determine if proposed movement position is valid, and increment score if a skip is possible
        if (player == "black's"){
            isValid = ((row - moveRow == 1) && (abs(column - moveColumn) == 1));
            isValidSkip = (isValid && isWhitePiece);
            blackScore += 1 * isValidSkip;
        }
        if (player == "white's"){
            isValid = ((moveRow - row == 1) && (abs(column - moveColumn) == 1));
            isValidSkip = (isValid && isBlackPiece);
            whiteScore += 1 * isValidSkip;
        }

        //Move the piece if position is valid, default to a skip if one is possible
        int input;
        vector<vector<int>> oldGrid = grid;
        if ((isEmptyTile && isValid) || isValidSkip){
            if (isValidSkip){
                cout << player + " piece is skipping!" << endl;
                oldGrid[moveRow - (row - moveRow)][moveColumn - (column - moveColumn)] = oldGrid[row][column];
                oldGrid[moveRow][moveColumn] = 0;
                oldGrid[row][column] = 0;
                grid = oldGrid;
                hasMoved = true;
            }else{
                oldGrid[moveRow][moveColumn] = oldGrid[row][column];
                oldGrid[row][column] = 0;
                grid = oldGrid;
                hasMoved = true;
            }
        }
        else if (moveRow == -1 || moveColumn == -1){
            hasMoved = true;
        }
        return hasMoved;

    }

    // Requires: non-negative input between 1 and 8, string with a value of either "white's" or "black's"
    // Modifies: cout
    // Effects: checks if a piece on the board is present at the input position, and determines the piece's corresponding team
    bool checkForPiece(int pieceRow, int pieceColumn, string player){
        //Determine team of piece at given position, or if tile is empty
        bool found = false;
        if (pieceRow > -1 && pieceColumn > -1 && pieceRow <= length && pieceColumn <= width){
            if (player == "white's"){
                if (grid[pieceRow][pieceColumn] == -1){
                    found = true;
                }
            }
            if (player == "black's"){
                if (grid[pieceRow][pieceColumn] == 1){
                    found = true;
                }
            }
        }else if (pieceRow != -1 && pieceColumn != -1){
            cout << "Your input was outside the range of the board, please try again" << endl;
        }
        return found;
    }

    //Getters
    // Requires: nothing
    // Modifies: nothing
    // Effects: returns the score for the black team to determine a winner
    int getBlackScore(){
        return blackScore;
    }

    // Requires: nothing
    // Modifies: nothing
    // Effects: returns the score for the white team to determine a winner
    int getWhiteScore(){
        return whiteScore;
    }

};

#endif //CBProject1_BOARD_H