#ifndef WALLPOST_H
#define WALLPOST_H

#include <iostream>
#include <string>
#include <ctime>
#include "Node.h"
#include "LinkedList.h"
#include "Array.h"
#include "WallPostResponse.h"
#include "User.h"

using namespace std;

class WallPost {

	public:
		WallPost();
		explicit WallPost(string _post);
		explicit WallPost(string _post, string _mood);
		explicit WallPost(string _post, string _mood, User* _poster);
		string getPost() const;
		void setPost(string _post);
		time_t getTime() const;
		void setTime(time_t _postTime);
		string getMood() const;
		void setMood(string _mood);
		User* getPoster();
		void setPoster(User* _poster);
		string toString();
		~WallPost();

		List<WallPostResponse> * commentList;

	private:
		string post;
		time_t postTime;
		string mood;
		User* poster; 
};

#endif
