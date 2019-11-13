#include<iostream>

using namespace std;

bool isSafe(int data[], int index) {
	if (data[index - 1] == 1)
		return false;
	return true;
}

void combinariUtil(int data[], int n, int index) {
	if (index == n)
	{
		for (int i = 0; i < n; i++)
			cout << data[i] << ' ';
		cout << '\n';
		return;
	}
	data[index] = 0;
	combinariUtil(data, n, index + 1);
	if (isSafe(data, index) == true) {
		data[index] = 1;
		combinariUtil(data, n, index + 1);
	}
}
void combinari(int n) {
	int data[10];
	combinariUtil(data, n, 0);
}

int main() {
	int n;
	cin >> n;
	combinari(n);
	return 0;
}