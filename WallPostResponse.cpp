#include "WallPostResponse.h"

WallPostResponse::WallPostResponse()
{
	comment = "";
	commentTime = time(0);
	commenter = NULL;
}

WallPostResponse::WallPostResponse(string _comment)
{
	comment = _comment;
	commentTime = time(0);
	commenter = NULL;
}

WallPostResponse::WallPostResponse(string _comment, User * _commenter)
{
	comment = _comment;
	commentTime = time(0);
	commenter = _commenter;
}

string WallPostResponse::getComment()
{
	return comment;
}

time_t WallPostResponse::getCommentTime()
{
	return commentTime;
}

User* WallPostResponse::getCommenter()
{
	return commenter;
}

void WallPostResponse::setComment(string _comment)
{
	comment = _comment;
}

void WallPostResponse::setCommenter(User * _commenter)
{
	commenter = _commenter;
}