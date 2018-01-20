// InsertSort.cpp : �ӵ�ǰλ����ǰ��
//�ȶ���ʱ�临�Ӷ�O(n^2),�ռ临�Ӷ�O(1)

#include "stdafx.h"		//Ԥ���룬����Ҫ���±����ȶ����룬Ԥ����Ľ���ļ���projectName.pch
#include "iostream"
#include "init.h"
using namespace std;


int main()
{
	Sort insert;
	insert.Init();
	insert.Rank();
	insert.Print();
    return 0;
}


void Sort::Rank() {
	element[0] = -1;
	int k ;
	for (int j = 1; j < len; j++) {
		//����1:
		/*k = j;
		while (k>0 && element[k] > element[k + 1]) {
			element[0] = element[k + 1];
			element[k + 1] = element[k];
			element[k] = element[0];
			k--;
		}*/
		//����2:
		element[0] = element[j + 1];
		for (k = j; k>=0 && element[k] > element[0]; k--) {
			element[k + 1] = element[k];
		}
		element[k+1] = element[0];
	}
}
