//#include<iostream>
//#include<conio.h>
//
//using namespace std;
//
//}void swap(char *x, char *y)
//{
//	char temp;
//	temp = *x;
//	*x = *y;
//	*y = temp;
//}
//
//void permute(char *a, int l, int r)
//{
//	int i;
//	if (l == r) {
//		
//		printf("%s\n", a);
//	}
//	else
//	{
//		for (i = l; i <= r; i++)
//		{
//			swap((a + l), (a + i));
//			permute(a, l + 1, r);
//			swap((a + l), (a + i)); //backtrack 
//		}
//	}
//}
//
//int main() {
//	_getch();
//	return 0;
//}
//
//

#include<stdio.h>

#define V 4

void printSolution(int color[]);

bool isSafe(int v, bool map[V][V], int color[], int c) {
	for (int i = 0; i < V; i++)
		if (map[V][i] && c == color[i])
			return false;
		return true;
}

bool mapColoringUtil(bool map[V][V], int m, int color[], int v) {
	if (v == V)
		return true;
	for (int c = 1; c <= m; c++) {
		if (isSafe(v, map, color, c)) {
			color[v] = c;
			
			if (mapColoringUtil(map, m, color, v + 1) == true)
				return true;
			color[v] = 0;
		}
	}
	return false;
}

bool mapColoring(bool map[V][V], int m) {
	int *color = new int[V];
	for (int i = 0; i < V; i++)
		color[i] = 0;

	if (mapColoringUtil(map, m, color, 0) == false) {
		printf("solutia nu exista");
		return false;
	}

	printSolution(color);
	return true;
}

void printSolution(int color[]) {
	printf("sol exista:");
	for (int i = 0; i < V; i++)
		printf("%d", color[i]);
	printf("\n");
}