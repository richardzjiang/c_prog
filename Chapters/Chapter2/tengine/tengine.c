/* A chess engine, except for tic-tac-toe */

#include <stdio.h>
#define TRUE 1
#define FALSE 0

int minimax(int node, int depth, int maximizingPlayer);
int max(int a, int b);
int min(int a, int b);
int tree(int value, int depth, int maximizing);

main()
{
}

int tree(int value, int depth, int maximizing, int *p)
{
	int i;
	int grid[9];
	for (i = 0; i < 9; ++i)
		grid[i] = p[i];

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
