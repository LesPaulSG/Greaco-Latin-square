#include "definitions.h"
#include <iostream>

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

void check(qwer** A, int n) {
	bool realGLS = true;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (!checkExistPair(A, A[i][j], n)) {
				realGLS = false;
				break;
			}
		}
	}
	if (realGLS) {
		std::cout << std::endl << "it's true Greek-Latin square!" << std::endl;
	} else {
		std::cout << std::endl << "it isn't Greek-Latin square!" << std::endl;
	}
}

void print(qwer** A, int n) {
	std::cout << std::endl;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			std::cout << '<' << A[i][j].x << ',' << A[i][j].y << '>' << ' ';
		}
		std::cout << std::endl;
	}
}