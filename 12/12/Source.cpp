#include<iostream>

using namespace std;

void print(int startTime[], int finishTime[], int index, int counter) {
	cout << "Spectacolul " << counter << ": " << "incepe la " << startTime[index] << ", se termina la " << finishTime[index] << '\n';
}

void maximumNumberOfSpect(int startTime[], int finishTime[], int n) {
	int i = 0;
	int counter = 1;
	print(startTime, finishTime, 0, counter++);

	for (int j = 1; j < n; j++) {
		if (startTime[j] >= finishTime[i]) {
			print(startTime, finishTime, j, counter++);
			i = j;
		}
	}
}

int main() {
	int startTime[] = { 1, 3, 0, 5, 8, 5 };
	int finishTime[] = { 2, 4, 6, 7, 9, 9 };
	int n = 6;
	maximumNumberOfSpect(startTime, finishTime, n);
	return 0;
}