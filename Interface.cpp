
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
	bool running = true;
	while (running)
	{
		char input;
		UserNetwork * un = new UserNetwork();
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
			string newUsername;
			cout << "Please enter your preferred username." << endl;
			cin >> newUsername;
		}
		else if (input == 'l')
		{
			string usernameInput;
			cout << "Username: " << endl;
			cin >> usernameInput;
			if (un -> contains(usernameInput))
			{
				bool running2 = true;
				while(running2)
				{
					char userInput;
					cout << "Logged in as " << usernameInput << endl;
					cout << "What would you like to do next?" << endl;
					cout << "Display wall. (d)" << endl;
					cin >> userInput;
					if (userInput != 'd')
					{
						cout << "Invalid input, please try again.\n"
					}
					else 
					{
						User u = un -> getUser(usernameInput);
						u.getWall().toString();
					}
				}
			}
		}
		else if (input == 'x')
		{
			running = false;
		}
	}
	

	return 0;
};