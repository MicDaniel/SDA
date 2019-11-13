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

bool solveKingUtil(int x, int y, int moves, int sol[N][N], int xMove[N], int yMove[N]) {

	if (moves == N * N)
		return true;

	int nextX, nextY;

	for (int i = 0; i < N; i++) {
		nextX = x + xMove[i];
		nextY = y + yMove[i];
		if (isSafe(nextX, nextY, sol) == true) {
			sol[nextX][nextY] = moves;
			if (solveKingUtil(nextX, nextY, moves+1, sol, xMove, yMove) == true)
				return true;
			else
				sol[nextX][nextY] = -1;
		}
	}

	return false;
}

void solveKing() {
	int sol[N][N];
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			sol[x][y] = -1;
		}
	}

	int xMove[N] = { 0, 1, 1, 1, 0, -1, -1, -1 };
	int yMove[N] = { -1, -1, 0, +1, +1, +1, 0, -1 };

	sol[0][0] = 0;
	if (solveKingUtil(0, 0, 1, sol, xMove, yMove) == true)
		printSol(sol);
	else {
		cout << "Nu exista solutie";
	}
}

int main() {
	solveKing();
	return 0;
}