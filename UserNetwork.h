#ifndef USERNETWORK_H
#define USERNETWORK_H

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
		void readUserList(ifstream dataFile);
		~UserNetwork();
		DoubleLinkedList<User> * userList;
};


#endif