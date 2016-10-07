#include <iostream>
#include <string>

using namespace std;

class Solver {

public:

	// just for curiosity sake
	int stepsTaken = 0;

	// flag into step mode where each step waits on the users input
	bool step = false;

	void setStepMode(bool flag)
	{
		step = flag;
	}

	// attempts to solve the given board
	bool solve(int board[9][9])
	{
		// current position on the board the solver is at
		// these values will be set with the findNext function by reference
		int row = 0;
		int col = 0;

		if(!findNext(board, row, col))
			return true;

		// traverse through all possible numbers, back track if it doesnt work
		for(int num = 1; num <= 9; num++)
		{
				if(isValid(board, row, col, num)) // check if the number at this position will be valid, if not, back track!
				{
					board[row][col] = num;

					if(solve(board))
						return true; // everthing works!

					// (curiosity)
					stepsTaken++;

					if(step)
					{
						std::cin.ignore();
						displayBoard(board);
					}
					board[row][col] = 0; // failed, set the board position back to 0 and try again - BACK TRACK!
				}
		}

		// this option is a dead end, BACK TRACK!
		return false;
	}


	// gets the next empty position in the board, if there is no more positions
	// to be checked, return false (this causes the program to exit solving)
	bool findNext(int board[9][9], int &row, int &col)
	{

		for(row = 0; row < 9; row++)
			for(col = 0; col < 9; col++)
				if(board[row][col] == 0)
					return true; // we still have more steps to go
		return false; // we are done searching all that we can, we have reached the end of the board
	}

	// check column constraint
	bool validInCol(int board[9][9], int row, int col, int num)
	{
		for(int c = 0; c < 9; c++)
			if(board[row][c] == num)
				return false; // not valid
		return true;
	}

	// checks row constraint
	bool validInRow(int board[9][9], int row, int col, int num)
	{
		for(int r = 0; r < 9; r++)
			if(board[r][col] == num)
				return false; // not valid

			return true;
	}

	// checks (3x3)x3 box constraint
	bool validInBox(int board[9][9], int rowOffset, int colOffset, int num)
	{
		for(int x = 0; x < 3; x++)
			for(int y = 0; y < 3; y++)
				if(board[x + rowOffset][y + colOffset] == num)
					return false; // not valid

		return true;
	}

	// general function to check all constraints of the current move to make sure it is a valid move
	bool isValid(int board[9][9], int row, int col, int num)
	{
		return validInCol(board, row, col, num)
		    && validInRow(board, row, col, num)
		    && validInBox(board, row - row % 3, col - col % 3, num);
		    // modulo 3 gives us the start position of each 3x3 grid inside the game board
	}


	// displays the full game board
	void displayBoard(int board[9][9]) {
		cout << endl;
		for (int x = 0; x < 9; x++) {
			for (int y = 0; y < 9; y++) {

				if(y == 3 || y == 6)
					cout << "  ";


				if ((int) y % 10 == 0)
					cout << endl;

				cout << board[x][y];
			}
		}
	}
};


// runs the solver!
int main() {

	Solver s;


// plug in any 9x9 game board you like here

	int board[9][9] =      {{4, 0, 8, 0, 0, 2, 3, 6, 0},
						    {0, 7, 0, 0, 0, 0, 0, 0, 4},
						    {1, 9, 3, 4, 0, 0, 0, 0, 2},
						    {0, 0, 9, 0, 5, 0, 0, 0, 1},
						    {0, 6, 1, 2, 0, 3, 8, 4, 0},
						    {3, 0, 0, 0, 4, 0, 6, 0, 0},
						    {5, 0, 0, 0, 0, 4, 9, 7, 8},
						    {9, 0, 0, 0, 0, 0, 0, 2, 0},
						    {0, 1, 7, 9, 0, 0, 4, 0, 6}};


/** int board[9][9] =      {{9, 0, 0, 2, 3, 0, 0, 0, 8},
						    {8, 0, 7, 0, 0, 1, 0, 2, 0},
						    {0, 0, 0, 4, 0, 0, 0, 7, 9},
						    {6, 0, 0, 0, 9, 0, 7, 4, 0},
						    {0, 2, 0, 7, 0, 5, 0, 8, 0},
						    {1, 7, 0, 8, 0, 0, 0, 0, 0},
						    {0, 0, 0, 6, 2, 0, 0, 1, 7},
						    {3, 4, 0, 1, 0, 9, 0, 0, 0},
						    {7, 1, 0, 0, 4, 8, 0, 3, 2}};
**/


	// use this to flag manual execution so you can watch to algorithm work
	// the program will wait until you press any key
	s.setStepMode(false);

	cout << endl << "START";
	s.displayBoard(board);
	cout << endl;

	// attempt to solve the given game
	if(s.solve(board))
	{
		cout << endl << "SOLUTION";
		s.displayBoard(board);
	}
	else
		cout << "there is no solution to the given board";


	//cout << endl << s.stepsTaken;

	return 0;
}
