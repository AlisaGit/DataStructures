// HeapSort.cpp: 定义控制台应用程序的入口点。
//HeapSort需要做的就是如何使待排序的数组建成堆，输出最小（最大）的堆顶元素，再将剩下的元素建成新的堆，输出堆顶元素。
//依次输出有序序列，最后得到有序数组
//堆排序是找到合适位置后再把该元素放在该合适位置

#include "stdafx.h"
#include "init.h"
#include "iostream"
using namespace std;


int main()
{
	Sort heap;
	heap.Init();
	heap.Rank();
	//heap.Print();
    return 0;
}
//向下调整

void HeapAdjustDown(ElementType element[],int parent,int len) {
	ElementType temp = element[parent];
	int child = 2 * parent;
	while (child<=len)
	{
		if (child+1 <= len && element[child] > element[child + 1]) {
			child++;
		}
		if (temp < element[child]) {
			break;
		}
		element[parent] = element[child];
		parent = child;
		child = 2 * child;
	}
	element[parent] = temp;
}
//建堆
void BuildHeap(ElementType element[],int len) {
	for (int i = len/2; i>0; i--) {
		HeapAdjustDown(element, i,len);
	}
}
void print(ElementType element[], int len) {
	for (int i = len; i >0; i--) {
		cout << element[i] << "    ";
	}
	cout << endl;
}
//每一次输出堆顶元素后进行堆调整
void Sort::Rank() {
	BuildHeap(element, len);
	for (int i = len; i > 1; i--) {
		ElementType temp = element[i];
		element[i] = element[1];
		element[1] = temp;
		HeapAdjustDown(element, 1, i-1);
		print(element, len);
	}
}