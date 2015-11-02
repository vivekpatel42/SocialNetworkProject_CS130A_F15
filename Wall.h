#ifndef WALL_H
#define WALL_H

#include <string>
#include <cstring>
#include <ctime>
#include <iostream>
#include <sstream>
#include "Node.h"
#include "LinkedList.h"
#include "WallPost.h"

using namespace std;

class Wall {

	public:
		Wall();
		void addPost(WallPost post);
		void addPost(string post);
		void addPost(string post, string mood);
		void removePost(int i);
		string getUsername() const;
		void setUsername(string _username);
		string toString();
		string toStringDisplay();
		void parseWall(string input);
		~Wall();

		// Linked list of wall posts on this wall.
		List<WallPost> * posts;

	private:
		string username;
};

#endif