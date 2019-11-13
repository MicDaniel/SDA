#include<iostream>

using namespace std;

void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int arr[], int low, int high) {
	int pivot = arr[high];
	int i = low - 1;

	for (int j = low; j <= high - 1; j++) {
		if (arr[j] <= pivot) {
			i++;
			swap(&arr[i], &arr[j]);
		}
	}

	swap(&arr[i + 1], &arr[high]);
	return i + 1;
}

void quickSort(int arr[], int low, int high) {
	if (low < high) {
		int pi = partition(arr, low, high);

		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

void print(int arr[], int n) {
	for (int i = 0; i < n; i++)
		cout << arr[i] << ' ';
	cout << '\n';
}

void suma(int arr[], int n) {
	int p = 0;
	for (int i = 1; i < n; i++) {
		p += arr[i] * arr[i - 1];
	}
	p += arr[0] * arr[n - 1];
	cout << p<<'\n';
}

void cerc(int arr[], int n) {
	int nr[100];
	for (int j = 0; j < n; j++) {
		nr[j] = arr[j];
	}
	int i = n - 1;
	int k = 0;


	while (i > 0) {
		arr[k++] = nr[i--];
		arr[n - k] = nr[i--];
	}
}
int main() {

	int arr[10] = { 1, 8, 3, 2, 5, 4 };
	print(arr, 6);
	cout << "suma: ";
	suma(arr, 6);

	quickSort(arr, 0, 5);
	cout << "Sorted array: ";
	print(arr, 6);
	cout << "suma: ";
	suma(arr, 6);

	cerc(arr, 6);
	cout << "Final array: ";
	print(arr, 6);
	cout << "suma: ";
	suma(arr, 6);
	return 0;
}