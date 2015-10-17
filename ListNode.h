#ifndef LISTNODE_H
#define LISTNODE_H

#include <iostream>

using namespace std;

template <class T> 
class ListNode {
	public:

		ListNode()
		{
			data = T { };
			next = NULL;
			prev = NULL;
		}

		// Creates a new ListNode object with the specified data value T.
		explicit ListNode(const T & value) 
		{ 
			data = value; 
			next = NULL; 
			prev = NULL; 
		} 

		~ListNode()
		{
			delete next;
			delete prev;
		}

		const T & getData() const 
		{ 
			return data; 
		} // Sets the data value T for the invoking ListNode object.
		
		void setData (const T & value) 
		{ 
			data = value; 
		} // Sets the data value T for the invoking ListNode object.
		
		ListNode<T> * getNext() const 
		{ 
			return next; 
		} // Gets the ListNode object referred to by the NEXT pointer.
		
		void setNext(ListNode<T> * l) 
		{ 
			next = l; 
		} // Sets the ListNode object referred to by the NEXT pointer.
		
		ListNode<T> * getPrev() const 
		{ 
			return prev; 
		} // Gets the ListNode object referred to by the PREV pointer.
		
		void setPrev(ListNode<T> * l) 
		{ 
			prev = l; 
		} // Sets the ListNode object referred to by the PREV pointer.
		
		void printNode() 
		{ 
			cout << data << endl;
		}

	private:
		T data;
		ListNode<T> *next;
		ListNode<T> *prev;
};

#endif