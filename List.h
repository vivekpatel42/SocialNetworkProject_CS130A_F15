#ifndef LIST_H
#define LIST_H

template <class T>
class List 
{

	virtual void insert (int pos, const T & item);

	virtual void remove (int pos);

	virtual void set (int pos, const T & item);

	virtual T const & get (int pos) const;
	
};

#endif