#ifndef USER_H
#define USER_H

using namespace std;

class User {

	public:
		User();
		explicit User(string _username);
		explicit User(string _username, string _password, string _fullName, string _city);
		Wall getWall() const;
		string getUsername() const;
		void setUsername(string _username);
		string getFullName() const;
		void setFullName(string _fullName);
		string getCity() const;
		void setCity(string _city);
		void addPost(string post);
		void addPost(string post, string mood);
		void deletePost(int i);
		string getUserInfo() const;
		~User();
	private:
		Wall userWall;
		string username;
		string password;
		string fullName;
		string city;
};

#endif