#ifndef NODE_H
#define NODE_H

template <class T>
class Node 
{
	public:
		Node()
		{
			data = T();
			next = NULL;
		}

		~Node()
		{
		}

		const T & getData()
		{
			return data;
		}

		void setData(const T & value)
		{
			data = value;
		}

		Node<T> * getNext()
		{
			return next;
		}

		void setNext(Node<T> * l)
		{
			next = l;
		}

	private:
		T data;
		Node<T> * next:

};

#endif