#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "List.h"
#include "Node.h"

using namespace std;

template <class T>
class LinkedList : public List<T>
{
	public:
		LinkedList()
		{
			head = NULL;
			numItems = 0;
		}

		bool insert (int pos, const T & item) override
		{
			if (pos < 0 || pos > numItems)
			{
				return false;
			}
			else if (pos == 0 && numItems == 0)
			{
				delete head;
				head = new Node<T>(item);
				head -> setNext(NULL);
				numItems++;
				return true;
			}
			else if (pos == 0 && numItems != 0)
			{
				Node<T> * n = new Node<T>(item);
				n -> setNext(head);
				head = n;
				numItems++;
				return true;
			}
			else if (pos == numItems)
			{
				Node<T> * n = head;
				while(n -> getNext())
				{
					n = n -> getNext();
				}
				Node<T> * l = new Node<T>(item);
				l -> setNext(NULL);
				n -> setNext(l);
				numItems++;
				return true;
			}
			else
			{
				Node<T> * n = head;
				for (int i = 0; i < pos; i++)
				{ 
					n = n -> getNext();
				}
				Node<T> * l = new Node<T>(item);
				n -> setNext(l);
				numItems++;
				return true;
			}
		}

		bool appendItem(const T & item)
		{
			return insert(numItems, item);
		}

		bool remove (int pos) override
		{
			if (numItems == 0)
			{
				return false;
			}
			else if (pos < 0 || pos > numItems)
			{
				return false;
			}
			else if (pos == 0)
			{
				Node<T> * n = head;
				head = head -> getNext();
				delete n;
				numItems--;
				return true;
			}
			else if (pos == numItems - 1)
			{
				Node<T> * n = head;
				for (int i = 0; i < numItems - 2; i++)
				{
					n = n -> getNext();
				}
				Node<T> * temp = n -> getNext();
				n -> setNext(NULL);
				delete temp;
				numItems--;
				return true;
			}
			else
			{
				Node<T> * n = head;
				for (int i = 0; i < pos - 1; i++)
				{
					n = n -> getNext();
				}
				Node<T> * temp = n -> getNext();
				n -> setNext(temp -> getNext());
				delete temp;
				numItems--;
				return true;
			}
		}

		void set (int pos, const T & item) override
		{
			if (pos < 0 || pos >= numItems)
			{
				return;
			}
			Node<T> * n = head;
			for (int i = 0; i < pos; i++)
			{
				n = n -> getNext();
			}
			n -> setData(item);
		}

		T const & get (int pos) const override
		{
			Node<T> * n = head;
			for (int i = 0; i < pos; i++)
			{
				n = n -> getNext();
			}
			return n -> getData();
		}

		Node<T> * getHead() const
		{
			return head;
		}

		int getCount() const override
		{
			return numItems;
		}

		void clearList()
		{
			Node<T> * l = head;  
			while (l)
			{
				head = head -> getNext();
				delete l;
				l = head;
			}
			head = NULL;
			numItems = 0;
		}

		~LinkedList()
		{
			while (head) 
			{
				Node<T> * next = head -> getNext();
				delete head;
				head = next;
			}
		}

	private:
		Node<T> * head;
		int numItems;

};

#endif