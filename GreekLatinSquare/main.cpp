//Greek-Latinian squre
//
//Orlov S. 27.05.19 
#include <iostream>

using namespace std;

struct qwer {
	int x;
	int y;
	qwer() : x(0), y(0) {};
	qwer(int newX, int newY) : x(newX), y(newY) { };
};

bool check(qwer**, int);
bool checkExistPair(qwer**, qwer, int);
bool operator == (qwer, qwer);

bool operator == (qwer a, qwer b) {
	if (a.x == b.x) {
		if (a.y == b.y) {
			return true;
		}
	}
	return false;
}

bool checkExistPair(qwer** A, qwer checkingPair, int n) {
	int counter = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (A[i][j] == checkingPair) {
				++counter;
				if (counter > 1) {
					return false;
				}
			}
		}
	}
	return true;
}

bool check(qwer** A, int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (!checkExistPair(A, A[i][j], n)) {
				return false;
			}
		}
	}
	return true;
}

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