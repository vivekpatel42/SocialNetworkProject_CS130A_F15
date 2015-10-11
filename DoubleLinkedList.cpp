#include "DoubleLinkedList.h"

DoubleLinkedList::DoubleLinkedList() 
{
	ListNode l = new ListNode();
	this -> head = &l;
	head -> prev = NULL;
	head -> next = NULL;
	count = 1;
}

ListNode* DoubleLinkedList::getHead() const
{
	return this -> head;
}

void DoubleLinkedList::addHead(ListNode* l)
{
	// Not yet fully implemented!!!
	
	if (head) 
	{
		head -> prev = l;
		l -> next = head;
		l -> prev = NULL;
		head = l;
		count++;
	}
	this -> head = l;
}

ListNode* DoubleLinkedList::getItem(int n) const
{
	ListNode* result = this -> head;
	while (n != 0)
	{
		result = result -> getNext();
		n--;
	}
	return result;
}

void DoubleLinkedList::insertItem(int n, ListNode* l)
{
	if (n == 0)
	{
		this.setHead(l);
		return;
	}

}	

void DoubleLinkedList::appendItem(ListNode* l)
{
	ListNode* temp = this -> head;
	for (int i = 0; i < count - 1; i++)
	{
		temp = temp -> next;
	}
	l -> prev = temp;
	temp -> next = l;
	l -> next = NULL;
	count++;
}