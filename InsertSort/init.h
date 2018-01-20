#pragma once
#define MaxSize 10
#define ElementTpe int

#include "iostream"
using namespace std;
struct Sort {
private:
	ElementTpe element[MaxSize];
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