//Greaco-Latin squre
//
//Orlov S. 27.05.19 
//
//Laboratory work on the discipline "Algorithms and data structures"

#include <iostream>
#include "definitions.h"

using namespace std;

int main()
{
	int n = 5;
	int a;

	cout << "number > " << n << endl;
	//cin >> n;

	int** sq1 = new int* [n];
	int** sq2 = new int* [n];
	qwer** greekLatin = new qwer* [n];

	for (int i = 0; i < n; ++i) {
		sq1[i] = new int[n];
		sq2[i] = new int[n];
		greekLatin[i] = new qwer[n];
	}

	for (int i = 0; i < n; ++i) {
		a = i + 1;
		for (int j = 0; j < n; ++j) {
			sq1[i][j] = a;
			a++;
			if (a > n) {
				a = 1;
			}
		}
	}
	
	for (int i = 0; i < n; ++i) {
		a = i + 1;
		for (int j = 0; j < n; ++j) {
			sq2[i][j] = a;
			a--;
			if (a <= 0) {
				a = n;
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			greekLatin[i][j].x = sq1[i][j];
			greekLatin[i][j].y = sq2[i][j];
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << '<' << greekLatin[i][j].x << ',' << greekLatin[i][j].y << '>' << ' ';
		}
		cout << endl;
	}

	if (check(greekLatin, n)) {
		cout << endl << "it's true Greek-Latin square!" << endl;
	} else {
		cout << endl << "it isn't Greek-Latin square!" << endl;
	}

	qwer** random = new qwer* [n];
	for (int i = 0; i < n; ++i) {
		random[i] = new qwer[n];
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			random[i][j] = qwer(rand() % n, rand() % n);
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << '<' << random[i][j].x << ',' << random[i][j].y << '>' << ' ';
		}
		cout << endl;
	}
	if (check(random, n)) {
		cout << endl << "it's true Greek-Latin square!" << endl;
	}
	else {
		cout << endl << "it isn't Greek-Latin square!" << endl;
	}

	for (int i = 0; i < n; ++i) {
		delete[] sq1[i];
		delete[] sq2[i];
		delete[] greekLatin[i];
		delete[] random[i];
	}

	delete[] sq1;
	delete[] sq2;
	delete[] greekLatin;
	delete[] random;
}