#pragma once
#ifndef DEFINITIONS_H
#define DEFINITIONS_H

struct qwer {
	int x;
	int y;
	qwer() : x(0), y(0) {};
	qwer(int newX, int newY) : x(newX), y(newY) { };
};

bool check(qwer**, int);
bool checkExistPair(qwer**, qwer, int);
bool operator == (qwer, qwer);


#endif // !DEFINITIONS_H

