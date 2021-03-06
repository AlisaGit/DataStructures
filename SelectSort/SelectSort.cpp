// SelectSort.cpp: 定义控制台应用程序的入口点。
//SelectSort是选出最小（或者最大）的一个数与第1个位置的数交换；然后在剩下的数当中再找
//最小（或者最大）的与第2个位置的数交换，依次类推，直到第n-1个元素（倒数第二个数）和第n个元素（最后一个数）比较为止
//本算法实现的是二路选择，即在选择的时候同时选择出最大和最小值

#include "stdafx.h"
#include "iostream"
#include "init.h"
using namespace std;

int main()
{
	Sort sort;
	sort.Init();
	sort.Rank();
	sort.Print();
    return 0;
}
void Sort::Rank() {
	int min, max;
	for (int i = 1; i <= len/2; i++) {
		min = i;
		max = i;
		for (int j = i+1; j <= len-i+1; j++) {
			if (element[j] < element[min]) {
				min = j;
				continue;
			}
			if (element[j] > element[max]) {
				max = j;
			}
		}
		element[0] = element[min];
		element[min] = element[i];
		element[i] = element[0];
		if (element[i] != element[max]) {
			element[0] = element[max];
			element[max] = element[len-i+1];
			element[len-i+1] = element[0];
		}
	}
}


