#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

template <class T> 
class DoubleLinkedList {
	
	public:
		DoubleLinkedList();
		ListNode* getHead() const;
		void setHead(ListNode* l);
		ListNode* getItem(int n) const;
		void setItem(int n, ListNode* l);

	private:
		ListNode *head;
		int count;
};

#endif