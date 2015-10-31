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
	char buf[MAX_CHARS_PER_LINE];
	const char * token1; 
	const char * token2;
	User tempUser = User();
	Wall tempWall = Wall();
	string s, wholeFile;
	const string temp;
	getline(infile, s);
	while (infile)
	{
		wholeFile += s + "\n";
		getline(infile, s);			
	}
	token1 = strtok(s, END_USER_DELIM);
	while (token1)
	{
		int count = 0;
		token2 = strtok(token1, "\n");
		temp += token2 + "\n";
		for(int i = 0; i < 3; i++)
		{
			token2 = strtok(NULL, "\n");
			temp += token2 + "\n";
		}
		tempUser.parseUserInfo(temp);
		temp = "";
		while(token2)
		{
			
		}
	}
}

UserNetwork::~UserNetwork()
{}