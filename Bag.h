#ifndef BAG_H
#define BAG_H

#include <iostream>

using namespace std;

template <class T>
class Bag
{

	public:

		Bag()
		{
			count = 0;
		}

		bool insert(const T & value)
		{
			data[count] = value;
			count++;
		}

		bool remove(int pos)
		{
			if (pos < 0 || pos >= count)
			{
				return false;
			}
			for(int i = pos; i < count; i++)
			{
				data[i] = data[i + 1];
			}
			return true;
		}

		int getCount()
		{
			return count;
		}

		~Bag()
		{
		}

		T data[10];

	private:
		int count;
};

#endif