#include<iostream>

using namespace std;

void swap(char* a, char* b) {
	char temp = *a;
	*a = *b;
	*b = temp;
}

void permutare(char* a, int left, int right) {
	int i;
	if (left == right)
		cout << a << '\n';
	else
		for (int i = left; i <= right; i++) {
			swap((a + left), (a + i));
			permutare(a, left + 1, right);
			swap((a + left), (a + i));
		}
}

int main() {
	char str[] = "abc";
	int n = strlen(str);
	permutare(str, 0, n - 1);
	return 0;
}

int getMaxGhinde(int m[][N], int g[][N], int initial_i, int initial_j) {
	for (int i = initial_i; i < N; i++) {
		for (int j = initial_j; j < N; j++) {
			int left = 0;
			int up = 0;
			if (i - 1 >= 0) {
				up = m[i - 1][j];
			}
			if (j - 1 >= 0) {
				left = m[i][j - 1];
			}
			m[i][j] = max(left, up) + g[i][j];
		}
	}
	return m[N - 1][N - 1];
}