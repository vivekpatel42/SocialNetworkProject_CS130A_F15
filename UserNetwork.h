#ifndef USERNETWORK_H
#define USERNETWORK_H

#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
#include "ListNode.h"
#include "DoubleLinkedList.h"
#include "User.h"

using namespace std;

class UserNetwork {

	public:
		UserNetwork();
		void addUser(User u);
		void deleteUser(string username);
		bool contains(string username);
		User getUser(string username);
		void writeUserList();
		void readUserList();
		~UserNetwork();
		DoubleLinkedList<User> * userList;
	private:
		const string END_USER_DELIM = "----------";
		const int MAX_CHARS_PER_LINE = 512;
		const int MAX_TOKENS_1 = 50;
		const int MAX_TOKENS_2 = 512;
};


#endif