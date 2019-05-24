/*
 *  Sudoku.h
 *  sudoku
 *
 *  Created by Juergen Falb and Michael Strommer on 19.02.08.
 *
 */

#ifndef _SUDOKU_H_
#define _SUDOKU_H_

#define SIZE 9
#define SQRT_SIZE 3

void init(int begin[SIZE][SIZE]);
void print();
int checkValueInField(int value, int row, int col);
int setValueInField(int value, int row, int col);
int removeValueFromField(int row, int col);
int getValueFromField(int row, int col);
int solve(int row, int col);

#endif /* _SUDOKU_H_ */
