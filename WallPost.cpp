#include "WallPost.h"

using namespace std;

WallPost::WallPost() 
{
	postTime = time(0);
}

WallPost::WallPost(string _post) : post { _post }
{
	postTime = time(0);
}

WallPost::WallPost(string _post, string _mood) : post { _post }, mood { _mood }
{
	postTime = time(0);
}

WallPost::WallPost(string _post, time_t _postTime, string _mood) : post { _post }, mood { _mood }
{
	postTime = _postTime;
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

string WallPost::printPost()
{
	struct tm * timeInfo;
	timeInfo = localtime(&postTime);
	string result = post + "\t" + asctime(timeInfo) + "\t" + mood + "\t";
	cout << result;
	return result;
}

WallPost::~WallPost() {}
