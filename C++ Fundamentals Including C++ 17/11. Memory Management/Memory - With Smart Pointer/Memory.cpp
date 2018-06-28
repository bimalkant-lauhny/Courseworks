// Memory.cpp : Defines the entry point for the console application.
//

#include "Person.h"
#include <string>
using std::string;

int Dummy(Person p) { return p.GetNumber(); }

int main()
{
	{
		Person Kate("Kate", "Gregory", 345);
		Kate.AddResource();
		string s1 = Kate.GetResourceName();
		Kate.AddResource();
		
		/*
		Line below will perform shallow copying and increase the ref count,
		changes in Kate will be reflected in Kate2 and vice versa
		*/
		// here ref count will become 2
		Person Kate2 = Kate;
		
		// here ref count remains 2
		Kate = Kate2;
		
		/* 
		here ref count will become 3 since Kate2 is being copied into
		argument Person p of function Dummy 
		*/
		int j = Dummy(Kate2);
	}
	return 0;
}

