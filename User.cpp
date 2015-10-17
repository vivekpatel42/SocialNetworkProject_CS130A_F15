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

string User::getFullName() const
{
	return fullName;
}

void User::setFullName(string _fullName) const
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
	string result;
	result.append(username + "\n");
	result.append(password + "\n");
	result.append(fullName + "\n");
	result.append(city + "\n");
	return result;
}

User::~User()
{}