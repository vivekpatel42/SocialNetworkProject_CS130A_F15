#include "UserNetwork.h"

using namespace std;

UserNetwork::UserNetwork()
{
	userList = new LinkedList<User*>();
}

void UserNetwork::addUser(User* u)
{
	userList -> appendItem(u);
}

void UserNetwork::deleteUser(string username)
{
	Node<User*> * l = userList -> getHead();
	int n = 0;
	while (l)
	{
		if (username.compare(((User*)(l -> getData())) -> getUsername()) == 0)
		{
			userList -> remove(n);
			return;
		}
		l = l -> getNext();
		n++;			
	}	
}

bool UserNetwork::contains(string username)
{
	if ((userList -> getCount()) <= 0)
	{
		return false;
	}
	Node<User*> * l = userList -> getHead();
	while(l -> getNext())
	{
		if (username.compare(((User*)(l -> getData())) -> getUsername()) == 0)
		{
			return true;
		}
		l = l -> getNext();
	}
	if (username.compare(((User*)(l -> getData())) -> getUsername()) == 0)
	{
		return true;
	}
	return false;
}

User* UserNetwork::getUser(string username)
{
	if(username.empty())
	{
		return nullptr;
	}
	Node<User*> * l = userList -> getHead();
	while(l)
	{
		if (username.compare(((User*)(l -> getData())) -> getUsername()) == 0)
		{
			return ((User*)(l -> getData()));			
		}
		l = l -> getNext();
	}
}

void UserNetwork::writeUserList()
{
	if ((userList -> getCount()) == 0)
	{
		return;
	}
	ofstream mainUserFile, friendsFile, requestsFile, commentsFile;
	mainUserFile.open("userList.txt");
	friendsFile.open("friends.txt");
	requestsFile.open("friendRequests.txt");
	commentsFile.open("comments.txt");
	Node<User*> * l = userList -> getHead();
	while (l -> getNext())
	{
		mainUserFile << ((User*)(l -> getData())) -> toString();
		friendsFile << ((User*)(l -> getData())) -> friendsToString();
		requestsFile << ((User*)(l -> getData())) -> requestsToString();
		commentsFile << ((User*)(l -> getData())) -> commentsToString();
		l = l -> getNext();  
	}
	mainUserFile << ((User*)(l -> getData())) -> toStringLast();
	friendsFile << ((User*)(l -> getData())) -> friendsToStringLast();
	requestsFile << ((User*)(l -> getData())) -> requestsToStringLast();
	commentsFile << ((User*)(l -> getData())) -> commentsToStringLast();
	mainUserFile.close();
	friendsFile.close();
	requestsFile.close();
	commentsFile.close();
}

void UserNetwork::readUserList()
{
	userList -> clearList();
	delete userList;
	userList = new LinkedList<User*>();
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
		addUser(tempUser);
	}
	infile.close();
	readFriendsList();
	readRequestsList();
	readCommentsList();
}

void UserNetwork::readFriendsList()
{
	ifstream infile;
	infile.open("friends.txt");
	string s, wholeFile;
	while (getline(infile, s))
	{
		wholeFile += s + "\n";		
	}
	string token, temp;
	istringstream iss1(wholeFile);
	Node<User*> * l = userList -> getHead();
	while (getline(iss1, token, '\f'))
	{
		istringstream iss2(token);
		while(getline(iss2, temp))
		{
			((User*)(l -> getData())) -> addFriend(getUser(temp));
		}
		l = l -> getNext();
	}
	infile.close();
}

void UserNetwork::readRequestsList()
{
	ifstream infile;
	infile.open("requests.txt");
	string s, wholeFile;
	while (getline(infile, s))
	{
		wholeFile += s + "\n";		
	}
	string token, temp;
	istringstream iss1(wholeFile);
	Node<User*> * l = userList -> getHead();
	while (getline(iss1, token, '\f'))
	{
		istringstream iss2(token);
		while(getline(iss2, temp))
		{
			((User*)(l -> getData())) -> addFriendRequest(getUser(temp));
		}
		l = l -> getNext();
	}
	infile.close();
}

void UserNetwork::readCommentsList()
{
	ifstream infile;
	infile.open("comments.txt");
	string s, wholeFile;
	while(getline(infile, s))
	{
		wholeFile += s + "\n";
	}
	string token, temp;
	istringstream iss1(wholeFile);
	Node<User*> * l = userList -> getHead();
	while(getline(iss1, token, '\f'))
	{
		((Wall*)(((User*)(l -> getData())) -> getWall())) -> parseWallComments(token, (UserNetwork*)this);
		l = l -> getNext();
	}
}

UserNetwork::~UserNetwork()
{
}