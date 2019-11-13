#include<iostream>

using namespace std;

int max(int a, int b) {
	return (a > b) ? a : b;
}

int cutRod(int price[], int n) {
	int* val = new int[n];
	val[0] = 0;
	int i, j;

	for (i = 1; i <= n; i++) {
		int maxValue = INT_MIN;
		for (j = 0; j < i; j++)
			maxValue = max(maxValue, price[j] + val[i - j - 1]);
		val[i] = maxValue;
	}

	return val[n];
}

int main() {

	return 0;
}