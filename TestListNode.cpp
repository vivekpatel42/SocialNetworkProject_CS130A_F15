#include <stdio.h>
#include "ListNode.h"
#include "DoubleLinkedList.h"
#include "WallPost.h"

using namespace std;

int main() 
{
	string post = "This is the first post";
	string mood = "Happy :)";
	WallPost * p = new WallPost(post, mood);
	p -> printPost();

	ListNode<char> * l = new ListNode<char>('c');
	DoubleLinkedList<char> * dll = new DoubleLinkedList<char>(l);
	dll -> appendItem('s');
	dll -> appendItem('d');
	dll -> appendItem('a');
	dll -> appendItem('z');
	printf("%d\n", dll -> getCount());
	dll -> printList();
	dll -> removeItem(3);
	dll -> removeItem(0);
	printf("%d\n", dll -> getCount());
	dll -> printList();

	return 0;
}