#include<iostream>

using namespace std;

bool isSorted(int arr[], int n) {
	if (n == 0 || n == 1)
		return true;
	if (arr[n - 1] >= arr[n - 2])
		isSorted(arr, n - 1);
	else
		return false;
}

int main() {

	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int arr2[10] = { 1,2,3,4,5,6,8,7,10,9 };
	int arr3[10] = { 1,2,2,3,4,5,6,7,8,9 };

	if (isSorted(arr, 10) == true)
		cout << "true ";
	else
		cout << "false ";

	if (isSorted(arr2, 10) == true)
		cout << "true ";
	else
		cout << "false ";

	if (isSorted(arr3, 10) == true)
		cout << "true ";
	else
		cout << "false ";

	return 0;
}