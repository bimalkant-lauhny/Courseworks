
#include "Person.h"

using namespace std;

Person::Person(string first,string last,
	int arbitrary) : firstname(first),lastname(last),
	arbitrarynumber(arbitrary)
{
}



string Person::GetName() const
{
	return firstname + " " + lastname;
}


void Person::AddResource()
{
	// instead of manual deletion, shared_ptr provides reset() method
	pResource.reset();
	// make_shared calls new for you, but it is a memory efficient implementation
	pResource=std::make_shared<Resource>("Resource for " + GetName());
}
