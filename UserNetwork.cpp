#include "UserNetwork.h"

UserNetwork::UserNetwork()
{
	userList = new DoubleLinkedList<User>();
}

void UserNetwork::addUser(User u)
{
	userList -> appendItem(u);
}

void UserNetwork::deleteUser(string username)
{
	ListNode<User> * l = userList -> getHead();
	n = 0;
	while (l)
	{
		if (username.compare(l -> getData() -> getUsername()) == 0)
		{
			userList -> removeItem(n);
			return;
		}
		l = l -> getNext();
		count++;			
	}	
}

void UserNetwork::writeUserList()
{
	ofstream file;
	file.open("userList.txt");
	ListNode<User> * l = userList -> getHead();
	while (l)
	{
		string userInfo;
		userInfo.append(l -> getData() -> getUsername() + "\n" + l -> getData() -> getCity());
		userInfo.append(l -> getData() -> getFullName() + "\n");
		userInfo.append( + "\n");
		file << userInfo;
		string wallPosts;
		wallPosts.append(((l -> getData() -> getWall()).posts) ->)
	}
}

UserNetwork::~UserNetwork()
{}