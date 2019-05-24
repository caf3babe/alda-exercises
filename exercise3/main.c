#include <stdio.h>
#include "sudoku.h"

int main (int argc, char * const argv[]) {
	int initial[SIZE][SIZE] = {
		{0, 1, 0, 0, 0, 9, 0, 5, 0},
		{0, 9, 0, 0, 0, 0, 4, 8, 0},
		{0, 6, 0, 1, 0, 4, 0, 0, 0},
		{0, 0, 5, 0, 0, 0, 9, 3, 0},
		{0, 0, 0, 7, 0, 2, 0, 0, 0},
		{0, 2, 1, 0, 0, 0, 8, 0, 0},
		{4, 0, 0, 0, 8, 0, 6, 0, 9},
		{0, 0, 0, 0, 6, 0, 5, 0, 3},
		{2, 0, 0, 0, 3, 0, 0, 0, 0},
	};

	init(initial);
	print();
	solve(0,0);
	print();

   return 0;
}
