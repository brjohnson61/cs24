// triangles.cpp - more recursive print functions
// Adam Gulliver Blake Johnson, 5/17/2016

#include <iostream>
using namespace std;

// recursively prints n asterisks ('*') on one line to cout
void stars(int n) {
	if (n > 0) {
		cout << '*';
		stars(n - 1);
	}

	// IMPLEMENT
}

// recursively prints rows of '*', first n, then n-1, ... 1
void triangle(int n) {
	if (n > 0) {
		stars(n);
		cout << endl;
		triangle(n - 1);
		}
	// IMPLEMENT
}

// recursively prints rows of '*' in reverse: 1, 2, ... n
void rtriangle(int n) {
	if (n > 0) {
		rtriangle(n - 1);
		stars(n);
		cout << endl;

	}

	// IMPLEMENT
}

int main() {
	int size;
	cout << "enter size:" << endl;
	cin >> size;

	//stars(size); // first test only; then delete
	//cout << endl;

	triangle(size);
	//cout << endl;

	rtriangle(size);
	//cout << endl;

	system("pause");

}