#pragma once
#include <string>

#include "Resource.h"
#include <memory>

class Person
{
private:
	std::string firstname;
	std::string lastname;
	int arbitrarynumber;
	/*
	shared_ptr is a pointer type that allows shallow copy of pointer. It uses
	reference count to mark the number of current pointers pointing to it. As
	the pointers go out of scope, it decreases the ref count. When ref count
	becomes 0, the pointer is actually deleted and memory is freed. So, now we
	do not need to perform manual deep copy of objects using copy ctor and
	copy assigment operator.
	*/
	std::shared_ptr<Resource> pResource;

public:
	Person(std::string first,
		std::string last,
		int arbitrary);
	/* Notice that now we don't need a manual destructor, since we're using
	shared_ptr */
	std::string GetName() const;
	int GetNumber() const {return arbitrarynumber;}
	void SetNumber(int number) {arbitrarynumber = number;}
	void SetFirstName(std::string first) {firstname = first;}
	void AddResource();
	std::string GetResourceName() const {
		/*
			It is imp to check whether pResource is not a nullptr before
			accessing it's members.
		*/ 
		return pResource ? pResource->GetName() : ""; 
	}
};
