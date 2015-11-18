#ifndef WALLPOSTRESPONSE_H
#define WALLPOSTRESPONSE_H

#include <iostream>
#include <string>
#include <ctime>
#include "Array.h"
#include "User.h"

using namespace std;

class User;

class WallPostResponse
{

	public:
		WallPostResponse();
		explicit WallPostResponse(string _comment);
		explicit WallPostResponse(string _comment, User * _commenter);
		string getComment();
		time_t getCommentTime();
		User* getCommenter();
		void setComment(string _comment);
		void setCommenter(User * _commenter);

	private:
		string comment;
		time_t commentTime;
		User* commenter;
};

#endif