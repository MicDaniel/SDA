#include<iostream>

using namespace std;

void printEgyptian(int numarator, int numitor) {
	if (numarator == 0 || numitor == 0)
		return;

	if (numitor % numarator == 0) {
		cout << "1/" << numitor / numarator;
		return;
	}

	if (numarator % numitor == 0) {
		cout << numarator / numitor;
		return;
	}

	if (numarator > numitor) {
		cout << numarator / numitor << " + ";
		printEgyptian(numarator % numitor, numitor);
		return;
	}

	int n = numitor / numarator + 1;
	cout << "1/" << n << " + ";

	printEgyptian(numarator * n - numitor * 1, numitor * n);
}

int main() {
	
	int numarator = 12;
	int numitor = 13;
	cout << "Egyptian Fraciton Representation of " << numarator << "/" << numitor << " is: \n";
	printEgyptian(numarator, numitor);
	return 0;
}