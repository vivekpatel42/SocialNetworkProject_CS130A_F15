#include "ListNode.h"

ListNode::ListNode() { }

ListNode::const T& getData() const 
{
	return this.T;
}

ListNode::void setData(const T& value) 
{
	this.T = value;
}

ListNode::ListNode* getNext() const 
{
	return this -> next;
}

ListNode::void setNext(ListNode* l)
{
	this -> next = l;
}

ListNode::ListNode* getPrev() const
{
	return this -> prev;
}

ListNode::void setPrev(ListNode* l)
{
	this -> prev = l;
}