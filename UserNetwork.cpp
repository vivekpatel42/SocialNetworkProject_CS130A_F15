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
	ofstream outfile;
	outfile.open("userList.txt");
	ListNode<User> * l = userList -> getHead();
	while (l)
	{
		outfile << ((User)(l -> getData())).toString();
		l = l -> getNext();
	}
	outfile.close();
}

void UserNetwork::readUserList()
{
	userList -> clearList();
	ifstream infile;
	infile.open("userList.txt");
	User tempUser = User();
	Wall tempWall = Wall();
	string s, wholeFile;
	getline(infile, s);
	while (infile)
	{
		wholeFile += s + "\n";
		getline(infile, s);			
	}
	string token, temp;
	istringstream iss1(s);
	while (getline(iss1, token, END_USER_DELIM))
	{
		temp = "";
		int count = 0;
		istringstream iss2(token);
		for (int i = 0; i < 4; i++)
		{
			getline(iss2, temp, '\n');
			temp += '\n';
		}
		tempUser.parseUserInfo(temp);
		temp = "";
		while (getline(iss2, temp, '\n'))
		{	
			temp += '\n';
		}
		tempWall.parseWall(temp);
		tempUser.setWall(tempWall);
		addUser(tempUser);
	}
}

UserNetwork::~UserNetwork()
{}