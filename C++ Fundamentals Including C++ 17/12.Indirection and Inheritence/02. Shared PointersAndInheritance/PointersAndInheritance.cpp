// PointersAndInheritance.cpp : Defines the entry point for the console application.
//

#include "Person.h"
#include "Tweeter.h"
#include <iostream>
using std::cout;
using std::endl;
#include <memory>
using std::shared_ptr;
using std::make_shared;

int Dummy(Person const& p) { return p.GetNumber(); }

int main()
{
	Person Kate ("Kate", "Gregory",456);
	Person & rKate = Kate;
	Person* pKate = &Kate;

	Tweeter KateGregcons ("Twitter","User",567,"@gregcons");
	Person* pKateGregcons = &KateGregcons;
	Person& rpKateGregcons = KateGregcons;
	Tweeter& rtKateGregcons = KateGregcons;

	cout << rKate.GetName() << endl;
	cout << pKate->GetName() << endl;
	cout << KateGregcons.GetName() << endl;
	cout << rpKateGregcons.GetName() << endl;
	cout << rtKateGregcons.GetName() << endl;
	cout << pKateGregcons->GetName() << endl;

	//Person* Someone = new Tweeter("Someone", "Else", 567, "@someone");
	//cout << Someone->GetName() << endl;
	//delete Someone;
	
	/*
	Tweeter version of GetName() will run because of virtual keyword used in
	Person class.
	*/
	shared_ptr<Person> spKate = make_shared<Tweeter>("Third", "Name", 678, "@handle");
	cout << spKate->GetName() << endl;
	
	/*
	You cannot do something as below commented out line. A Parent class object
	cannot be assigned to a Derived class holder due to less info is held by
	Parent class object. It may be supported explicitly by assigning default
	values to Derived class object but it is not implicitly supported by
	compiler.
	*/
	//KateGregcons = Kate;
	
	/*
	Due to assignment of Derived class object into Parent class holder, the line
	below will lead to 'Slicing' i.e. the Parent class holder will just throw
	away extra members. It doesn't matter whether you use virtual keyword here
	or not. It means that virtual keyword works only for pointers and references.
	*/
	Kate = KateGregcons;
	cout << Kate.GetName() << endl;
	/*
	Generally, this kind of Slicing while copying might happen in case of a 
	'call by value' to a function, so, to avoid slicing, it's better to use 
	'call by reference' here. For ex. see Dummy() function call below and the
	function definition above.
	*/
	int x;
	x = Dummy(Kate); /* in this case, even if call by ref is not used, there will
	be same result */
	x = Dummy(KateGregcons); /* In this case, if call by val is used, slicing
	will happen. Hence to avoid slicing, use call by ref*/




}

