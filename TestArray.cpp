#include <iostream>
#include <string>
#include <cstring>
#include "Array.h"
#include "User.h"

using namespace std;


int main()
{
	Array<User*> * arrayList = new Array<User*>();
	User* myUser = new User("pls", "where", "am", "I");
	arrayList -> appendItem(myUser);
	cout << ((User*)(arrayList -> get(0))) -> toString();	
}