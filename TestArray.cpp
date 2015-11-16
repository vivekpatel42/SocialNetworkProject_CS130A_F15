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
	User* herUser = new User("omg", "pls", "yes");
	arrayList -> appendItem(myUser);
	arrayList -> appendItem(herUser);
	arrayList -> remove(0);
	cout << ((User*)(arrayList -> get(0))) -> toString();
}