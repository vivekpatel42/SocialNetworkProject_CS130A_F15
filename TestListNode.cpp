#include <stdio.h>
#include "ListNode.h"

using namespace std;

int main() 
{
	ListNode<int> l = ListNode<int>(2);
	l.setData(3);
	l.printNode();
	printf("\n");

	l.setData(5);
	l.printNode();
	printf("\n");

	return 0;
}