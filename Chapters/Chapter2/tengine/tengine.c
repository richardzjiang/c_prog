/* A chess engine, except for tic-tac-toe. I guess it's a tic-tac-toe engine? tengine for short */

#include <stdio.h>
#include <math.h>
#define TRUE 1
#define FALSE 0
#define OCCUPIED 1
#define UNOCCUPIED 0


int minimax(int node, int depth, int maximizingPlayer);
int max(int a, int b);
int min(int a, int b);
int tree(int value, int depth, int maximizing, int *p);
int eval(int position, int *p);

main()
{
	int i;
	int grid[9];

	for (i = 0; i < 9; ++i)
		grid[i] = UNOCCUPIED;	/* starting value of unoccupied slots in the grid array must be zero */
}

/* tree: a function that is incredibly similar to the minimax function that I definitely did not copy off of wikipedia */
int tree(int value, int depth, int maximizing, int *p)
{
	int i;
	int grid[9];
	for (i = 0; i < 9; ++i)
		grid[i] = p[i];
	if (depth == 0)
		return value;	/* i think */
	if (maximizing) {
		value = -INFINITY;	/* I belive that this macro is defined in math.h. value is neg infinity. After this for loop, value will be equal to the play that has the highest value */
		for (i = 0; i < 9; ++i)
			if (grid[i] == UNOCCUPIED) {
				grid[i] = OCCUPIED;
				value = max(value, tree(eval(i, grid), depth - 1, FALSE, grid));
				grid[i] = UNOCCUPIED;	/* makes sure to not permanently change the values of grid */
			}
		return value;
	} else {
		/* value is pos infinity */
		value = INFINITY;	/* INFINITY is defined in math.h I think */
		for (i = 0; i < 9; ++i)
			if (grid[i] == UNOCCUPIED) {
				grid[i] = OCCUPIED;
				value = min(value, tree(eval(i, grid), depth - 1, TRUE, grid));
				grid[i] = UNOCCUPIED;	/* makes sure to not permanently change the values of grid */
			}	
		return value;
	}
}
	

int minimax(int node, int depth, int maximizingPlayer)
{
	if (depth == 0 /* or node is a terminal node */)
		return node;
	if (maximizingPlayer) {
		value = /* neg infinity */;
		for (/* each child of node */)
			value = max(value, minimax(child, depth - 1, FALSE));
		return value;
	}
	else (/* minimizing player */) {
		value = /* pos infinity */;
		for (/* each child of node */)
			value = min(value, minimax(child, depth - 1, TRUE));
		return value;
	}
}

/* eval: receive input of the current state of the tictactoe grid, and a position to evaluate. It will evaluate how good it would be to play that position */
int eval(int position, int *p)
{
}

int max(int a, int b)
{
	if (a > b)
		return a;
	else if (a < b)
		return b;
	else if (a == b)
		return a;	/* or b, it doesn't matter */
}

int min(int a, int b)
{
	if (a > b)
		return b;
	else if (a < b)
		return a;
	else if (a == b)
		return a;	/* or b, it doesn't matter */
}
