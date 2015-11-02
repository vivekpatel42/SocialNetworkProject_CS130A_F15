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