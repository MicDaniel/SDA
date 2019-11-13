#include<iostream>

#define V 4 // numar tari

using namespace std;

void printSol(int colorArray[]) {
	cout << "Solutia este:\n";
	for (int i = 0; i < V; i++)
		cout << colorArray[i];
}

bool isSafe(bool map[V][V], int zona, int color, int colorArray[]) {
	for (int i = 0; i < V; i++) {
		if (map[zona][i] && color == colorArray[i])
			return false;
		return true;
	}
}

bool mapColoringUtil(bool map[V][V], int zona, int nrCulori, int colorArray[]) {
	if (zona == V)
		return true;// toate tarile au asignate culori
	for (int c = 1; c <= nrCulori; c++) {
		if (isSafe(map, zona, c, colorArray) == true) {
			colorArray[zona] = c;

			if (mapColoringUtil(map, zona++, nrCulori, colorArray) == true)
				return true;
			colorArray[zona] = 0;
		}
	}

	return false;
}

bool mapColoring(bool map[V][V], int nrCulori) {
	int* colorArray = new int[V];
	for (int i = 0; i < V; i++) {
		colorArray[i] = 0;
	}

	if (mapColoringUtil(map, 0, nrCulori, colorArray) == false) {
		cout << "Solutia nu exista";
		return false;
	}

	
	printSol(colorArray);
	return true;
}

int main() {

	bool map[V][V] = {
		{ 0, 1, 1, 1 },
		{ 1, 0, 1, 0 },
		{ 1, 1, 0, 1 },
		{ 1, 0, 1, 0 }
	};

	int nrCulori = 3;
	

	return 0;
}