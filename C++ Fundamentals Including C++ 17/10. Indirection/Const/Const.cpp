// Const.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include "Person.h"

int DoubleIt(int const& x)
{
	return x*2;
}



int main()
{
	int i = 3;

	int const ci = 3;
	i = 4;
	//ci = 4; // cannot change const int

	int& ri = i;
	ri = 5;

	int const & cri = i;
	//cri = 6; // cannot change const reference
	i++; // can change nonconst i, hence value of cri also changed

	//int& ncri = ci;
	
	int j = 10;
	int DoubleJ = DoubleIt(j);
	/*Passing a literal 10 to a function which will receive it as reference
	is an error. Hence const is added to reference. See function DoubleIt above.
	If you change DoubleIt(int const &x) to DoubleIt(int &x), it will not compile.*/
	int DoubleTen = DoubleIt(10);

	Person Kate("Kate", "Gregory", 234);
	Kate.SetNumber(235);
	Person const cKate = Kate;
	//cKate.SetNumber(236); // cannot change members of a const object.
	int KateNumber = cKate.GetNumber(); // only call a const member function on a 
	// const object else you'll get a compiler error (Check Person::GetNumber())

	int* pI = &i;
	//int* pII = &pI; // cannot assign a 'pointer to a pointer to int' with a 'pointer to int'
	//pI = &Kate; // type safety
	
	int const * pcI = pI; // pointer to a const
	//*pcI = 4; // cannot change value
	pcI = &j; // can change address
	j = *pcI;

	int * const cpI = pI; // const pointer
	*cpI = 4; // can change value
	//cpI = &j; // cannot change address

	int const * const crazy = pI; // const pointer to a const
	//*crazy = 4; // cannot change value
	//crazy = &j; // cannot change address
	j = *crazy;

	return 0;
}

