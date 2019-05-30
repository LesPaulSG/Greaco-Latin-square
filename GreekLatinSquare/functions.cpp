#include "definitions.h"

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