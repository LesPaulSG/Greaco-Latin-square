//Greaco-Latin squre
//
//Orlov S. 27.05.19 
//
//Laboratory work on the discipline "Algorithms and data structures"

#include <iostream>
#include <ctime>
#include "definitions.h"

using namespace std;

int main()
{
	int n, a;

	cout << "number > ";
	cin >> n;

	int** sq1 = new int* [n];   
	int** sq2 = new int* [n];
	qwer** greacoLatin = new qwer* [n];
	qwer** randomSq = new qwer * [n];

	for (int i = 0; i < n; ++i) {           //generation second layer dynamic arrays
		sq1[i] = new int[n];
		sq2[i] = new int[n];
		greacoLatin[i] = new qwer[n];
		randomSq[i] = new qwer[n];
	}

	for (int i = 0; i < n; ++i) {			//generation Latin square sq1
		a = i + 1;
		for (int j = 0; j < n; ++j) {
			sq1[i][j] = a;
			a++;
			if (a > n) a = 1;
		}
	}
	
	for (int i = 0; i < n; ++i) {			//generation ortogonal to sq1 square sq2
		a = i + 1;
		for (int j = 0; j < n; ++j) {
			sq2[i][j] = a;
			a--;
			if (a <= 0) a = n;
		}
	}

	for (int i = 0; i < n; ++i) {			//combination sq1 and sq2 to Greaco-Latin square
		for (int j = 0; j < n; ++j) {
			greacoLatin[i][j] = qwer(sq1[i][j], sq2[i][j]);
		}
	}

	srand(time(0));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			randomSq[i][j] = qwer(rand() % n, rand() % n);
		}
	}

	print(greacoLatin, n);
	check(greacoLatin, n);

	print(randomSq, n);
	check(randomSq, n);

	for (int i = 0; i < n; ++i) {
		delete[] sq1[i], sq2[i], greacoLatin[i], randomSq[i];
	}

	delete[] sq1, sq2, greacoLatin, randomSq;
}