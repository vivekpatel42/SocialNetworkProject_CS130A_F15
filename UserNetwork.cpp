#include "UserNetwork.h"

using namespace std;

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
	int n = 0;
	while (l)
	{
		if (username.compare(((User)(l -> getData())).getUsername()) == 0)
		{
			userList -> removeItem(n);
			return;
		}
		l = l -> getNext();
		n++;			
	}	
}

bool UserNetwork::contains(string username)
{
	ListNode<User> * l = userList -> getHead();
	while(l)
	{
		if (username.compare(((User)(l -> getData())).getUsername()) == 0)
		{
			return true;
		}
		l = l -> getNext();
	}
	return false;
}

User UserNetwork::getUser(string username)
{
	ListNode<User> * l = userList -> getHead();
	while(l)
	{
		if (username.compare(((User)(l -> getData())).getUsername()) == 0)
		{
			return ((User)(l -> getData));			
		}
		l = l -> getNext();
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
		userInfo.append(((User)(l -> getData())).getUsername() + "\n"); 
		userInfo.append(((User)(l -> getData())).getPassword() + "\n"); 
		userInfo.append(((User)(l -> getData())).getFullName() + "\n");
		userInfo.append(((User)(l -> getData())).getCity() + "\n");
		userInfo.append( + "\n");
		file << userInfo;
	}
}

UserNetwork::~UserNetwork()
{}