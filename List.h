#ifndef LIST_H
#define LIST_H

template <class T>
class List 
{

	virtual bool insert (int pos, const T & item) = 0;

	virtual bool remove (int pos) = 0;

	virtual void set (int pos, const T & item) = 0;

	virtual T const & get (int pos) const = 0;
	
};

#endif