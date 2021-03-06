// ShellSort.cpp: 定义控制台应用程序的入口点。
//Shell排序先确定间隔排序的距离d，再在d的基础上使用插入排序惊醒排序
//所以shell排序与直接插入排序均属于插入排序

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
	int d = 3;
	for (int i = d; i > 0; i--) {					//步长
		for (int j = i + 1; j <= len; j++) {	//直接插入排序
			if (element[j] < element[j - i]) {
				element[0] = element[j];
				int k = j;
				while (k > i && element[k-i] > element[0])
				{
					element[k] = element[k - i];
					k = k - i;
				}
				element[k] = element[0];
			}
		}
		d--;
	}
}
