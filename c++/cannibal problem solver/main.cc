#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <sstream>
#include <string>

using namespace std;

// This solution to the missionary cannibal problem simulates states and trys to traverse the state space

/**
* States of the game
*/
struct GameState {
	int leftM;
	int leftC;
	int boatPos;
	GameState *previousState;
	int moves; // number of moves used to get to this state
	int flag;
};

/**
* Override the ostream to make convenient output of the state
*/
	ostream& operator<<(ostream& os, const GameState& state)
	{
    	os << "M:" << state.leftM << "/" << "C:" << state.leftC;
    	if(state.boatPos == 1)
    		os<< "_BOAT__________";
    	else
    		os << "__________BOAT_";
    	os << "M:" << 3 - state.leftM << "/" << "C:" << 3 - state.leftC;
    	os << endl;
    	return os;
	}


	GameState operator+(const GameState &a, const GameState &b)
	{
	   GameState n = a;
	   n.leftM += b.leftM;
	   n.leftC += b.leftC;
	   n.boatPos += b.boatPos;
	   return n;
	}

	GameState operator-(const GameState &a, const GameState &b)
	{
	   GameState n = a;
	   n.leftM -= b.leftM;
	   n.leftC -= b.leftC;
	   n.boatPos -= b.boatPos;
	   return n;
	}

class Game {
public:
	GameState initialState = {3, 3, 1, NULL, 0, 1};
	vector<GameState*> validStates;

	//List of possible moves
	GameState move1 = {1, 0, 1, NULL, 1};
	GameState move2 = {2, 0, 1, NULL, 1};
	GameState move3 = {0, 1, 1, NULL, 1};
	GameState move4 = {0, 2, 1, NULL, 1};
	GameState move5 = {1, 1, 1, NULL, 1};

	/**
	* Initializes a new "game"
	*/
	void initialize() {
			cout << "Missionaries and Cannibals" << endl << endl;
	}


	/** runs the simulation and outputs the shortest move set to win
	*
	*/
	void run() {
		GameState *init = new GameState;
		*init = initialState;
		
		cout << "Solution" << endl;

		cout << printSolution(init);
	}

	/**
	* Checks if the state we are trying to get to is valid and does not cause the cannibals to eat the missionaries
	*/
	bool checkState(GameState state) {
		 if(state.leftC > state.leftM)
		 	return false;
		return true;
	}

	string printSolution(GameState *initial)
	{
		queue<GameState*> q;
		
		string path = "";

		q.push(initial);

		while(!q.empty())
		{
			GameState *x = q.front();
	
			std::ostringstream stream;
			vector<GameState*> children;


			//** NEED TO APPEND STRINGS DIFFERENTLY

	
			path += stream.str();

			q.pop();

			if(checkWin(x)) {
				cout << "WIN\n";
				cout << *x;
				return path;
			}
			
			vector<GameState*> y = getNextMoves(x);

			
			for(unsigned int x = 0; x < y.size(); x++)
			{
				q.push(y[x]);
			}
			
		}

		return path;
	}

	/**
	* Makes the next legal move
	*/
	vector<GameState*> getNextMoves(GameState *state) { 
				
			vector<GameState*> children;

			GameState *a = new GameState;
			GameState *b = new GameState;	
			GameState *c = new GameState;
			GameState *d = new GameState;
			GameState *e = new GameState;
		

				if(state->flag == 1) {
						*a = *state - move1;
						*b = *state - move2;
						*c = *state - move3;
						*d = *state - move4;
						*e = *state - move5;
						// set children to be added next (new tree level)
						a->flag = 0;
						b->flag = 0;
						c->flag = 0;
						d->flag = 0;
						e->flag = 0;

						a->previousState = state;
						b->previousState = state;
						c->previousState = state;
						d->previousState = state;
						e->previousState = state;
						
				
				} 
				if(state->flag == 0) {
						*a = *state + move1;
						*b = *state + move2;
						*c = *state + move3;
						*d = *state + move4;
						*e = *state + move5;
						// set children to be minused next (new tree level)
						a->flag = 1;
						b->flag = 1;
						c->flag = 1;
						d->flag = 1;
						e->flag = 1;
						a->previousState = state;
						b->previousState = state;
						c->previousState = state;
						d->previousState = state;
						e->previousState = state;
					
					}
				

			if(checkState(*a)) {
				children.push_back(a);
			}
			if(checkState(*b)) {
				children.push_back(b);
			}
			if(checkState(*c)) {
				children.push_back(c);
			}
			if(checkState(*d)) {
				children.push_back(d);
			}

			if(checkState(*e)) {
				children.push_back(e);
			}

		
		return children;
	}


	/**
	* Checks for the win condition, being that al 6 are on the right side of the river
	*/
	bool checkWin(GameState *state) {
		if(state->leftM == 0 && state->leftC == 0 && state->boatPos == 0)
			return true;
		return false;
	}

};

/*
* The main method to run the simulation
*/
int main() {

	Game g;
	g.initialize();
	g.run();

	return 0;
}


