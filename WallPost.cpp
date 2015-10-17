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

string WallPost::getPost() 
{
	return post;
}

void WallPost::setPost(string _post) 
{
	post = _post;
}

time_t WallPost::getTime()
{
	return postTime;
}

void WallPost::setTime(time_t _postTime)
{
	postTime = _postTime;
}

string WallPost::getMood()
{
	return mood;
}

void WallPost::setMood(string _mood)
{
	mood = _mood;
}

void WallPost::printPost()
{
	cout << "Status: " << post << endl;
	cout << "Time: " << ctime(&postTime) << endl;
	cout << "Mood: " << mood << endl;
}
