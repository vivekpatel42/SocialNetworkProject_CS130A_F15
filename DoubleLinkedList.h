#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

using namespace std;

template <class T> 
class DoubleLinkedList {
	
	public:

		// Creates a new DoubleLinkedList object with the specified HEAD node. CANNOT have empty list.
		explicit DoubleLinkedList(ListNode<T> * value)
		{
			head = value;
			head -> setPrev(NULL);
			head -> setNext(NULL);
			count = 1;
		} 
		
		// Gets the HEAD node.
		ListNode<T> * getHead() const
		{
			return head;
		} 

		// Appends ListNode to the end of the list.

		void appendItem(const T & value)
		{
			ListNode<T> * l = new ListNode<T>(value);
			ListNode<T> * temp = this -> head;
			for (int i = 0; i < count - 1; i++)
			{
				temp = temp -> getNext();
			}
			l -> setPrev(temp);
			temp -> setNext(l);
			l -> setNext(NULL);
			count++;
		} 

		void printList()
		{
			ListNode<T> * l = head;
			while (l)
			{
				l -> printNode();
				l = l -> getNext();
			}
		}

		~DoubleLinkedList() 
		{
			while (head) 
			{
				ListNode<T> * next = head -> getNext();
				delete head;
				head = next;
			}
		}

	private:
		ListNode<T> * head;
		int count;
};

#endif