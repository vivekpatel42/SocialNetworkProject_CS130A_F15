#include "Wall.h"

using namespace std;

Wall::Wall()
{
	posts = new LinkedList<WallPost>();
}

void Wall::addPost(WallPost post)
{
	posts -> appendItem(post);
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
	posts -> remove(i);
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
	string result = "";
	Node<WallPost> * l = new Node<WallPost>();
	l = posts -> getHead();
	if (posts -> getCount() == 0)
	{
		return result;
	}
	else if (posts -> getCount() == 1)
	{
		result += (((WallPost)(l -> getData())).toString());
		return result;
	}
	else
	{
		while(l)
		{
			result.append(((WallPost)(l -> getData())).toString());
			l = l -> getNext();
		}
	}	
	return result;
}

string Wall::toStringDisplay()
{
	string result = "";
	Node<WallPost> * l = new Node<WallPost>();
	l = posts -> getHead();
	if (posts -> getCount() == 0)
	{
		return result;
	}
	int i = 0;
	if (posts -> getCount() == 1)
	{
		result += "(" + to_string(i) + ")\n";
		result += (((WallPost)(l -> getData())).toString());
		return result;
	}
	else
	{
		while(l)
		{
			result += "(" + to_string(i) + ")\n";
			result.append(((WallPost)(l -> getData())).toString());
			l = l -> getNext();
			i++;
		}
	}	
	return result;
}

void Wall::parseWall(string input)
{
	int i = 0;
	string token;
	time_t postTime;
	struct tm timeStruct;
	WallPost temp = WallPost();
	istringstream iss(input);
	while (getline(iss, token))
	{
		if ((i % 3) == 0) 	
		{
			temp.setPost(token);
		}
		else if ((i % 3) == 1)
		{
			
			strptime(token.c_str(), "%a %b %d %T %Y", &timeStruct);
			time_t _postTime = mktime(&timeStruct);
			temp.setTime(_postTime);
		}
		else if ((i % 3) == 2)
		{
			temp.setMood(token);
			addPost(temp);
		}
		i++;
	}
}

Wall::~Wall()
{}
