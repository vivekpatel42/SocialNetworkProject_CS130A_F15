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
	outfile.open("userList.txt", ofstream::out | ofstream::trunc);
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
	delete userList;
	userList = new DoubleLinkedList<User>();
	ifstream infile;
	infile.open("userList.txt");
	string s, wholeFile;
	while (getline(infile, s))
	{
		wholeFile += s + "\n";		
	}
	string token, temp;
	istringstream iss1(wholeFile);
	while (getline(iss1, token, '\f'))
	{
		User * tempUser = new User();
		Wall * tempWall = new Wall();
		string input;
		temp = "";
		istringstream iss2(token);
		for (int i = 0; i < 4; i++)
		{
			getline(iss2, temp);
			input += temp + '\n';
		}
		tempUser -> parseUserInfo(input);
		input = "";
		temp = "";
		while (getline(iss2, temp))
		{	
			input += temp + '\n';
		}
		tempWall -> parseWall(input);
		tempWall -> setUsername(tempUser -> getUsername());
		tempUser -> setWall(tempWall);
		addUser(*tempUser);
	}
	infile.close();
}

UserNetwork::~UserNetwork()
{}