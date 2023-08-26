/* A chess engine, except for tic-tac-toe. I guess it's a tic-tac-toe engine? tengine for short */

#include <stdio.h>
#include <math.h>
#define TRUE 1
#define FALSE 0
#define OCCUPIED 1
#define UNOCCUPIED 0


//int minimax(int node, int depth, int maximizingPlayer);
int max(int a, int b);
int min(int a, int b);
int tree(int value, int depth, int maximizing, int *grid);
int eval(int position, int *grid);
int printgrid(int *grid, char symbol);

main()
{
	int i;
	int grid[9];

	for (i = 0; i < 9; ++i)
		grid[i] = UNOCCUPIED;	/* starting value of unoccupied slots in the grid array must be zero */

	printgrid(grid, 'X');
}

/* tree: a function that is incredibly similar to the minimax function that I definitely did not copy off of wikipedia */
int tree(int value, int depth, int maximizing, int *grid)
{
	int i;
	int tmp[9];	/* used in the input for eval() */
	for (i = 0; i < 9; ++i)
		tmp[i] = grid[i];
	if (depth == 0)
		return value;	/* i think */
	if (maximizing) {
		value = -INFINITY;	/* I belive that this macro is defined in math.h. value is neg infinity. After this for loop, value will be equal to the play that has the highest value */
		for (i = 0; i < 9; ++i)
			if (grid[i] == UNOCCUPIED) {
				grid[i] = OCCUPIED;
				value = max(value, tree(eval(i, tmp), depth - 1, FALSE, grid));
				grid[i] = UNOCCUPIED;	/* makes sure to not permanently change the values of grid */
			}
		return value;
	} else {
		/* value is pos infinity */
		value = INFINITY;	/* INFINITY is defined in math.h I think */
		for (i = 0; i < 9; ++i)
			if (grid[i] == UNOCCUPIED) {
				grid[i] = OCCUPIED;
				value = min(value, tree(eval(i, tmp), depth - 1, TRUE, grid));
				grid[i] = UNOCCUPIED;	/* makes sure to not permanently change the values of grid */
			}	
		return value;
	}
}
	
/*
int minimax(int node, int depth, int maximizingPlayer)
{
	if (depth == 0  or node is a terminal node )
		return node;
	if (maximizingPlayer) {
		value =  neg infinity;
		for ( each child of node )
			value = max(value, minimax(child, depth - 1, FALSE));
		return value;
	}
	else ( minimizing player ) {
		value =  pos infinity ;
		for ( each child of node )
			value = min(value, minimax(child, depth - 1, TRUE));
		return value;
	}
}
*/

/* eval: receive input of the current state of the tictactoe grid, and a position to evaluate. It will evaluate how good it would be to play that position */
int eval(int position, int *grid)
{
	int i;

	if (grid[i] = OCCUPIED)	/* the grid position that is to be evaluated is already occupied */
		return -INFINITY;	/* cuz playing in a position that is already occupied is a dogwater decision */

	/* function unfinished */
}

/* printgrid: receive the array containing the tic-tac-toe grid data as input, and print the grid. symbol can be X or O (or something else even) */
printgrid(int *grid, char symbol)
{
	int i, tmp, n;
	for (i = 0; i < 3; ++i) {	/* 3 is vertical dimension of grid */
		for (tmp = 0; tmp < 3; ++tmp) {	/* 3 is horizontal dimension of grid */
			if (grid[n] == 1)
				printf("[%c]", symbol);
			else
				printf("[ ]");
			++n;
		}
		putchar('\n');
	}
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
