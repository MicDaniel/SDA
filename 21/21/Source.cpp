#include<iostream>

using namespace std;

int ternarySearch(int arr[], int left, int right, int key) {
	if (right >= left) {
		int mid1 = left + (right - left) / 3;
		int mid2 = right - (right - left) / 3;

		if (arr[mid1] == key)
			return mid1;
		if (arr[mid2] == key)
			return mid2;
		if (key < arr[mid1]) {
			return ternarySearch(arr, left, mid1 - 1, key);
		}
		else if (key > mid2) {
			return ternarySearch(arr, mid2 + 1, right, key);
		}
		else{
			return ternarySearch(arr, mid1 + 1, mid2 - 1, key);
		}
	}

	return -1;
}

int main() {
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int p = ternarySearch(arr, 0, 10 - 1, 5);
	cout << p;
	p = ternarySearch(arr, 0, 10 - 1, 50);
	cout << p;
	return 0;
}