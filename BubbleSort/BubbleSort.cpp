// BubbleSort.cpp: 定义控制台应用程序的入口点。
//BubbleSort是将待排序列中最大的元素选出来放在最后

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
	int flag = 0;
	for (int i = 1; i < len; i++) {
		for (int j = 1; j <= len - i; j++) {
			if (element[j] > element[j + 1]) {
				ElementType temp = element[j];
				element[j] = element[j + 1];
				element[j + 1] = temp;
				flag = 1;
			}
		}
		if (flag == 0) {
			return;
		}
	}
}