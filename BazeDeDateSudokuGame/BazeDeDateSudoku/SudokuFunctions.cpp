#include"SudokuFunctions.h"


bool solveSudoku(int matrix[N][N]) {
	int row, col;

	if (!findEmptyCells(matrix, row, col)) {
		return true;//am terminat jocul
	}

	for (int i = 1; i <= 9; i++) {
		if (isSafe(matrix, row, col, i)) {
			matrix[row][col] = i;

			if (solveSudoku(matrix))
				return true;

			matrix[row][col] = empty;
		}
	}

	return false; // nu exista solutie
}

bool findEmptyCells(int matrix[N][N], int & x, int & y)
{
	for (x = 0; x < N; x++) {
		for (y = 0; y < N; y++) {
			if (matrix[x][y] == empty)
				return true;
		}
	}
	return false;
}

bool isSafe(int matrix[N][N], int x, int y, int number) {
	if (checkRow(matrix, x, number) &&
		checkCol(matrix, y, number) &&
		checkBox(matrix, x - x%3, y - y%3, number) &&
		matrix[x][y] == empty)
		return true;
	return false;
}

bool checkRow(int matrix[N][N], int x, int number)
{
	for (int y = 0; y < N; y++) {
		if (matrix[x][y] == number)
			return false;
	}
	return true;
}

bool checkCol(int matrix[N][N], int y, int number)
{
	for (int x = 0; x < N; x++) {
		if (matrix[x][y] == number)
			return false;
	}
	return true;
}

bool checkBox(int matrix[N][N], int boxX, int boxY, int number)
{
	for (int x = 0; x < 3; x++) {
		for (int y = 0; y < 3; y++) {
			if (matrix[boxX + x][boxY + y] == number)
				return false;
		}
	}
	return true;
}

void print(int matrix[N][N])
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << matrix[i][j] << ' ';
		}
		cout << '\n';
	}
}
