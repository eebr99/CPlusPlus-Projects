// Author: Eric Blanco
// Course: COSC 1337 Spring 2020 MW10; Instructor: Thayer
// Assignment: Lab 8
// Topic: This program 
/*
IPO Chart

INPUT
 class Board, the game board will have the following members
  declare enum Board_state_t
  private:
	char grid, for a 3 by 3 standard tic tac toe board
	Board_state_t state, for state of the board
	public:
	void reset(), to clear board for a new game
	make_move(), to make a move on the board and update it
	show(), to show current state of the board
 bool running, to run the while loop
 char play_again, either y or n, if y, play again, else, quit 
 get_int(), avoids infinite loop if letter entered
 row, for board row#
 col, for board column#
 
PROCESSING
 take player 1 input and place x in chosen spot
 take player 2 input and place o in chosen spot
 if spot already taken, display appropriate message and ask to retry
 continue until player 1 or 2 wins, or nobody wins
 keep program running and play again if players decide to
 quit if players are finished
 
OUTPUT
 display greeting and explanation/instruction
 display player1 prompt and current board
 display player2 prompt and current board
  continue until end of game
 display result of game and ask to play again
  if play again, do all over
 else, display farewell message
*/
// Compiler directives
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <vector> // needed for vectors
using namespace std;

int getint (const string &prompt, string errNonDigit, string errRange, int lo, int hi) {
	while (bool getting_integer=true) {
		cout<<prompt<<" ("<<lo<<"-"<<hi<<"): ";
		int users_int_input=0;
		if(cin>>users_int_input) {
      if(users_int_input>=lo and users_int_input <= hi) {
        return users_int_input; // RETURN VALID USER INPUT VALUE
      } else cout<<errRange;
 		}
    else {
 		  cout<<errNonDigit; cin.clear(); cin.ignore(1024, '\n');
 		}
	}
}
enum board_state_t {no_won, X_won, O_won, draw, original}; // create enum for game status
class Board {
  //enum board_state_t {no_won, X_won, O_won, draw, original}; // create enum for game status
  private:
    char grid[3][3]; /*= {{'7','8','9'},
	                   	 {'4','5','6'},
	                     {'1','2','3'}};*/
    board_state_t state;

  public:
    void reset(){  // need this to clear / reset board to start a new game
    	grid[0][0] = '7'; grid[0][1] = '8'; grid[0][2] = '9';
    	grid[1][0] = '4'; grid[1][1] = '5'; grid[1][2] = '6';
    	grid[2][0] = '1'; grid[2][1] = '2'; grid[2][2] = '3';

		}
    /*board_state_t*/ void make_move(int spot, char player){ // need this to make a move on the board, update board
			switch(spot){
				case 1: grid[2][0] = player; break; 
				case 2: grid[2][1] = player; break;
				case 3: grid[2][2] = player; break;
				case 4: grid[1][0] = player; break;
				case 5: grid[1][1] = player; break;
				case 6: grid[1][2] = player; break;
				case 7: grid[0][0] = player; break;
				case 8: grid[0][1] = player; break;
				case 9: grid[0][2] = player; break;
			}
    }
    void show(){ // need this to display the board after each move
    	cout << "-----------" << endl;
			for (int row = 0; row < 3; row++){
  			for (int col = 0; col < 3; col++){
  				cout << grid[row][col] << " | ";
				}
				cout << "\n-----------";
				cout << endl;
			}
		}
};


int main(){
	cout<<"\nHi! This is a game of tic tac toe! Here is the board:\n";
	Board board;
	board.reset();
	board.show();
	cout << "The board is identical to the numpad on your computer."; 
	cout << "\nPlease enter the corresponding number you wish to place your X or O on." << endl;
	
  bool playing=true;
  while (playing) {
    static char player='X'; // use a static char, so only one, not reset to 'X' every iteration of loop
    //board_state_t game_status;
    string prompt="\nEnter player "+string(1, player)+"'s move, 0 to quit. ";
    // need to convert char player 'X' into string "X" before I can use + to concatenate strings together
    
    // use getint() for validation checking, avoid infinite loop error if user enters letters

    int spot=getint(prompt+"location: ", "", "", 0, 9); // allow range 0-9, 0 to quit
    if (!spot) break; // break if spot is false, (or 0)
    // here, need to make a move on the board, then see if there is a winner, cat game (tie game), etc.
		/*game_status = */board.make_move(spot, player);
    player=((player=='X')?'O':'X'); // alternate player from X to O to X ...
    board.show();
  }
}


