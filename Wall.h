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
#include "User.h"
#include "UserNetwork.h"

using namespace std;

class User;
class WallPost;

class Wall {

	public:
		Wall();
		void addPost(WallPost post);
		void addPost(string post);
		void addPost(string post, string mood);
		void addPost(string post, string mood, string poster);
		void removePost(int i);
		string getUsername() const;
		void setUsername(string _username);
		string toString();
		string toStringDisplay();
		string commentsToString();
		string commentsToStringLast();
		void parseWall(string input);
		void parseWallComments(string input, UserNetwork* un);
		~Wall();

		// Linked list of wall posts on this wall.
		List<WallPost> * posts;

	private:
		string username;
};

#endif