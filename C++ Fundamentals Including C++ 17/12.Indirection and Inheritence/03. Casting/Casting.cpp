// Casting.cpp : Defines the entry point for the console application.
//

#include "Person.h"
#include "Tweeter.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include "Resource.h"

/* When we try to cast Derived to Parent, it works, but not the other way
	round.*/

int main()
{
	Tweeter t("Kate","Gregory",123,"@gregcons");
	Person* p = &t;

	/*Commented out line below will give compiler errors because Derived class
	pointer cannot point to a Base class object (information not enough).*/
	//Tweeter* pt = p;
	
	/*But, we're sure that p is Tweeter type, so we can use casting. Since we're
	very much sure (just previous lines help us to be sure that 'p' is in fact
	pointing to a Tweeter object), we can use static_cast (compile time casting)*/
	Tweeter* pt = static_cast<Tweeter*>(p);
	cout << pt->GetName() << endl;
	
	/* Lines below also produce compiler errors for obvious reasons. Trying to
	cast an unrelated type is bad.*/
	//int i = 3;
	//Tweeter* pi = static_cast<Tweeter*>(&i);


	Resource r("local");
	Tweeter* pt2;
	cout << "Use Resource or Tweeter?" << endl;
	std::string answer;
	std::cin >> answer;
	if (answer == "r")
	{
		/* if 'r' is entered, the line below tries to cast Resource type to
		pointer to Tweeter type. Since both are totally unrelated, and, we're
		using dynamic_cast, pt2 will be set to nullptr here. So, dynamic_cast
		tries to perform casting at runtime, and, if such things happen, it
		returns nullptr. Amazing!*/
		pt2 = dynamic_cast<Tweeter*>(&r);
	}
	else
	{
		/* if 'r' is not entered, the line below tries to dynamic_cast 'Pointer
		to Tweeter' to 'Pointer to Tweeter', which is fine. So pt2 now will have
		pointer to p (rather than a nullptr as above).*/
		pt2 = dynamic_cast<Tweeter*>(p);
	}

	/*So, as an example below, we can check for success of dynamic_cast.*/
	if (pt2)
	{
		cout << pt2->GetName() << endl;
	}
	else
	{
		cout << "pointer can't be cast to tweeter" << endl;
	}


	return 0;
}

