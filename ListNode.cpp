#include "ListNode.h"

ListNode::ListNode() { }

ListNode::ListNode(const T& value)
{
	
}

const T& ListNode::getData() const 
{
	return this.T;
}

void ListNode::setData(const T& value) 
{
	this.T = value;
}

ListNode* ListNode::getNext() const 
{
	return this -> next;
}

void ListNode::setNext(ListNode* l)
{
	this -> next = l;
}

ListNode* ListNode::getPrev() const
{
	return this -> prev;
}

void ListNode::setPrev(ListNode* l)
{
	this -> prev = l;
}