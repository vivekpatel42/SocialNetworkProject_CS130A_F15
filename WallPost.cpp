#include "WallPost.h"

using namespace std;

WallPost::WallPost() 
{
	post = "";
	postTime = time(0);
	mood = "";
	poster = "";
	commentList = new Array<WallPostResponse>();
}

WallPost::WallPost(string _post) : post { _post }
{
	postTime = time(0);
	mood = "";
	poster = "";
	commentList = new Array<WallPostResponse>();
}

WallPost::WallPost(string _post, string _mood) : post { _post }, mood { _mood }
{
	postTime = time(0);
	poster = "";
	commentList = new Array<WallPostResponse>();
}

WallPost::WallPost(string _post, string _mood, string _poster) : post { _post }, mood { _mood }, poster { _poster }
{
	postTime = time(0);
	commentList = new Array<WallPostResponse>();
}

string WallPost::getPost() const
{
	return post;
}

void WallPost::setPost(string _post) 
{
	post = _post;
}

time_t WallPost::getTime() const
{
	return postTime;
}

void WallPost::setTime(time_t _postTime)
{
	postTime = _postTime;
}

string WallPost::getMood() const
{
	return mood;
}

void WallPost::setMood(string _mood)
{
	mood = _mood;
}

string WallPost::getPoster() const
{
	return poster;
}

void WallPost::setPoster(string _poster)
{
	poster = _poster;
}

void WallPost::addComment(WallPostResponse wpr)
{
	commentList -> appendItem(wpr);
}
	
string WallPost::toString()
{
	string result = post + "\n" + ctime(&postTime) + mood + "\n";
	result += poster + "\n";
	return result;
}

string WallPost::commentsToString()
{
	string result;
	if ((commentList -> getCount()) == 0)
	{
		result += "\r";
		return result;
	}
	for(int i = 0; i < (commentList -> getCount()); i++)
	{
		result += ((WallPostResponse)(commentList -> get(i))).toString();
	}
	result += "\r";
	return result;
}

string WallPost::commentsToStringLast()
{
	string result;
	if ((commentList -> getCount()) == 0)
	{
		result += "";
		return result;
	}
	for(int i = 0; i < (commentList -> getCount()); i++)
	{
		result += ((WallPostResponse)(commentList -> get(i))).toString();
	}
	return result;
}

void WallPost::parseWallPostComments(string input, UserNetwork* un)
{
	int i = 0;
	string token;
	istringstream iss1(input);
	struct tm timeStruct;
	WallPostResponse temp = WallPostResponse();
	while(getline(iss1, token))
	{
		if((i % 3) == 0)
		{
			temp.setComment(token);
		}
		else if((i % 3) == 1)
		{
			strptime(token.c_str(), "%a %b %d %T %Y", &timeStruct);
			time_t _commentTime = mktime(&timeStruct);
			temp.setCommentTime(_commentTime);
		}
		else if((i % 3) == 2)
		{
			temp.setCommenter((User*)(un -> getUser(token)));
			addComment(temp);
		}
	}
}

WallPost::~WallPost() {}
