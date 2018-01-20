#pragma once
#ifndef IOSTREAM_H
#include "iostream"
using namespace std;
#endif // !IOSTREAM_H


#define MaxSize 10
#define ElementType int

struct Sort {
private:
	ElementType element[MaxSize];
	int len;
public:
	void Init();
	void Rank();
	void Print();
};

void Sort::Init() {
	cin >> len;
	for (int i = 1; i <= len; i++) {
		cin >> element[i];
	}
}


void Sort::Print() {
	for (int i = 1; i <= len; i++) {
		cout << element[i] << "  ";
	}
	cout << endl;
}