#include <iostream>
#include <vector>

using namespace std;

#ifndef CBProject1_BOARD_H
#define CBProject1_BOARD_H

class Board{
private:
int length;
int width;
int pieceCount;

vector<vector<string>> grid;

public:
Board(int length, int width, int pieceCount){
    this->pieceCount = pieceCount;
    this->length = length;
    this->width = width;
    buildBoard();
};

void buildBoard(){
    vector<string> tempRow;
    vector<string> tempRow2;
    for (int i = 0; i < width/2; ++i){
        for (int j = 0; j < length/2; ++j){
            tempRow.push_back("○ • ");
            tempRow2.push_back("• ○ ");
        }
        tempRow[tempRow.size()-1].pop_back();
        tempRow2[tempRow2.size()-1].pop_back();
        grid.push_back(tempRow);
        grid.push_back(tempRow2);
        tempRow.clear();
        tempRow2.clear();
    }

}

void printBoard(){
    printVectorOfVectors(grid);
};

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

void getInput();

void movePiece();


};

#endif //CBProject1_BOARD_H