#ifndef BAG_H
#define BAG_H

template <class T>
class Bag 
{

	public:
		Bag()
		{
			data = new T[20];
			for(int i = 0; i < DEFAULT_MAX; i++)
			{
				data[i] = T();
			}
			numItems = 0;
			maxLength = DEFAULT_MAX;
		}

		explicit Bag(int size)
		{
			data = new T[size];
			for(int i = 0; i < size; i++)
			{
				data[i] = T();
			}
			numItems = 0;
			maxLength = size;
		}

		T const & get(int pos)
		{
			if(pos < 0 || pos >= numItems)
			{
				return NULL;
			}
			else
			{
				return data[pos];
			}
		}

	/*
	 * Data elements: Dynamic array of elements of type T
	 *				  Integer representing the current amount of items in the bag.
	 *				  Integer representing the maximum capacity of the array of items.
	 */
	private:
		T * data;
		int numItems;
		int maxLength;
		static const int DEFAULT_MAX = 20;
};

#endif