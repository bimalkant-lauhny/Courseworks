#include "Person.h"
#include <iostream>
using std::string;
using std::cout;
using std::endl;


Person::Person(string first,string last,
	int arbitrary) : firstname(first),lastname(last),
	arbitrarynumber(arbitrary)
{
	cout << "Person Constructor for " << GetName() << endl;
}

Person::~Person()
{
	cout << "Person Destructor for " << GetName() << endl;
}

string Person::GetName() const
{
	return firstname + " " + lastname;
}
