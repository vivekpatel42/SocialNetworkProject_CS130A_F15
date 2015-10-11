#include "DoubleLinkedList.h"

DoubleLinkedList::DoubleLinkedList() { }

DoubleLinkedList::ListNode* getHead() const
{
	return this -> head;
}

DoubleLinkedList::void setHead(ListNode* l)
{
	// Not yet fully implemented!!!
	
	if (head) 
	{
		ListNode*
	}
	this -> head = l;
}

DoubleLinkedList::ListNode* getItem(int n) const
{
	ListNode* result = this -> head;
	while (n != 0)
	{
		result = result -> getNext();
		n--;
	}
	return result;
}

DoubleLinkedList::void setItem(int n, ListNode* l)
{
	if (n == 0)
	{
		this.setHead(l);
		return;
	}

}	