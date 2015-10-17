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

	return 0;
}