#include "Person.h"
using std::string;

Person::Person(string first,string last,
	int arbitrary) 
	:
	firstname(first),lastname(last),
	arbitrarynumber(arbitrary)
{
}

Person::~Person()
{
}

string Person::GetName() const
{
	return firstname + " " + lastname;
}

bool Person::operator<(Person const& p) const
{
	return arbitrarynumber < p.arbitrarynumber;
}

bool Person::operator<(int i) const
{
	return arbitrarynumber < i;
}

/*Note that this function doesn't need Person::
Since Person is a const reference in this function, any member function accessed by p should be a const 
ex. p.getNumber() must be a const
RULE: a const object cannot call a non-const member function*/
bool operator<(int i, Person const& p) 
{
	return i < p.GetNumber();
}
