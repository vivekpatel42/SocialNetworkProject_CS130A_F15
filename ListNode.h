#ifndef LISTNODE_H
#define LISTNODE_H

template <class T> 
class ListNode {
	public:
		ListNode();
		const T& getData() const;
		void setData (const T& value);
		ListNode* getNext() const;
		void setNext(ListNode* l);
		ListNode* getPrev() const;
		void setPrev(ListNode* l);

	private:
		T data;
		ListNode *next;
		ListNode *prev;
};

#endif