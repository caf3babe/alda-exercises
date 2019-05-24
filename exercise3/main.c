#include <stdio.h>
#include "sudoku.h"
#include "sudoku.c"

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
	printf("Sudoku to solve: \n");
	print();

	if(solve(0,0)){
        print();
	} else {
	    printf("No solution found :-( \n");
	}

    print();


   return 0;
}
