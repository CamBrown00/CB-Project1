#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#ifndef CBProject1_BOARD_H
#define CBProject1_BOARD_H

/*
 * This program contains:
 * Board Class with functions to assemble and update a checkers board
 * build_grid function to populate the grid with integers for pieces and tiles
 * print_board function to translate the integer contents of grid to strings for clarity, and print the board
 * move_piece function to rearrange, replace, and delete pieces upon movement or skipping
 * check_for_piece function to determine if a piece exists at a given position
 *
 * TODO: Add logic to allow for multiple consecutive skips
 * TODO: Add logic to allow for kinging and backwards movement
 */

class Board
{
private:
    int i_length;
    int i_width;
    int i_black_score;
    int i_white_score;

    vector<vector<int>> vvi_grid;

public:

    //Constructor
    Board(int i_length, int i_width)
    {
        this->i_length = i_length;
        this->i_width = i_width;
        i_black_score = 0;
        i_white_score = 0;
        build_grid();
    }

    //Populates grid vector with vectors of integers to represent the checker pieces and tiles
    void build_grid()
    {
        //Populates grid with vectors containing integer values of 0 to represent an empty tile
        vector<int> vi_temp_pieces;
        for (int i = 0; i < i_length; ++i)
        {
            vvi_grid.push_back(vi_temp_pieces);
            for (int j = 0; j < i_width; ++j)
            {
                vvi_grid[i].push_back(0);
            }
        }

        //Change some default integers in grid to 1 or -1 to represent black and white pieces
        for (int i = 0; i < i_length/2-1; ++i)
        {
            for (int j = 0; j < i_width; ++j)
            {
                if (((i+1) % 2) != ((j+1) % 2))
                {
                    vvi_grid[i][j] = -1;
                }
            }
        }
        for (int i = i_length/2+1; i < i_length; ++i)
        {
            for (int j = 0; j < i_width; ++j)
            {
                if (((i+1) % 2) != ((j+1) % 2))
                {
                    vvi_grid[i][j] = 1;
                }
            }
        }
    }


    //Translates the integer values contained in the grid vector to strings for the board display
    void print_board()
    {
        //Display team scores
        cout << "\nBLACK TEAM SCORE: " << i_black_score << endl;
        cout << "WHITE TEAM SCORE: " << i_white_score << endl;

        //Translate integers in grid to strings to clarify board contents when printed to console
        for (int i = 0; i < i_length; ++i)
        {
            for (int j = 0; j < i_width; ++j)
            {
                
                if (vvi_grid[i][j] != 0){
                    if (vvi_grid[i][j] == -1)
                    {
                        cout << "W ";
                    }
                    else if (vvi_grid[i][j] == 1)
                    {
                        cout << "B ";
                    }
                }
                else
                {
                    if (((i+1) % 2) == ((j+1) % 2))
                    {
                        cout << "- ";
                    }
                    else
                    {
                        cout << "- ";
                    }
                }
                
            }
            cout << endl;
        } 
    }

    //Rearranges and replaces integers contained within the grid to represent piece movement, and skipping
    bool move_piece(int i_row, int i_column, int i_move_row, int i_move_column, string s_player)
    {
        //Initialize boolean variables based on nearby pieces/tiles
        bool b_has_moved = false;
        bool b_is_black_piece = check_for_piece(i_move_row, i_move_column, "black's");
        bool b_is_white_piece = check_for_piece(i_move_row, i_move_column, "white's");
        bool b_is_empty_tile = !check_for_piece(i_move_row, i_move_column, "white's") && !check_for_piece(i_move_row, i_move_column, "black's");
        bool b_is_valid;
        bool b_is_valid_skip;

        //Determine if proposed movement position is valid, and increment score if a skip is possible
        if (s_player == "black's")
        {
            b_is_valid = ((i_row - i_move_row == 1) && (abs(i_column - i_move_column) == 1));
            b_is_valid_skip = (b_is_valid && b_is_white_piece);
            i_black_score += 1 * b_is_valid_skip;
        }
        if (s_player == "white's")
        {
            b_is_valid = ((i_move_row - i_row == 1) && (abs(i_column - i_move_column) == 1));
            b_is_valid_skip = (b_is_valid && b_is_black_piece);
            i_white_score += 1 * b_is_valid_skip;
        }

        //Move the piece if position is valid, default to a skip if one is possible
        int input;
        vector<vector<int>> vvi_old_grid = vvi_grid;
        if ((b_is_empty_tile && b_is_valid) || b_is_valid_skip)
        {
            if (b_is_valid_skip)
            {
                cout << s_player + " piece is skipping!" << endl;
                vvi_old_grid[i_move_row - (i_row - i_move_row)][i_move_column - (i_column - i_move_column)] = vvi_old_grid[i_row][i_column];
                vvi_old_grid[i_move_row][i_move_column] = 0;
                vvi_old_grid[i_row][i_column] = 0;
                vvi_grid = vvi_old_grid;
                b_has_moved = true;
            }
            else
            {
                vvi_old_grid[i_move_row][i_move_column] = vvi_old_grid[i_row][i_column];
                vvi_old_grid[i_row][i_column] = 0;
                vvi_grid = vvi_old_grid;
                b_has_moved = true;
            }
        }
        else if (i_move_row == -1 || i_move_column == -1)
        {
            b_has_moved = true;
        }
        return b_has_moved;

    }

    //Checks if a piece on the board is present at the input position, and determines the piece's corresponding team
    bool check_for_piece(int i_piece_row, int i_piece_column, string s_player)
    {
        //Determine team of piece at given position, or if tile is empty
        bool b_found = false;
        if (i_piece_row > -1 && i_piece_column > -1 && i_piece_row <= i_length && i_piece_column <= i_width)
        {
            if (s_player == "white's")
            {
                if (vvi_grid[i_piece_row][i_piece_column] == -1)
                {
                    b_found = true;
                }
            }
            if (s_player == "black's")
            {
                if (vvi_grid[i_piece_row][i_piece_column] == 1)
                {
                    b_found = true;
                }
            }
        }
        else if (i_piece_row != -1 && i_piece_column != -1)
        {
            cout << "Your input was outside the range of the board, please try again" << endl;
        }
        return b_found;
    }

    //Getters
    int get_black_score()
    {
        return i_black_score;
    }

    int get_white_score()
    {
        return i_white_score;
    }

};

#endif //CBProject1_BOARD_H