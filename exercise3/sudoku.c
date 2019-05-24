/*
 *  Sudoku.cpp
 *  sudoku
 *
 *  Created by Juergen Falb and Michael Strommer on 19.02.08.
 *
 */

#include "sudoku.h"
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>


int field[SIZE][SIZE];
int initial[SIZE][SIZE];

typedef struct {
    int row;
    int col;
} Cell;


/* Initializes the sudoku array.
 * The field initial keeps the original start value for
 * figuring out if a value is fixed or can be changed. */
void init(int begin[SIZE][SIZE]) {
    memcpy(field, begin, SIZE * SIZE * sizeof(int));
    memcpy(initial, begin, SIZE * SIZE * sizeof(int));
}

/* really pretty prints the sudoku array */
void print() {
    int row, col;
    // print the first line
    printf("||");
    for (col = 0; col < SIZE - 1; col++) {
        if (col % SQRT_SIZE == SQRT_SIZE - 1)
            printf("===++");
        else
            printf("===+");
    }
    printf("===||\n");
    // loop through all rows of the array
    for (row = 0; row < SIZE; row++) {
        // print the line with field values
        for (col = 0; col < SIZE; col++) {
            if (col % SQRT_SIZE == 0)
                printf("|| ");
            else
                printf("| ");
            if (field[row][col] == 0)
                printf("  ");
            else
                printf("%d ", field[row][col]);
        }
        // print the separation line;
        // depending on the result of the modulo operation
        // print a single or double line
        printf("||\n||");
        if (row % SQRT_SIZE == SQRT_SIZE - 1) {
            for (col = 0; col < SIZE - 1; col++) {
                if (col % SQRT_SIZE == SQRT_SIZE - 1)
                    printf("===++");
                else
                    printf("===+");
            }
            printf("===||\n");
        } else {
            for (col = 0; col < SIZE - 1; col++) {
                if (col % SQRT_SIZE == SQRT_SIZE - 1)
                    printf("---++");
                else
                    printf("---+");
            }
            printf("---||\n");
        }
    }
}

/* Checks if the value is valid and can be set into the field.
 * The function returns false if the value is already present or
 * has been one of the initial values. */
int checkValueInField(int value, int row, int col) {
    int i, r, c;
    int squareRow;
    int squareCol;
    // checks for initial values
    if (initial[row][col] != 0) {
        if (initial[row][col] == value)
            return 1;
        else
            return 0;
    }

    // check horizontally
    for (i = 0; i < SIZE; i++) {
        if (field[row][i] == value) return 0;
    }

    // check vertically
    for (i = 0; i < SIZE; i++) {
        if (field[i][col] == value) return 0;
    }

    // check square
    squareRow = row / SQRT_SIZE;
    squareCol = col / SQRT_SIZE;
    for (r = squareRow * SQRT_SIZE; r < squareRow * SQRT_SIZE + SQRT_SIZE; r++) {
        for (c = squareCol * SQRT_SIZE; c < squareCol * SQRT_SIZE + SQRT_SIZE; c++) {
            if (field[r][c] == value) return 0;
        }
    }

    return 1;
}

/* Set a value in the sudoku field if the field is empty.
 * The method returns false if the field contains a fixed number. */
int setValueInField(int value, int row, int col) {
    if (initial[row][col] == 0) {
        field[row][col] = value;
        return 1;
    } else if (initial[row][col] == value)
        return 1;
    return 0;
}

/* Removes a value in the sudoku field if it doesn't contain an initial value.
 * The method returns false if the field contains a fixed number and cannot be
 * removed. */
int removeValueFromField(int row, int col) {
    if (initial[row][col] == 0) {
        field[row][col] = 0;
        return 1;
    }
    return 0;
}

/* Returns the value in the field */
int getValueFromField(int row, int col) {
    return field[row][col];
}

/* Return true if you've found a valid solution for the sudoku. Use the
 * return value to abort the backtracking algorithm if you've found the
 * first solution, otherwise you would search for a possible solution. */
/*int solve(int row, int col) {
    if(col == SIZE){
        if(row >= SIZE){
            return 1;
        }
        col = col%SIZE;
        row++;
    }

    if(getValueFromField(row,col) == 0 ){
        int candidateValue = 1;
        while(candidateValue <= SIZE){
            if(candidateValue == SIZE){
                removeValueFromField(row,col);
                return FALSE;
            }
            if(checkValueInField(candidateValue,row,col)){
                setValueInField(candidateValue,row,col);
                if(!solve(row,col+1)){
                    removeValueFromField(row,col);
                    return FALSE;
                }
            }
            candidateValue++;
        }
    } else {
        if(!solve(row,col+1)){
            return FALSE;
        } else {
            return TRUE;
        }
    }
	return TRUE;
}*/

int solve(int row, int col) {
    int candidateValue = 1;
    while (candidateValue <= SIZE) {
        if (checkValueInField(candidateValue, row, col)) {
            setValueInField(candidateValue, row, col);
            if (col == SIZE - 1 && row == SIZE - 1) {
                return 1;
            } else if (row < SIZE && col == SIZE - 1) {
                if (solve(row + 1, 0)) {
                    return 1;
                }
            } else if (col < SIZE) {
                if (solve(row, col + 1)) {
                    return 1;
                }
            }
        }

        candidateValue++;
    }
    removeValueFromField(row, col);
    return 0;
}
