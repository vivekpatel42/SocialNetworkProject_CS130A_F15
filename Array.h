#ifndef ARRAY_H
#define ARRAY_H

template <class T>
class Array : public class List
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

		bool insert (int pos, const T & item)
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

		bool remove (int pos)
		{
			if (pos < 0 || pos >= maxLength)
			{
				return false;
			}
			else
			{
				data[pos] = NULL;
				for (int i = pos + 1; i < numItems; i++)
				{
					data[i-1] = data[i];
				}
				numItems--;
				return true;
			}
		}

		void set (int pos, const T & item)
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

		T const & get (int pos) const
		{
			if (pos < 0 || pos >= numItems)
			{
				return NULL;
			}
			else
			{
				return data[pos];
			}
		}

	private:
		T *data;
		int numItems;
		int maxLength;
		const int DEFAULT_SIZE = 30;

};

#endif