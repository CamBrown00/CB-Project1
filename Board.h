#include <iostream>
#include <vector>

using namespace std;

#ifndef CBProject1_BOARD_H
#define CBProject1_BOARD_H

class Board{
private:
int length;
int width;
int pieceTotal;
int blackScore = 0;
int whiteScore = 0;

vector<vector<int>> grid;

public:
Board(int length, int width, int pieceTotal){
    this->pieceTotal = pieceTotal;
    this->length = length;
    this->width = width;
    buildGrid();
}

void buildGrid(){
    vector<int> tempPieces;
    for (int i = 0; i < length; ++i){
        grid.push_back(tempPieces);
        for (int j = 0; j < width; ++j){
            grid[i].push_back(0);
        }
    }

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

void printBoard(){
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

bool movePiece(int moveRow, int moveColumn){
    vector<vector<int>> oldGrid = grid;

}

bool checkForPiece(int pieceRow, int pieceColumn, string player){
    bool found = false;
    if (pieceRow > 0 && pieceColumn > 0 && pieceRow <= length && pieceColumn <= width){
        if (player == "white's"){
            if (grid[pieceRow-1][pieceColumn-1] == -1){
                found = true;
            } 
        }
        if (player == "black's"){
            if (grid[pieceRow-1][pieceColumn-1] == 1){
                found = true;
            } 
        }
    }else{
        cout << "Your input was outside the range of the board, please try again" << endl;
    }
    return found;
}

int getBlackScore(){
    return blackScore;
}

int getWhiteScore(){
    return whiteScore;
}

};

#endif //CBProject1_BOARD_H