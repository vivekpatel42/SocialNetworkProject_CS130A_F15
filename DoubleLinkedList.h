#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

template <class T> 
class DoubleLinkedList {
	
	public:
		DoubleLinkedList(); // Creates a new DoubleLinkedList object with an empty HEAD node.
		DoubleLinkedList(ListNode* head); // Creates a new DoubleLinkedList object with the specified HEAD node.
		ListNode* getHead() const; // Gets the HEAD node.
		void addHead(ListNode* l); // Adds a new ListNode as the HEAD node.
		ListNode* getItem(int n) const; // Gets the ListNode item at the specified index.
		void insertItem(int n, ListNode* l); // Inserts ListNode at the specified index.
		void appendItem(ListNode* l); // Appends ListNode to the end of the list.

	private:
		ListNode *head;
		int count;
};

#endif