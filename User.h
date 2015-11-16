#ifndef USER_H
#define USER_H

#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include "Node.h"
#include "LinkedList.h"
#include "Wall.h"
#include "Array.h"

using namespace std;

class User {

	public:
		User();
		explicit User(string _username);
		explicit User(string _username, string _password, string _fullName);
		explicit User(string _username, string _password, string _fullName, string _city);
		Wall * getWall() const;
		void setWall(Wall * w);
		string getUsername() const;
		void setUsername(string _username);
		string getPassword() const;
		void setPassword(string _password);
		string getFullName() const;
		void setFullName(string _fullName);
		string getCity() const;
		void setCity(string _city);
		void addPost(string post);
		void addPost(string post, string mood);
		void deletePost(int i);
		void addFriend(User* u);
		void addFriendRequest(User* u);
		bool containsFriend(string _username);
		bool containsRequest(string _username);
		string getUserInfo() const;
		string toString();
		string toStringLast();
		string friendsToString();
		string friendsToStringLast();
		string requestsToString();
		string requestsToStringLast();
		string searchUserInfo();
		void parseUserInfo(string userInfo);
		~User();
		List<User*> * friends;
		List<User*> * friendRequests;	
	private:
		Wall * userWall;
		string username;
		string password;
		string fullName;
		string city;
};

#endif