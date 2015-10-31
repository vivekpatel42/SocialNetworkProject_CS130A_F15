#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

using namespace std;

template <class T> 
class DoubleLinkedList {
	
	public:

		DoubleLinkedList()
		{
			head = new ListNode<T>();
			tail = new ListNode<T>();
			head -> setPrev(NULL);
			head -> setNext(tail);
			tail -> setPrev(head);
			tail -> setNext(NULL);
			count = 0;
		}

		// Creates a new DoubleLinkedList object with the specified HEAD node. CANNOT have empty list.
		explicit DoubleLinkedList(ListNode<T> * value)
		{
			head = value;
			head -> setPrev(NULL);
			head -> setNext(tail);
			tail -> setPrev(head);
			tail -> setNext(NULL);
			count = 1;
		} 
		
		// Gets the HEAD node.
		ListNode<T> * getHead() const
		{
			return head;
		} 

		//Gets the TAIL node.
		ListNode<T> * getTail() const
		{
			return tail;
		}

		int getCount() const
		{
			return count;
		}

		// Appends ListNode to the end of the list.

		void appendItem(const T & value)
		{
			if (count == 0)
			{
				head -> setData(value);
				head -> setNext(tail);
				head -> setPrev(NULL);
				tail -> setPrev(head);
				tail -> setNext(NULL);
				count++;
				return;
			}
			else if (count == 1)
			{
				tail -> setData(value);
				count++;
				return;
			}
			else 
			{
				ListNode<T> * temp = new ListNode<T>(value);
				tail -> setNext(temp);
				temp -> setPrev(tail);
				tail = temp;
				tail -> setNext(NULL);
			}
		} 

		// Removes the nth ListNode
		void removeItem(int n) 
		{
			if (!head && !tail)
			{
				return;
			}
			if (n > count || n == 0) 
			{
				return;
			}
			else if (n == count) {
				if (!tail)
				{
					return;
				}
				ListNode<T> * l = tail -> getPrev();
				delete tail;
				tail = l;
				tail -> setNext(NULL);
				count--;
			}
			else if (n == 1)
			{
				if (!head)
				{
					return;
				}
				ListNode<T> * l = head -> getNext();
				delete head;
				head = l;
				head -> setPrev(NULL);
				count--;
			}
			else 
			{
				ListNode<T> * l = head;
				for (int i = 1; i < n; i++)
				{
					l = l -> getNext();
				}
				l -> getPrev() -> setNext(l -> getNext());
				l -> getNext() -> setPrev(l -> getPrev());
				count--;
			}
		}

		// void printList()
		// {
		// 	ListNode<T> * l = head;
		// 	while (l)
		// 	{
		// 		l -> printNode();
		// 		l = l -> getNext();
		// 	}
		// }

		void clearList()
		{
			ListNode<T> * l = head;  
			while (l)
			{
				head = head -> getNext();
				delete l;
				l = head;
			}
			head = NULL;
			tail = NULL;
			count = 0;
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
		ListNode<T> * tail;
		int count;
};

#endif
