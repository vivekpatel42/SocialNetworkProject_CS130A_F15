#ifndef LISTNODE_H
#define LISTNODE_H

template <class T> 
class ListNode {
	public:
		ListNode(); // Creates a new empty ListNode object. 
		ListNode(const T& value); // Creates a new ListNode object with the specified data value T.
		const T& getData() const; // Sets the data value T for the invoking ListNode object.
		void setData (const T& value); // Sets the data value T for the invoking ListNode object.
		ListNode* getNext() const; // Gets the ListNode object referred to by the NEXT pointer.
		void setNext(ListNode* l); // Sets the ListNode object referred to by the NEXT pointer.
		ListNode* getPrev() const; // Gets the ListNode object referred to by the PREV pointer.
		void setPrev(ListNode* l); // Sets the ListNode object referred to by the PREV pointer.
	private:
		T data;
		ListNode *next;
		ListNode *prev;
};

#endif