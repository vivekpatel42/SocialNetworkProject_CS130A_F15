#ifndef USERNETWORK_H
#define USERNETWORK_H

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include "Node.h"
#include "LinkedList.h"
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
		List<User> * userList;
};


#endif