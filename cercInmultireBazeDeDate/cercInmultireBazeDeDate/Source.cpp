#include<iostream>
#include<conio.h>

using namespace std;


void sortAsc(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] > arr[j]) {
				int aux = arr[j];
				arr[j] = arr[i];
				arr[i] = aux;
			}
		}
	}
}

void print(int arr[], int n) {
	for (int i = 0; i < n; i++)
		cout << arr[i] << ' ';
	cout << '\n';
}

void inmultire(int arr[], int n) {
	int p = 0;
	for(int i = 1; i < n; i++) {
		p += arr[i] * arr[i - 1];
	}
	p += arr[0] * arr[n - 1];
	cout << "\n" << p;
}

int main() {
	int n = 6;
	int numbers[100] = {1,3,2,4,5,8};
	int arr[100];
	sortAsc(numbers, n);
	print(numbers, n);
	
	for (int i = 0; i < n; i++) {
		arr[i] = numbers[i];
	}
	
	int i = n - 1, k = 0;
	while (i > 0) {
		numbers[k++] = arr[i--];
		numbers[n - k] = arr[i--];
	}
	
	cout << "The final array:\n";
	print(numbers, n);
	inmultire(numbers, n);
	_getch();
	return 0;
}