// PointersAndInheritance.cpp : Defines the entry point for the console application.
//

#include "Person.h"
#include "Tweeter.h"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
	Person Kate ("Kate", "Gregory",456);
	Person & rKate = Kate;
	Person* pKate = &Kate;

	Tweeter KateGregcons ("Kate","Gregory",567,"@gregcons");
	
	/*
	Also, a variable of type 'Pointer or Reference to Base class' can accomodate
	'Pointer or Reference to Derived class', since Derived class generally have 
	more info than required by the type.
	*/

	/*
	The next two objects will call the Person (parent class) version of 
	GetName() function. To call the Tweeter (child class) version of GetName
	using these two Person Pointer and Reference, GetName() must be marked
	virtual in Person class.
	*/
	Person* pKateGregcons = &KateGregcons; 
	Person& rpKateGregcons = KateGregcons;
	
	/*
	Since this is a Tweeter class reference, the Tweeter class GetName() version
	will be called in any case. Also, a variable of type 'Pointer or Reference to
	derived class' cannot accomodate 'Pointer or Reference to Base class', since
	Base class doesn't have enough info for the required type.
	*/
	Tweeter& rtKateGregcons = KateGregcons;

	cout << rKate.GetName() << endl;
	cout << pKate->GetName() << endl;
	cout << KateGregcons.GetName() << endl;
	cout << rpKateGregcons.GetName() << endl;
	cout << rtKateGregcons.GetName() << endl;
	cout << pKateGregcons->GetName() << endl;
	
	/*
	For code below, if Person dtor is not marked virtual, the dtor for Tweeter
	will never go off, which is a memory leak as Someone's Tweeter resources never
	got released.
	Hence, even if a single function in Base class is marked virtual, one must
	mark the destructor virtual.
	*/
	Person* Someone = new Tweeter("Someone", "Else", 567, "@someone");
	cout << Someone->GetName() << endl;
	delete Someone;



}

