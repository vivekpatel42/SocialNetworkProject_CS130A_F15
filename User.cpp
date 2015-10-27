#include "User.h"

using namespace std;

User::User()
{
	userWall = Wall();
}

User::User(string _username)
{
	userWall = Wall();
	username = _username;
}

User::User(string _username, string _password, string _fullName)
{
	userWall = Wall();
	username = _username;
	password = _password;
	fullName = _fullName;
	city = "";
}

User::User(string _username, string _password, string _fullName, string _city)
{
	userWall = Wall();
	username = _username;
	password = _password;
	fullName = _fullName;
	city = _city;
}

Wall User::getWall() const
{
	return userWall;
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
	userWall.addPost(post);
}

void User::addPost(string post, string mood)
{
	userWall.addPost(post, mood);
}

void User::deletePost(int i)
{
	userWall.removePost(i);
}

string User::getUserInfo() const
{
	string result = username + "\n" + password + "\n" 
					+ fullName + "\n" + city + "\n";

	return result;
}

string User::toString()
{
	string result = "user\n";
	result += getUserInfo();
	result += userWall.toString();
	result += "enduser\n";
}

void User::parseUserInfo(string userInfo)
{

}

User::~User()
{}