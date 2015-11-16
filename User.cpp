#include "User.h"

using namespace std;

User::User()
{
	friends = new Array<User*>();
	friendRequests = new Array<User*>();
	userWall = new Wall();
	username = "";
	password = "";
	fullName = "";
	city = "";
}

User::User(string _username)
{
	friends = new Array<User*>();
	friendRequests = new Array<User*>();
	userWall = new Wall();
	username = _username;
	password = "";
	city = "";	
}

User::User(string _username, string _password, string _fullName)
{
	friends = new Array<User*>();
	friendRequests = new Array<User*>();
	userWall = new Wall();
	username = _username;
	password = _password;
	fullName = _fullName;
	city = "";

}

User::User(string _username, string _password, string _fullName, string _city)
{
	friends = new Array<User*>();
	friendRequests = new Array<User*>();
	userWall = new Wall();
	username = _username;
	password = _password;
	fullName = _fullName;
	city = _city;
}

Wall * User::getWall() const
{
	return userWall;
}

void User::setWall(Wall * w)
{
	userWall = w;
}

string User::getUsername() const
{
	return username;
}

void User::setUsername(string _username)
{
	username = _username;
}

string User::getPassword() const
{
	return password;
}

void User::setPassword(string _password)
{
	password = _password;
}

string User::getFullName() const
{
	return fullName;
}

void User::setFullName(string _fullName)
{
	fullName = _fullName;
}

string User::getCity() const
{
	return city;
}

void User::setCity(string _city)
{
	city = _city;
}

void User::addPost(string post)
{
	userWall -> addPost(post);
}

void User::addPost(string post, string mood)
{
	userWall -> addPost(post, mood);
}

void User::deletePost(int i)
{
	userWall -> removePost(i);
}

void User::addFriend(User* u)
{
	friends -> appendItem(u);
}

void User::addFriendRequest(User* u)
{
	friendRequests -> appendItem(u);
}

bool User::containsFriend(string _username)
{
	for (int i = 0; i < (friends -> getCount()); i++)
	{
		if(_username.compare(((User*)(friends -> get(i))) -> getUsername()) == 0)
		{
			return true;
		}
		return false;
	}
}

bool User::containsRequest(string _username)
{
	for (int i = 0; i < (friendRequests -> getCount()); i++)
	{
		if(_username.compare(((User*)(friendRequests -> get(i))) -> getUsername()) == 0)
		{
			return true;
		}
		return false;
	}
}

string User::getUserInfo() const
{
	string result = username + "\n" + password + "\n" 
					+ fullName + "\n" + city + "\n";

	return result;
}

string User::toString()
{
	string result = getUserInfo();
	result += userWall -> toString();
	result += '\f';
	return result;
}

string User::toStringLast()
{
	string result = getUserInfo();
	result += userWall -> toString();
	return result;
}

string User::friendsToString()
{
	string result;
	for (int i = 0; i < (friends -> getCount()); i++)
	{
		result += ((User*)(friends -> get(i))) -> getUsername();
		result += '\n';
	}
	result += '\f';
	return result;	
}

string User::friendsToStringLast()
{
	string result;
	for (int i = 0; i < (friends -> getCount()); i++)
	{
		result += ((User*)(friends -> get(i))) -> username;
		result += '\n';
	}
	return result;
}

string User::requestsToString()
{
	string result;
	for (int i = 0; i < (friendRequests -> getCount()); i++)
	{
		result += ((User*)(friendRequests -> get(i))) -> username;
		result += '\n';
	}
	result += '\f';
	return result;
}

string User::requestsToStringLast()
{
	string result;
	for (int i = 0; i < (friendRequests -> getCount()); i++)
	{
		result += ((User*)(friendRequests -> get(i))) -> username;
		result += '\n';
	}
	return result;
}

string User::searchUserInfo()
{
	string result = fullName + "\n" + city + "\n";
	return result;
}

void User::parseUserInfo(string userInfo)
{
	string token;
	istringstream iss(userInfo);
	getline(iss, token);
	username = token;
	getline(iss, token);
	password = token;
	getline(iss, token);
	fullName = token;
	getline(iss, token);
	city = token;
}

User::~User()
{}