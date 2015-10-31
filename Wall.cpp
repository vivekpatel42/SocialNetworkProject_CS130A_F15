#include "Wall.h"

using namespace std;

Wall::Wall()
{
	posts = new DoubleLinkedList<WallPost>();
	count = 0;
}

void Wall::addPost(string post)
{
	WallPost wp = WallPost(post);
	posts -> appendItem(wp);
	count++;
}

void Wall::addPost(string post, string mood)
{
	WallPost * wp = new WallPost(post, mood);
	posts -> appendItem(*wp);
	count++;
}

void Wall::removePost(int i)
{
	posts -> removeItem(i);
	count--;
}

string Wall::getUsername() const
{
	return username;
}

void Wall::setUsername(string _username)
{
	username = _username;
}

int Wall::getCount() const
{
	return count;
}

string Wall::toString()
{
	string result = "";
	ListNode<WallPost> * l = new ListNode<WallPost>();
	l = posts -> getHead();
	for (int i = 0; i < count; i++)
	{
		result.append(((WallPost)(l -> getData())).toString());
		l = l -> getNext();
	}
	return result;
}

void Wall::parseWall(string input)
{
	posts -> clearList();
	string post, mood;
	time_t postTime;
}

Wall::~Wall()
{}
