
#include <iostream>
#include <string>
#include "ListNode.h"
#include "DoubleLinkedList.h"
#include "WallPost.h"
#include "Wall.h"
#include "User.h"
#include "UserNetwork.h"

using namespace std;

int main()
{
	User currentUser;
	UserNetwork * un = new UserNetwork();
	un -> readUserList();
	bool running = true;
	while (running)
	{
		bool program = false;
		char input;
		cout << "Please enter a letter to select what you would like to do: " << endl;
		cout << "Create a new user. (n)" << endl;
		cout << "Log in as a user. (l)" << endl;
		cout << "Exit the program. (x)" << endl;
		cin >> input;
		if (input != 'n' && input != 'l' && input != 'x') 
		{
			cout << "Invalid input, please try again.\n";
		}
		else if (input == 'n')
		{
			bool running2 = true;
			while(running2)
			{
				string newUsername;
				cout << "Please enter your preferred username: " << endl;
				cin >> newUsername;
				if (un -> contains(newUsername))
				{
					cout << "Username already exists in the network." << endl << "Please enter a unique username.";
				} 
				else 
				{
					string newPassword;
					string newFullName;
					cout << "Please enter a password for the new account." << endl;
					cin >> newPassword;
					cout << "Please enter your name." << endl;
					cin >> newFullName;
					User u1 = User(newUsername, newPassword, newFullName);
					un -> addUser(u1);
					currentUser = u1;
					program = true;
					running2 = false;
				}
			}
		}
		else if (input == 'l')
		{
			string usernameInput;
			string passwordInput;
			cout << "Username: " << endl;
			cin >> usernameInput;
			if (un -> contains(usernameInput))
			{
				User u2 = un -> getUser(usernameInput);
				cout << "Password: " << endl;
				cin >> passwordInput;
				if (passwordInput.compare(u2.getPassword()) == 0) 
				{
					currentUser = u2;
				}
				else 
				{
					cout << "The password you have entered is incorrect. Exiting...";
				}
				program = true;
			}
		}
		else if (program)
		{
			char userInput;
			cout << "Logged in as " << currentUser.getUsername() << endl;
			cout << "What would you like to do next?" << endl;
			cout << "Display wall. (d)" << endl;
			cout << "Exit the program. (x)" << endl;
			cin >> userInput;
			if (userInput != 'd' && userInput != 'x')
			{
				cout << "Invalid input, please try again.\n";
			}
			else if (userInput == 'd')
			{
				currentUser.getWall().toString();
			}
			else if (userInput == 'x')
			{
				running = false;
			}

		}
		else if (input == 'x')
		{
			running = false;
		}
	}
	un -> writeUserList();
	return 0;
};