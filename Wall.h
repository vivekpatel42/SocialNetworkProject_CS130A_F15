#ifndef WALL_H
#define WALL_H

#include <string>
#include <iostream>
#include "ListNode.h"
#include "DoubleLinkedList.h"
#include "WallPost.h"

using namespace std;

class Wall {

	public:
		Wall();
		void addPost(string post);
		void addPost(string post, string mood);
		void removePost(int i);
		string getUsername() const;
		void setUsername(string _username);
		int getCount() const;
		string toString();
		void parseWall(string input);
		~Wall();

		// Linked list of wall posts on this wall.
		DoubleLinkedList<WallPost> * posts;

	private:
		string username;
		int count;
};

#endif