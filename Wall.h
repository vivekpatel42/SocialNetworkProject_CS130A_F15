#ifndef WALL_H
#define WALL_H

#include <string>
#include <iostream>

using namespace std;

class Wall {

	public:
		Wall();
		Wall(DoubleLinkedList<WallPost> * _posts);
		void addPost(string post);
		void addPost(string post, string mood);
		void removePost(int i);
		string getUsername() const;
		void setUsername(string _username);
		string toString();
		void parseString(string input);
		~Wall();

		// Linked list of wall posts on this wall.
		DoubleLinkedList<WallPost> * posts;

	private:
		string username;
};

#endif