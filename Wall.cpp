#include "Wall.h"

using namespace std;

Wall::Wall()
{
	posts = new DoubleLinkedList<WallPost>();
	count = 0;
}

void Wall::addPost(WallPost post)
{
	posts -> appendItem(post);
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
	int count = 1;
	string token;
	struct tm _timeStruct;
	istringstream iss(input);
	while (getline(iss, token))
	{
		if (((count - 1) % 3) == 0)
		{	
			temp.setPost(token);
			count++;	
		}
		else if (((count - 1) % 3) == 1)
		{
			// strptime(token.c_str(), "%a %b %d %T %Y", &_timeStruct);
			// time_t _postTime = mktime(&_timeStruct);
			// temp.setTime(_postTime);
			// count++;
		}
		else if (((count - 1) % 3) == 2)
		{
			temp.setMood(token);
			count++;
			addPost(temp);
		}
	}
}

Wall::~Wall()
{}
