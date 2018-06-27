// Memory.cpp : Defines the entry point for the console application.
//

#include "Person.h"

int main()
{
	Person Kate("Kate", "Gregory", 345);
	Kate.AddResource();
	Kate.SetFirstName("Kate2");
	Kate.AddResource();
	Person Kate2 = Kate;
	/* If there is no explicit copy ctor, there will be shallow copying of
	Kate at Kate2. When Kate goes out of scope, it's dtor is called and resource
	is deleted. Now when Kate2 goes out of scope, it's dtor is called which
	tries to delete the resource already deleted by Kate.*/
	return 0;
}

