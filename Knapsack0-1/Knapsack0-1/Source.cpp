#include<iostream>

using namespace std;

int max(int a, int b) { return (a > b) ? a : b; }

int knapsack(int Weight, int weight[], int value[], int n) {
	if (Weight == 0 || n == 0)
		return 0;
	
	if (weight[n - 1] > Weight)
		return knapsack(Weight, weight, value, n - 1);
	else
		return max(value[n - 1] + knapsack(Weight - weight[n - 1], weight, value, n - 1),
			knapsack(Weight, weight, value, n - 1));
}

int main() {
	int value[] = { 60,100,120 };
	int weight[] = { 10,20,30 };
	int Weight = 50;
	int n = sizeof(value) / sizeof(value[0]);
	cout << knapsack(Weight, weight, value, n);
	return 0;
}