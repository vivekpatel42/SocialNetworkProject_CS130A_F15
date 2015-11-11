#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

template <class T>
class List 
{

	public:
		
		virtual bool insert (int pos, const T & item) = 0;

		virtual bool remove (int pos) = 0;

		virtual void set (int pos, const T & item) = 0;

		virtual T const & get (int pos) const = 0;

		virtual int getCount() const = 0;

		virtual void clearList() = 0;

		virtual Node<T> * getHead() const = 0;
	
		virtual bool appendItem(const T & item) = 0;

};

#endif