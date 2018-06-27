
#include "Person.h"

using namespace std;

Person::Person(string first,string last,
	int arbitrary) : firstname(first),lastname(last),
	arbitrarynumber(arbitrary), pResource(nullptr)
{
}

Person::~Person()
{
	delete pResource;
}

string Person::GetName() const
{
	return firstname + " " + lastname;
}


void Person::AddResource()
{
	delete pResource;
	pResource=new Resource("Resource for " + GetName());
}

Person::Person(Person const & p)
{
	pResource = new Resource(p.pResource->GetName());
}

Person& Person::operator=(const Person& p)
{
	/*
	Add the code to check if it is not self-assignment, ex. Kate = Kate. Because
	if self-assignment is not handled, function will first delete Kate's resource
	and then while assigning new resource, will ask Kate to fetch it's resource,
	which it just deleted! Havoc..	
	*/
	delete pResource;
	pResource = new Resource(p.pResource->GetName());
	return *this;
}

