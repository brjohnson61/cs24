// alph.cpp - some recursive print functions
// Blake Johnson Adam Gulliver, 5/17/16

#include <iostream>
using namespace std;

// recursively prints letter sequence 'a'..c
void alph(char c) {
	if (islower(c)) {
		if (c > 'a')
			alph(c - 1);
		cout << c;
	}
}

// recursively prints letter sequence c..'a'
void ralph(char c) {
	if (islower(c)) {
		if (c > 'a') {
			cout << c;
			ralph(c - 1);
		}
		else
			cout << 'a';
	}
	// IMPLEMENT
}

// recursively prints letter sequence c..'z'
void zalph(char c) {
	if (islower(c)) {
		if (c < 'z') {
			cout << c;
			zalph(c + 1);
		}
		else
			cout << 'z';
			
	
	}
	// IMPLEMENT
}

// recursively prints letter sequence 'z'..c
void zralph(char c) {
	if (islower(c)) {
		if (c < 'z')
			zralph(c + 1);
		cout << c;
		// IMPLEMENT
	}
}

int main() {
	char letter;
	cout << "enter letter:" << endl;
	cin >> letter;

	alph(letter);
	cout << endl;

	ralph(letter);
	cout << endl;

	zalph(letter);
	cout << endl;

	zralph(letter);
	cout << endl;
	system("pause");
	return 0;
}