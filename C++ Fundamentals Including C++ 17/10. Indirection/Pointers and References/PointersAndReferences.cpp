// PointersAndReferences.cpp : Defines the entry point for the console application.
//

/*
Pointers vs References
References - 
1. Can only set target when declaring it
2. All other actions go through it, i.e. whatever operation done on reference is
being done on target
3. Cannot be made to refer to something else (no re-targeting or re-binding)

Pointers -
1. Can point to something that exists
2. Can point "nowhere"
3. Can be made to point to something else
*/
#include <string>
using std::string;
#include <iostream>
using std::cout;
using std::endl;

#include "Person.h"


int main()
{
	int a = 3;
	cout << "a is " << a << endl;
	int& rA = a;
	rA = 5;
	cout << "a is " << a << endl;

	Person Kate("Kate", "Gregory", 234);
	Person& rKate = Kate;
	rKate.SetNumber(345);
	cout << "rKate: " << rKate.GetName() << " " << rKate.GetNumber() << endl;
    
    /*
    Uncomment the 3 lines below and compiler the program. You'll get errors.
    It shows that references must be set to target while declaring.
    */
	//int& badReference;
	//badReference = 3;
	//cout << badReference;


	int* pA = &a;
	*pA = 4;
	cout << "a is " << a << endl;
	int b = 100;
	pA = &b;
	(*pA)++;
	cout << "a " << a << ", *pA " << *pA << endl; 

	Person* pKate = &Kate;
	(*pKate).SetNumber(235);
	pKate->SetNumber(236);
	cout << "Kate: " << Kate.GetName() << " " << Kate.GetNumber() << endl;
	cout << "pKate: " << pKate->GetName() << " " << pKate->GetNumber() << endl;


    /*
    Checking before dereferencing badPointer is important because you cannot
    dereference a nullptr.
    */
	int* badPointer=nullptr;
	if (badPointer)
	{
		*badPointer = 3;
		cout << *badPointer << endl;
	}


	return 0;
}

