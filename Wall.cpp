#include "Wall.h"

using namespace std;

Wall::Wall()
{
	posts = new DoubleLinkedList<WallPost>();
}

Wall::Wall(DoubleLinkedList<WallPost> * _posts) 
{
	posts = _posts;
}

void Wall::addPost(string post)
{
	WallPost wp = WallPost(post);
	posts -> appendItem(wp);
}

void Wall::addPost(string post, string mood)
{
	WallPost wp = WallPost(post, mood);
	posts -> appendItem(wp);
}

void Wall::removePost(int i)
{
	posts -> removeItem(i);
}

string Wall::getUsername() const
{
	return username;
}

void Wall::setUsername(string _username)
{
	username = _username;
}

string Wall::toString()
{
	string result;
	ListNode<WallPost> * l = posts -> getHead();
	while (l -> getNext())
	{
		result.append(l -> getData() -> printPost());
		result.append("\n");
	}
	result.append(l -> getData() -> printPost());
}

void Wall::parseString(string input)
{
	
}