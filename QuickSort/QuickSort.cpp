// QuickSort.cpp: 定义控制台应用程序的入口点。
//

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
void swap(ElementType *element1, ElementType *element2) {
	ElementType temp = *element1;
	*element1 = *element2;
	*element2 = temp;
}
int partition(ElementType element[], int low, int high) {
	ElementType pivot = element[low];
	while (low<high&&element[high]>pivot)
	{
		high--;
	}
	swap(&element[low], &element[high]);
	cout << element[low] << "     " << element[high] << endl;
	while (low<high&&element[low]<pivot)
	{
		low++;
	}
	swap(&element[high], &element[low]);
	return low;
}
void QuickSort(ElementType element[],int low,int high) {
	if (low < high) {
		int pivotLoc = partition(element, low, high);
		QuickSort(element, low, pivotLoc - 1);
		QuickSort(element, pivotLoc + 1, high);
	}
}

void Sort::Rank() {
	QuickSort(element, 1, len);
}

