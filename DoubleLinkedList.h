#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

using namespace std;

template <class T> 
class DoubleLinkedList {
	
	public:

		DoubleLinkedList()
		{
			head = new ListNode<T>();
			head -> setPrev(NULL);
			head -> setNext(NULL);
			count = 0;
		}

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

		int getCount() const
		{
			return count;
		}

		// Appends ListNode to the end of the list.

		void appendItem(const T & value)
		{
			if (count == 0)
			{
				ListNode<T> *l = new ListNode<T>(value);
				head = l;
				head -> setNext(NULL);
				head -> setPrev(NULL);
				count++;
				return;
			}
			ListNode<T> * l = new ListNode<T>(value);
			ListNode<T> * temp = head;
			for (int i = 0; i < count - 1; i++)
			{
				temp = temp -> getNext();
			}
			l -> setPrev(temp);
			temp -> setNext(l);
			l -> setNext(NULL);
			count++;
		} 

		void removeItem(int n) 
		{
			if (n > count) 
			{
				return;
			}
			else if (n == count) {
				ListNode<T> * l = head;
				for (int i = 0; i < count - 1; i++)
				{
					l = l -> getNext();
				}
				delete l -> getNext();
				l -> setNext(NULL);
				count--;
			}
			else if (n == 0)
			{
				ListNode<T> * l = head;
				head = l -> getNext();
				head -> setPrev(NULL);
				count--;
			}
			else 
			{
				ListNode<T> * l = head;
				for (int i = 0; i < n - 1; i++)
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
			while (l -> getNext())
			{
				l = l -> getNext();
			}  
			while (l != head)
			{
				ListNode<T> * temp = l;
				l = l -> getPrev();
				delete temp;
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