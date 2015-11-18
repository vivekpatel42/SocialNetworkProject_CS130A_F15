
#include <iostream>
#include <string>
#include "ListNode.h"
#include "DoubleLinkedList.h"
#include "WallPost.h"
#include "Wall.h"
#include "User.h"
#include "UserNetwork.h"

using namespace std;

void searchUser(User * u, UserNetwork * network);

int main()
{
	User* currentUser;
	UserNetwork * un = new UserNetwork();
	un -> readUserList();
	bool running = true, program = false;
	while (running)
	{
		char input;
		if (!program)
		{

			cout << "Number of users: " << un -> userList -> getCount() << endl;
			cout << "Please enter a letter to select what you would like to do: " << endl << "--------------------------------------" << endl;
			cout << "Create a new user. (n)" << endl;
			cout << "Log in as a user. (l)" << endl;
			cout << "Exit the program. (x)" << endl << "--------------------------------------" << endl;
			cin >> input;
			cin.ignore(1,'\n');	
		}
		while (program)
		{
			char userInput;
			cout << "Logged in as " << currentUser -> getUsername() << endl << "--------------------------------------" << endl;
			cout << "Pending friend requests: " << (currentUser -> friendRequests) -> getCount() << endl << "--------------------------------------" << endl;
			cout << "What would you like to do next?" << endl;
			cout << "Add a new post. (a)" << endl;
			cout << "Display wall. (w)" << endl;
			cout << "Erase post. (e)" << endl;
			cout << "View/accept/delete pending friend requests. (v)" << endl;
			cout << "Search user network. (s)" << endl;
			cout << "Delete user profile. (d)" << endl; // t for truncate
			cout << "Back to main menu. (b)" << endl;
			cout << "Exit the program. (x)" << endl << "--------------------------------------" << endl;
			cin >> input;
			cin.ignore(1,'\n');
			if (input == 'a')
			{
				string status, mood;
				cout << "Please enter the status: ";
				getline(cin, status);
				cout << "Please enter your mood: ";
				getline(cin, mood);
				currentUser -> addPost(status, mood);
			}
			else if (input == 'w')
			{
				cout << "--------------------------------------" << endl;
				cout << (currentUser -> getWall()) -> toStringDisplay();
				cout << "--------------------------------------" << endl;
			}
			else if (input == 'e')
			{
				int del;
				cout << "Which post would you like to delete? (Select the number of the post)" << endl << "--------------------------------------" << endl;
				cout << (currentUser -> getWall()) -> toStringDisplay();
				cout << "--------------------------------------" << endl;
				cin >> del;
				(currentUser -> getWall()) -> removePost(del);
			}
			else if (input == 'v')
			{
				cout << "Friend requests: " << endl << "--------------------------------------" << endl;
				for(int i = 0; i < (currentUser -> friendRequests) -> getCount(); i++)
				{
					cout << "(" << to_string(i) << "): " << ((User*)(currentUser -> friendRequests -> get(i))) -> searchUserInfo();
				}
				char requestAction;
				cout << "What would you like to do next?" << endl << "--------------------------------------" << endl;
				cout << "Accept request! (a)" << endl;
				cout << "Delete request. (d)" << endl;
				cin >> requestAction;
				if (requestAction == 'a')
				{
					int requestAccept;
					cout << "Please type the number of the user you would like to befriend: ";
					cin >> requestAccept;
					if (requestAccept >= 0 && requestAccept < (currentUser -> friendRequests) -> getCount())
					{
						currentUser -> addFriend(((User*)(currentUser -> friendRequests -> get(requestAccept))));
						currentUser -> friendRequests -> remove(requestAccept);
					}
				}
				else if (requestAction == 'd')
				{
					int requestDelete;
					cout << "Please type the request you would like to delete: ";
					cin >> requestDelete;
					if (requestDelete >= 0 && requestDelete < (currentUser -> friendRequests) -> getCount())
					{
						currentUser -> friendRequests -> remove(requestDelete);
					}
				}
			}
			else if (input == 's')
			{
				searchUser(currentUser, un);
			}
			// Fix: Cannot delete the first user.
			else if (input == 'd')
			{
				char confirm;
				cout << "Are you sure? This cannot be undone!!! (Y or N)" << endl << "--------------------------------------" << endl;
				cin >> confirm;
				if (confirm == 'y' || confirm == 'Y')
				{
					un -> deleteUser(currentUser -> getUsername());
					program = false;
				}
			}
			else if (input == 'b')
			{
				program = false;	
			}
			else if (input == 'x')
			{
				program = false;
				running = false;
			}
		}
		if (input == 'n')
		{
			bool running2 = true;
			while(running2)
			{
				string newUsername;
				cout << "Please enter your preferred username: ";
				getline(cin, newUsername);
				if (un -> contains(newUsername))
				{
					cout << "Username already exists in the network." << endl << "Please enter a unique username." << endl;
				} 
				else 
				{
					string newPassword;
					string newFullName;
					string newCity;
					cout << "Please enter a password for the new account: ";
					getline(cin, newPassword);
					cout << "Please enter your name: ";
					getline(cin, newFullName);
					cout << "Please enter the city you are from: ";
					getline(cin, newCity);
					User* u1 = new User(newUsername, newPassword, newFullName, newCity);
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
				User* u2 = un -> getUser(usernameInput);
				cout << "Password: " << endl;
				cin >> passwordInput;
				if (passwordInput.compare(u2 -> getPassword()) == 0) 
				{
					currentUser = u2;
					program = true;
				}
				else 
				{
					cout << "The password you have entered is incorrect. Exiting...";
				}
			}
			else
			{
				cout << "The username you have entered does not exist in the network. Please try again.\n";	
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

void searchUser(User * u, UserNetwork * network)
{
	bool running = true;
	string input;
	int i = 0;
	while (running)
	{
		cout << "Please enter your search query: ";
		getline(cin, input);
		Node<User*> * n = network -> userList -> getHead();
		while (n)
		{
			if (((((User*)(n -> getData())) -> getUsername()).find(input) != string::npos) || 
				((((User*)(n -> getData())) -> getFullName()).find(input) != string::npos))
			{
				cout << "(" << to_string(i) << ")\n" << ((User*)(n -> getData())) -> searchUserInfo();
			}
			n = n -> getNext();
			i++;
		}
		int user; 
		cout << "Please enter the number of the user you would like to send a friend request to: ";
		cin >> user;
		((User*)(network -> userList -> get(user))) -> friendRequests -> appendItem(u);
		running = false;
	}
	return;
}