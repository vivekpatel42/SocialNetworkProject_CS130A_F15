#ifndef ARRAY_H
#define ARRAY_H

#include "List.h"

using namespace std;

template <class T>
class Array : public List<T>
{
	public:

		Array()
		{
			data = new T[DEFAULT_SIZE];
			maxLength = DEFAULT_SIZE;
			numItems = 0;
		}

		explicit Array(int size)
		{
			data = new T[size];
			maxLength = size;
			numItems = 0;
		}

		bool insert (int pos, const T & item) override
		{
			if (pos < 0 || pos >= maxLength)
			{
				return false;
			}
			else
			{
				for (int i = numItems - 1; i >= pos; i++)
				{
					data[i+1] = data[i];
				}
				data[pos] = item;
				numItems++;
			}
			if (numItems == maxLength)
			{
				T * temp = new T[maxLength*2];
				for (int i = 0; i < numItems; i++)
				{
					temp[i] = data[i];
				}
				delete [] data;
				data = temp;
				maxLength *= 2;
			}
			return true;
		}

		bool appendItem(const T & item)
		{
			return insert(numItems, item);
		}

		bool remove (int pos) override
		{
			if (pos < 0 || pos >= numItems)
			{
				return false;
			}
			else
			{
				for (int i = pos + 1; i < numItems; i++)
				{
					data[i-1] = data[i];
				}
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
			else
			{
				data[pos] = item;
			}
		}

		T const & get (int pos) const override
		{
			return data[pos];
		}

		int getCount() const
		{
			return numItems;
		}

		void clearList()
		{
			delete [] data;
		}

		Node<T> * getHead() const
		{
			return NULL;
		}

		~Array()
		{
			delete [] data;
			data = NULL;
		}

	private:
		T *data;
		int numItems;
		int maxLength;
		const int DEFAULT_SIZE = 20;
};

#endif