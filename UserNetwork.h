#ifndef USERNETWORK_H
#define USERNETWORK_H

#include <iostream>
#include <fstream>

using namespace std;

class UserNetwork {

	public:
		UserNetwork();
		void addUser(User u);
		void deleteUser(string username);
		void writeUserList();
		void readUserList(ifstream dataFile);
		~UserNetwork();
		DoubleLinkedList<User> * userList;
};


#endif