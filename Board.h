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
int blackScore;
int whiteScore;

vector<vector<int>> grid;

public:
Board(int length, int width, int pieceTotal){
    this->pieceTotal = pieceTotal;
    this->length = length;
    this->width = width;
    buildGrid();
    printBoard();
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
                    cout << "☻ ";
                }
                else if (grid[i][j] == 1){
                    cout << "☺ ";
                }
            }else{
                if (((i+1) % 2) == ((j+1) % 2)){
                    cout << "• ";
                }else{
                    cout << "○ ";
                }
            }
            
        }
        cout << endl;
    } 
}

void printVectorOfVectors(vector<vector<string>> vec){
    for (int i = 0; i < vec.size(); ++i){
        printVector(vec[i]);
    }
}

void printVector(vector<string> vec){
    for (int i = 0; i < vec.size(); ++i){
        cout << vec[i];
    }
    cout << endl;
}

void getInput(){

}

void movePiece(){

}

int getBlackScore(){
    return blackScore;
}

int getWhiteScore(){
    return whiteScore;
}

};

#endif //CBProject1_BOARD_H