#include<iostream>
#include<conio.h>

using namespace std;

void egyptianFraction(int nr, int dr) {
	if (nr == 0 || dr == 0)
		return;
	
	if (nr%dr == 0) {
		cout << nr / dr;
		return;
	}

	if (dr%nr == 0) {
		cout << "1/" << dr / nr;
		return;
	}

	if (nr>dr) {
		cout << nr / dr << " + ";
		egyptianFraction(nr%dr, dr);
		return;
	}

	int number = dr / nr + 1;
	cout << "1/" << number << '+';
	egyptianFraction(nr*number - dr, dr*number);
}

int main() {
	int nr = 7, dr = 3;
	cout << "Egyptian Fraction Representation of "
		<< nr << "/" << dr << " is\n ";
	egyptianFraction(nr, dr);
	_getch();
	return 0;
}