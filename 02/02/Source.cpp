#include<iostream>
#define N 8

using namespace std;

void printSol(int sol[N][N]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << sol[i][j] << ' ';
		cout << '\n';
	}
}

bool isSafe(int x, int y, int sol[N][N]) {
	return (x >= 0 && x < N && y >= 0 && y < N && sol[x][y] == -1);
}

bool knightsTourUtil(int x, int y, int moves, int sol[N][N], int xMoves[], int yMoves[]) {
	if (moves == N * N) {
		return true;
	}

	for (int i = 0; i < N; i++) {
		int nextX = x + xMoves[i];
		int nextY = y + yMoves[i];

		if (isSafe(nextX, nextY, sol) == true) {
			sol[nextX][nextY] = moves;
			if (knightsTourUtil(nextX, nextY, moves+1, sol, xMoves, yMoves) == true)
				return true;
			else
				sol[nextX][nextY] = -1;
		}
	}
	return false;
}

void knightsTour() {

	int sol[N][N];
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			sol[x][y] = -1;
		}
	}

	sol[0][0] = 0;

	int xMoves[N] = { 2, 1, -1, -2, -2, -1,  1,  2 };
	int yMoves[N] = { 1, 2,  2,  1, -1, -2, -2, -1 };

	if (knightsTourUtil(0, 0, 1, sol, xMoves, yMoves) == true)
		printSol(sol);
	else
		cout << "Solutia nu exista";
}

int main() {

	knightsTour();
	return 0;
}