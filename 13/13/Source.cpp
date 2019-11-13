#include<iostream>
#include<stack>

using namespace std;

void verificareParanteze(string st) {
	stack<char> stiva;
	bool isOk = true;
	string::iterator i;
	for (i = st.begin(); i < st.end(); i++) {
		char ch = *i;

		switch (ch)
		{
		case '{':
		case'[':
		case'(':
			stiva.push(ch);
			break;
		case'}':
			if (stiva.top() != '{')
				isOk = false;
			else
				stiva.pop();
			break;
		case']':
			if (stiva.top() != '[')
				isOk = false;
			else stiva.pop();
			break;
		case')':
			if (stiva.top() != '(')
				isOk = false;
			else
				stiva.pop();
			break;
		default:
			break;
		}
	}

	if (isOk == true)
		cout << st << " - Parantezele se inchid corect\n";
	else
		cout << st << " - Parantezele nu se inchid corect\n";
}

int main() {

	string s = "a{ b[c]d }e";
	verificareParanteze(s);
	s = "c[d]";
	verificareParanteze(s);
	s = "a{b(c]d}e";
	verificareParanteze(s);
	return 0;
}