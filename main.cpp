#include <iostream>
#include "Board.h"

using namespace std;

/*
 * This program contains:
 * main function to run global function for testing the Board class
 * play_checkers global function to test out the capabilities of the Board class
 * get_input global function to recieve and sanitize integer input from user
 *
 * TODO: Add logic to allow for rematches
 * TODO: Add timer to make matches more intense
 */

/******************** Global function prototypes ***********************/

void play_checkers();

int get_input();

int main()
{
    play_checkers();
    return 0;
}

/***************** Global function definitions *****************/

//Commences the game of checkers, testing out the Board class
void play_checkers()
{
    //Initialize variables for the start of the game, print instructions
    bool b_game_over = false;
    bool b_has_moved = false;
    int i_row, i_column, i_move_row, i_move_column;
    string s_player = "black's";
    Board b1(8, 8);
    cout << "Ready for some checkers? Enter 0 for either of the piece selection inputs to quit the game" << endl;
    cout << "Also, if you select a piece but want to move a different one instead, enter 0 for either of the movement inputs" << endl;

    //Main game loop, repeats every turn
    while(b_game_over == false)
    {
        //Print the board, display a special message once a score reaches 12
        b1.print_board();
        if (b1.get_white_score() == 12)
        {
            cout << "*********************" << endl;
            cout << "WHITE TEAM HAS WON!!!" << endl;
            cout << "*********************" << endl;
            b_game_over = true;
            break;
        }
        else if (b1.get_black_score() == 12)
        {
            cout << "*********************" << endl;
            cout << "BLACK TEAM HAS WON!!!" << endl;
            cout << "*********************" << endl;
            b_game_over = true;
            break;
        }

        //Get input for the piece selection position, quit game if user inputs 0
        cout << "It is " + s_player + " turn."<< endl;
        
        cout << "\nPlease enter the row # of the piece you would like to select to move: ";
        i_row = get_input() - 1;

        cout << "\nPlease enter the column # of the piece you would like to select to move: ";
        i_column = get_input() - 1;

        if (i_row == -1 || i_column == -1)
        {
            b_game_over = true;
            break;
        }

        //Verify piece is at given position, if so enter the game movement loop
        if (b1.check_for_piece(i_row, i_column, s_player))
        {
            //Get input for the movement position, loop if player fails to supply a valid movement position
            while(!b_has_moved)
            {
                cout << "\nPlease enter the row # of the tile you would like to move to: ";
                i_move_row = get_input() - 1;

                cout << "\nPlease enter the column # of the tile you would like to move to: ";
                i_move_column = get_input() - 1;

                //Attempt to move the piece using the given position, change player turn and exit loop if successful, display message otherwise
                b_has_moved = b1.move_piece(i_row, i_column, i_move_row, i_move_column, s_player);
                if (b_has_moved && i_move_row != -1 && i_move_column != -1)
                {
                    if (s_player == "black's")
                    {
                        s_player = "white's";
                    }
                    else if (s_player == "white's")
                    {
                        s_player = "black's";
                    }
                }
                else if(!b_has_moved && i_move_row != -1 && i_move_column != -1)
                {
                    b1.print_board();
                    cout << "Your move could not be performed, please attempt to move to a different tile" << endl;
                    cout << "if you mistakenly selected a piece, enter 0 for either of the movement inputs to select a different one" << endl;
                }
            }
        }
        b_has_moved = false;
    }
}

//Gets and returns integer input from user
int get_input()
{
    int i_input;
    //Get input, remove junk characters
    while (!(cin >> i_input))
        {
            cin.clear();
            string s_junk;
            getline(cin, s_junk);
        }
    return i_input;
}