#include <iostream>
#include <string>
#include <cstring>
#include "Array.h"


using namespace std;


int main()
{
	Array<string> * arrayList = new Array<string>();
	arrayList -> appendItem("a");
	arrayList -> appendItem("b");
	arrayList -> appendItem("c");
	arrayList -> appendItem("d");
	arrayList -> appendItem("e");
	arrayList -> insert(5, "pls");
	arrayList -> insert(4, "no");
	arrayList -> remove(2);
	arrayList -> printList();
	arrayList -> clearList();
	arrayList -> printList();		
}