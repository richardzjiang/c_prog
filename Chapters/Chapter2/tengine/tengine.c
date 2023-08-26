/* A chess engine, except for tic-tac-toe. I guess it's a tic-tac-toe engine? tengine for short */

#include <stdio.h>
#include <math.h>
#define TRUE 1
#define FALSE 0
#define GOODOCCUPIED 1	/* occupied by engine */
#define BADOCCUPIED 2	/* occupied by opponent */
#define UNOCCUPIED 0
#define DEPTH 5


//int minimax(int node, int depth, int maximizingPlayer);
int max(int a, int b);
int min(int a, int b);
int tree(int value, int depth, int maximizing, int *grid);
int bestmove(int depth, int *grid);
int eval(int pos, int *grid);
int printgrid(int *grid, char playersymbol, char computersymbol);
int openingbook();

main()
{
	int i;
	int tmp;
	int grid[9];
	char playersymbol;
	char computersymbol;
	int playerturn;
	int computerturn;
	int movestaken;	/* number of moves taken by both the engine and the opponent(the person that plays against the engine) */

	for (i = 0; i < 9; ++i)
		grid[i] = UNOCCUPIED;	/* starting value of unoccupied slots in the grid array must be zero */

	while (playersymbol != 'X' && playersymbol != 'O') {
		printf("Choose a symbol: ");
		scanf("%c", &playersymbol);
	}

	if (playersymbol == 'O') {
		computersymbol = 'X';
		grid[openingbook()] = GOODOCCUPIED;	/* in tictactoe, X goes first */
		++movestaken;
		computerturn = FALSE;
		playerturn = TRUE;
	} else {
		computerturn = FALSE;
		playerturn = TRUE;
		computersymbol = 'O';
	}

	printgrid(grid, playersymbol, computersymbol);
	while (movestaken < 9) {
		if (computerturn == TRUE) {
			tmp = bestmove(DEPTH, grid);
			grid[tmp] = GOODOCCUPIED;
		}
		else if (playturn == TRUE) {
			printf("Enter your move (enter a number 1-9): ");
			scanf("%d", &tmp);
			grid[tmp] = BADOCCUPIED;
		}
		printgrid(grid, playersymbol, computersymbol);
	}
}

/* tree: a function that is incredibly similar to the minimax function that I definitely did not copy off of wikipedia */
/* I believe that the "difficulty" of the engine can be modified by changing the value of depth. Higher values means that the engine is "smarter" */
int tree(int value, int depth, int maximizing, int *grid)
{
	int i;
	int tmp[9];	/* used in the input for eval() */
	for (i = 0; i < 9; ++i)
		tmp[i] = grid[i];
	if (depth == 0)
		return value;	/* i think */
	if (maximizing) {	/* my turn. */
		value = -INFINITY;	/* I belive that this macro is defined in math.h. value is neg infinity. After this for loop, value will be equal to the play that has the highest value */
		for (i = 0; i < 9; ++i)
			if (grid[i] == UNOCCUPIED) {
				grid[i] = GOODOCCUPIED;
				value = max(value, tree(eval(i, tmp), depth - 1, FALSE, grid));
				grid[i] = UNOCCUPIED;	/* makes sure to not permanently change the values of grid */
			}
		return value;
	} else {	/* opponent's turn. minimizing (least good for me). If it is the least good for me, then the opponent will probably play it */
		/* value is pos infinity */
		value = INFINITY;	/* INFINITY is defined in math.h I think */
		for (i = 0; i < 9; ++i)
			if (grid[i] == UNOCCUPIED) {
				grid[i] = BADOCCUPIED;
				value = min(value, tree(eval(i, tmp), depth - 1, TRUE, grid));
				grid[i] = UNOCCUPIED;	/* makes sure to not permanently change the values of grid */
			}	
		return value;
	}
}

/* bestmove: using the tree function, bestmove calculates the best move for the computer to take */
int bestmove(int depth, int *grid)
{
	int i;
	int value;

	value = -INFINITY;

	for (i = 0; i < 9; ++i)
		if (grid[i] == UNOCCUPIED)
			value = max(value, tree(eval(i, grid), depth, FALSE, grid));
	return value;
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
int eval(int pos, int *grid)
{
	int value;

	if (grid[pos] == GOODOCCUPIED || grid[i] == BADOCCUPIED)	/* the grid position that is to be evaluated is already occupied */
		return -INFINITY;	/* cuz playing in a position that is already occupied is a dogwater decision */

	switch (pos) {	/* this value calculation statement could probably be changed tbh (it's not very accurate) */
		case 0: value = grid[1] + grid[3] + grid[4] + grid[2] + grid[6] + grid[7];
		case 1: value = grid[0] + grid[2] + grid[4] + grid[7];
		case 2: value = grid[1] + grid[4] + grid[5] + grid[0] + grid[6] + grid[8];
		case 3: value = grid[0] + grid[4] + grid[6] + grid[5];
		case 4: value = grid[0] + grid[1] + grid[2] + grid[3] + grid[4] + grid[5] + grid[6] + grid[7] grid[8];
		case 5: value = grid[2] + grid[4] + grid[8] + grid[3];
		case 6: value = grid[3] + grid[4] + grid[7] + grid[0] + grid[2] + grid[8];
		case 7: value = grid[4] + grid[6] + grid[8] + grid[1];
		case 8: value = grid[4] + grid[5] + grid[7] + grid[0] + grid[2] + grid[6];
	}
	return value;
}

/* printgrid: receive the array containing the tic-tac-toe grid data as input, and print the grid. symbol can be X or O (or something else even) */
printgrid(int *grid, char playersymbol, char computersymbol)
{
	int i, tmp;
	int n = 0;

	putchar('\n');	/* for aesthetic reason */
	for (i = 0; i < 3; ++i) {	/* 3 is vertical dimension of grid */
		for (tmp = 0; tmp < 3; ++tmp) {	/* 3 is horizontal dimension of grid */
			if (grid[n] == GOODOCCUPIED)
				printf("[%c]", computersymbol);
			else if (grid[n] == BADOCCUPIED)
				printf("[%c]", playersymbol);
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

int openingbook
