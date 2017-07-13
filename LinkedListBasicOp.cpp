// LinkedListBasicOp.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
#include "limits"
using namespace std;

typedef int DATA_TYPE;
typedef struct LinkedData
{
	DATA_TYPE data;
	struct LinkedData *next;
}SingleLink;

/*Initialize a empty linked list*/
SingleLink* InitLink() {
	SingleLink *link = new SingleLink();
	link->next = nullptr;
	return link;
}
/*Judge that the linked list is empty*/
bool EmptyLink(SingleLink *singleLink) {
	if (singleLink == nullptr) {
		return true;
	}
	else
	{
		return false;
	}
}
/*Clear the linked list*/
void ClearLink(SingleLink *singleLink) {
	SingleLink *clearLink;
	SingleLink *tempLink;
	clearLink = singleLink;
	while (clearLink->next != nullptr) {
		tempLink=InitLink();
		tempLink = clearLink->next;
		clearLink->next = clearLink->next->next;
		delete tempLink;
	}
}
/*Create a linked list by head interpolation*/
void CreateLink(SingleLink *singleLink) {
	SingleLink *tempLink;
	int temp;
	cout << "Please input your values to the linked list" << endl;
	fflush(stdin);
	cin >> temp;
	while (temp > 0) {
		tempLink = InitLink();
		tempLink->data = temp;
		tempLink->next = singleLink->next;
		singleLink->next = tempLink;
		fflush(stdin);
		cin >> temp;
	}
}
/*Traverse the valus of the linked list.This includes the head node*/
void TraverseLink(SingleLink *singleLink) {
	SingleLink *tempLink;
	tempLink = singleLink;
	if (EmptyLink(tempLink) == true) {
		cout << "This is a empty linked list" << endl;
	}
	while (tempLink!=nullptr) {
		cout << tempLink->data << endl;
		tempLink = tempLink->next;
	}
} 
/*Get the length of the linked list*/
int GetLength(SingleLink *singleLink) {
	SingleLink *tempLink;
	int length = 0;
	tempLink = singleLink->next;
	while (tempLink != nullptr) {
		length++;
		tempLink = tempLink->next;
	}
	return length;
} 
/*Search a value's position that you point*/
void SearchLink(SingleLink *singleLink, DATA_TYPE data) {
	SingleLink *tempLink,*lengthLink;
	int index = 0;
	tempLink = singleLink;
	lengthLink = singleLink;
	/*Null pointer can't use directly,so we can not use "tempLink == nullptr" */
	while (tempLink->data != data&&tempLink->next) {
		tempLink = tempLink->next;
		index++;
	}
	if (index+1 > GetLength(lengthLink)&&tempLink->data!=data) {
		cout << "Can't find the value" << endl;
	}
	else {
		cout << "The position of the value is :" << index << endl;
	}
}

/*Insert a value into the linked list*/
void InsertLink(SingleLink *singleLink) {
	SingleLink *tempLink;
	SingleLink *insertLink;
	DATA_TYPE tempData;
	int position;
	int index=0;
	//Because this is shallow copy here,it's not necessary to return the pointer and it will get the change
	insertLink = singleLink;
	cout << "Please input your position that insert value" << endl;
	cin >> position;
	if (position<0 || position>GetLength(insertLink)) {
		cout << "You have inputed a wrong position" << endl;
	}
	else
	{
		while (index < position&&insertLink!=nullptr) {
			index++;
			insertLink = insertLink->next;
		}
		cout << "Please input your values that insert into the linked list" << endl;
		cin >> tempData;
		tempLink=InitLink();
		tempLink->data = tempData;
		tempLink->next = insertLink->next;
		insertLink->next = tempLink;
	}
}
/*Delete a value from where you point*/
void DeleteLink(SingleLink *singleLink) {
	SingleLink *tempLink;
	SingleLink *deleteLink;
	int position,index=0;
	deleteLink = singleLink;
	cout << "Please input your position that delete value" << endl;
	fflush(stdin);
	cin >> position;
	if (position<0 || position>GetLength(deleteLink)) {
		cout << "You have inputed a wrong position" << endl;
	}
	else
	{
		while (index < position-1) {
			index++;
			deleteLink = deleteLink->next;
		}
		tempLink = deleteLink->next;
		deleteLink->next = deleteLink->next->next;
		delete tempLink;
	}
	
}
/*Reverse a linked list*/ 
SingleLink *ReverseLink(SingleLink *singleLink) {
	SingleLink *tempLinkFront,*tempLinkRear;
	int index = GetLength(singleLink);
	int i = 0;
	tempLinkFront = singleLink->next;
	tempLinkRear = singleLink->next->next;
	singleLink->next = nullptr;
	while (i<index) {
		i++;
		tempLinkFront->next = singleLink;
		singleLink = tempLinkFront;
		tempLinkFront = tempLinkRear;
		if (tempLinkRear->next) {
			tempLinkRear = tempLinkRear->next;
		}
	}
	return singleLink;
}
int main()
{
	SingleLink *singleLink;
	singleLink = InitLink();
	CreateLink(singleLink);
	singleLink=ReverseLink(singleLink);
	TraverseLink(singleLink);
	/*cout << "The linked list's length is :" << GetLength(singleLink) << endl;
	SearchLink(singleLink,1);*/
	/*InsertLink(singleLink);
	TraverseLink(singleLink);
	DeleteLink(singleLink);
	TraverseLink(singleLink);
	ClearLink(singleLink);
	TraverseLink(singleLink);*/

	delete singleLink;
    return 0;
}