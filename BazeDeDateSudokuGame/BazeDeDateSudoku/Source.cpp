#include"SudokuFunctions.h"

int main() {
	int matrix[N][N] = { {5, 0, 7, 0, 9, 3, 3, 6, 0},
					 {0, 6, 0, 3, 4, 0, 0, 0, 0},
					 {2, 0, 1, 7, 0, 0, 9, 0, 0},
					 {0, 0, 0, 0, 0, 6, 2, 7, 0},
					 {6, 0, 0, 2, 0, 3, 0, 0, 4},
					 {0, 1, 2, 4, 0, 0, 0, 0, 0},
					 {0, 0, 5, 0, 0, 4, 7, 0, 6},
					 {0, 0, 0, 0, 2, 8, 0, 5, 0},
					 {0, 9, 4, 0, 5, 0, 1, 0, 2} };

	if (solveSudoku(matrix)) {
		print(matrix);
	}
	else
		cout << "No solution";

	_getch();
	return 0;
}


//{0, 0, 0, 0, 0, 0, 0, 0, 0},
//{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
//{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
//{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
//{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
//{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
//{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
//{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
//{ 0, 0, 0, 0, 0, 0, 0, 0, 0 }