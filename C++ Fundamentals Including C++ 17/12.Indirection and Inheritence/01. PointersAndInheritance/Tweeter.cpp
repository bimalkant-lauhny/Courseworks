#include "Tweeter.h"
#include <iostream>
using std::cout;
using std::endl;

Tweeter::Tweeter(std::string first,
		std::string last,
		int arbitrary,
		std::string handle): Person(first,last,
		                            arbitrary),
							twitterhandle(handle)
{
		cout << "Constructing Tweeter for " << GetName() << endl;
}


Tweeter::~Tweeter()
{
	cout << "Destructing Tweeter for " << GetName() << endl;
}

std::string Tweeter::GetName() const
{
	return Person::GetName() + " " + twitterhandle;
}

