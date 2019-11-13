#include<iostream>
#include<conio.h>
#include<string>

using namespace std;

int main() {
	string s;
	cout << "Enter string: ";
	getline(cin, s);
	
	cout << s << '\n';

	char caracter, caracterNou;
	cin >> caracter >> caracterNou;

	string::iterator i;

	for (i = s.begin(); i != s.end(); i++)
	{
		if (s[*i] == caracter) {
			s[*i] = caracterNou;
		}

	}

	cout << s << '\n';
	_getch();
	return 0;
}