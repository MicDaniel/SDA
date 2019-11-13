#include<iostream>
#include<math.h>
#include<vector>

using namespace std;

void bani(int S,int n,int e,int arr[],int counter) {
	vector<int> answer;

	for (int i = n; i >= 0; i--) {
		while (S >= arr[i]) {
			S -= arr[i];
			answer.push_back(arr[i]);
			counter++;
		}
	}
	
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << ' ';
	}
	cout<<"S-au folosit "<< counter<<" bancnote";
}

void currency(int n, int e, int arr[]) {
	for (int i = 0; i <= n; i++) {
		arr[i] =(int) pow(e, i);
	}
}

int main() {

	int S = 53;
	int e = 2;
	int n = 10;
	int arr[100];
	currency(n, e, arr);
	bani(S, n, e, arr, 0);
	return 0;
}