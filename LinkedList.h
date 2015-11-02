#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <class T>
class LinkedList : public class List
{
	public:
		LinkedList()
		{
			head = new Node();
			head -> setNext(NULL);
			length = 0;
		}

		bool insert (int pos, const T & item)
		{
			if (pos < 0 || pos > numItems)
			{
				return false;
			}
			else if (pos == 0)
			{
				Node<T> * n = new Node(item);
				n -> setNext(head);
				head = n;
				numItems++;
				return true;
			}
			else if (pos == numItems)
			{
				Node<T> * i = head;
				while(i -> getNext())
				{
					i = i -> getNext();
				}
				Node<T> * n = new Node(item);
				i -> setNext(n);
				numItems++;
				return true;
			}
			else
			{
				Node<T> * i = head;
				for (int i = 0; i < pos; i++)
				{
					i = i -> getNext();
				}
				Node<T> * n = new Node(item);
				i -> setNext(n);
				numItems++;
				return true;
			}
		}

		bool remove (int pos)
		{
			if (pos < 0 || pos >= numItems)
			{
				return false;
			}

		}

		void set (int pos, const T & item)
		{

		}

		T const & get (int pos) const
		{

		}

	private:
		Node<T> * head;
		int numItems;

};

#endif