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
			return ((User)(l -> getData()));			
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
		string userInfo = (((User)(l -> getData())).getUserInfo());
		file << "user\n" << userInfo << "enduser";
		Wall w = (((User)(l -> getData())).getWall());
		file << w.toString();
	}
}

void UserNetwork::readUserList(ifstream infile)
{
	string line;
	while (getline(infile, line))
	{
	    // istringstream iss(line);
	    // string userInfo;
	    // string posts;
	    // if (!(iss >> a >> b)) { break; } // error
	}
}

UserNetwork::~UserNetwork()
{}