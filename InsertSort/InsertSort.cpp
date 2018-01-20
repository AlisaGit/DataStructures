// InsertSort.cpp : 从当前位置往前比
//稳定，时间复杂度O(n^2),空间复杂度O(1)

#include "stdafx.h"		//预编译，不需要重新编译稳定代码，预编译的结果文件是projectName.pch
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
		//方法1:
		/*k = j;
		while (k>0 && element[k] > element[k + 1]) {
			element[0] = element[k + 1];
			element[k + 1] = element[k];
			element[k] = element[0];
			k--;
		}*/
		//方法2:
		element[0] = element[j + 1];
		for (k = j; k>=0 && element[k] > element[0]; k--) {
			element[k + 1] = element[k];
		}
		element[k+1] = element[0];
	}
}
