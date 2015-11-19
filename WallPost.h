#ifndef WALLPOST_H
#define WALLPOST_H

#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include "Node.h"
#include "LinkedList.h"
#include "Array.h"
#include "WallPostResponse.h"
#include "User.h"
#include "UserNetwork.h"

using namespace std;

class User;
class WallPostResponse;
class UserNetwork;

class WallPost {

	public:
		WallPost();
		explicit WallPost(string _post);
		explicit WallPost(string _post, string _mood);
		explicit WallPost(string _post, string _mood, string _poster);
		string getPost() const;
		void setPost(string _post);
		time_t getTime() const;
		void setTime(time_t _postTime);
		string getMood() const;
		void setMood(string _mood);
		string getPoster() const;
		void setPoster(string _poster);
		void addComment(WallPostResponse wpr);
		string toString();
		string commentsToString();
		string commentsToStringLast();
		void parseWallPostComments(string input, UserNetwork* un);
		~WallPost();

		List<WallPostResponse> * commentList;

	private:
		string post;
		time_t postTime;
		string mood;
		string poster;
};

#endif
