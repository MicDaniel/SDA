#include<iostream>
#include<conio.h>

using namespace std;

void merge(int v[], int left, int mid, int right);

void sort(int v[], int left, int right) {
	if (left >= right) {
		return;
	}

	int mid = left + (right - left) / 2;
	sort(v, left, mid);
	sort(v, mid + 1, right);
	merge(v, left, mid, right);
}

void merge(int v[], int left, int mid, int right) {
	int size_left = mid - left + 1;
	int size_right = right - mid;
	int Left[100], Right[100];

	for (int i = 0; i < size_left; i++) {
		Left[i] = v[left + i];
	}

	for (int i = 0; i < size_right; i++) {
		Right[i] = v[mid + 1 + i];
	}

	int index_vector = left;
	int index_left = 0, index_right = 0;
	while (index_left < size_left && index_right < size_right) {
		if (Left[index_left] < Right[index_right]) {
			v[index_vector++] = Left[index_left++];
		}
		else
			if (Left[index_left] > Right[index_right]) {
				v[index_vector++] = Right[index_right++];
			}
			else
			{
				v[index_vector++] = Left[index_left++];
				v[index_vector++] = Right[index_right++];
			}
	}

	while (index_left < size_left) {
		v[index_vector++] = Left[index_left++];
	}
	
	while (index_right < size_right) {
		v[index_vector++] = Right[index_right++];
	}
}

int main() {

	int n, v[100];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v, 0, n-1);

	for (int i = 0; i < n; i++) {
		cout << v[i] << ' ';
	}

	_getch();
	return 0;
}