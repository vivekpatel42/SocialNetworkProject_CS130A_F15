#ifndef WALLPOST_H
#define WALLPOST_H

#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class WallPost {

	public:
		WallPost();
		explicit WallPost(string _post);
		explicit WallPost(string _post, string _mood);
		string getPost() const;
		void setPost(string _post);
		time_t getTime() const;
		void setTime(time_t _postTime);
		string getMood() const;
		void setMood(string _mood);
		string printPost();
		~WallPost();
	private:
		string post;
		time_t postTime;
		string mood;
};

#endif