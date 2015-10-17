#include <iostream>
#include <string>
#include <sstream>
#include "ListNode.h"
#include "DoubleLinkedList.h"
#include "WallPost.h"
#include "Wall.h"
#include "User.h"
#include "UserNetwork.h"

using namespace std;

int main() 
{
	string post = "This is the first post";
	string mood = "Happy :)";
	WallPost * p = new WallPost(post, mood);
	p -> printPost();

	Wall * w = new Wall();
	//DoubleLinkedList<WallPost> * dll = new DoubleLinkedList<WallPost>();
	WallPost * wp = new WallPost("This is the second post", "Happy");
	w -> posts -> appendItem(*wp);
	WallPost * wp2 = new WallPost("This is the third post", "Happy");
	w -> posts -> appendItem(*wp2);
	WallPost * wp3 = new WallPost("This is the fourth post", "Happy");
	w -> posts -> appendItem(*wp3);
	w -> addPost("This is the fifth post", "Happy");
	ListNode<WallPost> * l = w -> posts -> getHead();
	while(l)
	{
		((WallPost)l -> getData()).printPost();
		l = l -> getNext();
	}

	UserNetwork * un = new UserNetwork();
	User u = User("vpatel", "poop", "Vivek Patel", "Glendale");
	un -> addUser(u);
	User u2 = User("xd", "poop", "Xochitl Duarte", "Goleta");
	un -> addUser(u2);
	ListNode<User> * l1 = un -> userList -> getHead();
	while(l1)
	{
		cout << ((User)l1->getData()).getUserInfo();
		l1 = l1 -> getNext();
	}

	return 0;
}