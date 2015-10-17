

int main()
{
	bool running = true;
	while (running)
	{
		char input;
		cout << "Please enter a letter to select what you would like to do: " << endl;
		cout << "Create a new user. (n)" << endl;
		cout << "Log in as a user. (l)" << endl;
		cout << "Exit the program. (x)" << endl;
		cin >> input;
		if (input != 'n' || input != 'l' || input != 'x') 
		{
			cout << "Invalid input, please try again."
		}
		else if (input == 'n')
		{

		}
		else if (input == 'l')
		{

		}
		else if (input == 'x')
		{
			running = false;
		}
	}
	

	return 0;
}