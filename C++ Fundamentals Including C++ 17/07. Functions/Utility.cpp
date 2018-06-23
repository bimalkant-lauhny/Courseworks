#include <iostream>
using std::cout;
using std::endl;

#include "Utility.h"

bool IsPrime(int x)
{
    bool prime = true;
    for (int i=2; i <= x/i; i = i + 1)
    {
        int factor = x/i;
        if (factor*i == x)
        {
            cout << "factor found: " << factor << endl;
            prime = false;
            break;
        }
    }
    return prime;
}

/* 
const reference is used to ensure that the function
doesn't mess up the value of the variable in calling 
function scope
*/
bool Is2MorePrime(int const& x)
{
    return IsPrime(x + 2);
}

/*
Returning a reference should generally be avoided
*/
//int& BadFunction()
//{
//	int a = 3;
//	return a;
//}

