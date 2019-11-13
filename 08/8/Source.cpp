#include<iostream>

using namespace std;

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

bool isSafe(int* a, int left, int right) {
	for (left; left <= right; left++) {
		if (a[left]%2 == 0 && a[left] != left)
			return false;
	}
	return true;
}

void permutation(int* a, int left, int right) {
	if (left == right && isSafe(a,0,right)){
		for (int i = 0; i <= right; i++) {
			cout << a[i] << ' ';
		}
		cout << '\n';
	}
	else {
		for (int i = left; i <= right; i++) {
				swap((a + left), (a + i));
				permutation(a, left + 1, right);
				swap((a + left), (a + i));
		}
	}
}

int main() {
	int arr[] = { 1,2,3 };
	int n = 3;
	permutation(arr, 0, n - 1);
	return 0;
}