#ifndef LISTNODE_H
#define LISTNODE_H

#include <stdio.h>

using namespace std;

template <class T> 
class ListNode {
	public:
		explicit ListNode(const T & value) { data = value; } // Creates a new ListNode object with the specified data value T.
		const T & getData() const { return data; } // Sets the data value T for the invoking ListNode object.
		void setData (const T & value) { data = value; } // Sets the data value T for the invoking ListNode object.
		ListNode<T> * getNext() const { return next; } // Gets the ListNode object referred to by the NEXT pointer.
		void setNext(ListNode<T> * l) { next = l; } // Sets the ListNode object referred to by the NEXT pointer.
		ListNode<T> * getPrev() const { return prev; } // Gets the ListNode object referred to by the PREV pointer.
		void setPrev(ListNode<T> * l) { prev = l; } // Sets the ListNode object referred to by the PREV pointer.
		void printNode() { printf("%d\n", data); }
	private:
		T data;
		T data;
		ListNode<T> *next;
		ListNode<T> *prev;
};

// template <class T>
// ListNode<T>::ListNode(const T & value) : data(value) // Initialization list for ListNode constructor.
// {
// }

// template <class T>
// const T & ListNode<T>::getData() const // const specifies an accessor
// {
// 	return data;
// }

// template <class T>
// void ListNode<T>::setData(const T & value) 
// {
// 	data = value;
// }

// template <class T>
// ListNode<T> * ListNode<T>::getNext() const 
// {
// 	return this -> next;
// }

// template <class T>
// void ListNode<T>::setNext(ListNode<T> *l)
// {
// 	this -> next = l;
// }

// template <class T>
// ListNode<T> * ListNode<T>::getPrev() const
// {
// 	return this -> prev;
// }

// template <class T>
// void ListNode<T>::setPrev(ListNode<T> *l)
// {
// 	this -> prev = l;
// }

// template <class T>
// void ListNode<T>::printNode()
// {
// 	printf("%d\n", data);
// }

#endif