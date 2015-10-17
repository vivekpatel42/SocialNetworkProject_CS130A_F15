#ifndef WALLPOST_H
#define WALLPOST_H

#include <string>
#include <ctime>

using namespace std;

class WallPost{

	public:
		WallPost();
		explicit WallPost(string _post);
		explicit WallPost(string _post, string _mood);
		string getPost();
		void setPost(string _post);
		time_t getTime();
		void setTime(time_t _postTime);
		string getMood();
		void setMood(string _mood);
		void printPost();

	private:
		string post;
		time_t postTime;
		string mood;
};

#endif