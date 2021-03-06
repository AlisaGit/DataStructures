// MergeSort.cpp: 定义控制台应用程序的入口点。
//MergeSort就是先通过递归分解待排序列，在将有序子序列合并
//在归并排序的Merge中千万不要写常数，因为low和high都在变，不知道会出现什么莫名其妙的问题

#include "stdafx.h"
#include "init.h"
#include "iostream"
using namespace std;


int main()
{
	Sort sort;
	sort.Init();
	sort.Rank();
	sort.Print();
    return 0;
}

void Merge(ElementType element[],int low,int middle,int high,ElementType temp[]) {
	int k = low;
	int i = low, j = middle;
	//ElementType *temp = new ElementType();
	while (i<middle&&j<=high)
	{
		if (element[i] < element[j]) {
			temp[k++] = element[i++];
		}
		else {
			temp[k++] = element[j++];
		}
	}
	while (i<middle)
	{
		temp[k++] = element[i++];
	}
	while (j<=high)
	{
		temp[k++] = element[j++];
	}
	for (int i = low; i <= high; i++) {
		element[i] = temp[i];
	}
	//delete temp;
	for (int i = low; i <= high; i++) {
		cout << element[i] << "      ";
	}
	cout << endl;
 }

void MergeSort(ElementType element[], int low, int high,ElementType temp[]) {
	if (low < high) {
		int middle = (low + high) / 2;
		MergeSort(element, low, middle,temp);
		MergeSort(element, middle + 1, high,temp);
		Merge(element, low, middle+1, high,temp);
	}
}

void Sort::Rank() {
	ElementType *temp = new ElementType[len + 1];
	MergeSort(element, 1, len,temp);
}