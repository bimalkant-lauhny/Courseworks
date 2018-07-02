#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

/*
chrono lib mainly deals with time units.
*/

// note here that argument type is 'chrono::milliseconds'
void print(milliseconds ms) {
  	cout << ms.count() << "ms \n";
}

int main() {
	// 's' suffix can be used to denote that 2 is not of 'integer' but 'seconds' type
	// seconds x = 2; will not work!  seconds x{2}; will work.
	seconds x = 2s;
	cout << " x = 2s :    "; print(x);
	
	/*
	GENERAL TIP: consider the statement below:
	
	auto s = "Bimal";
	Here, auto will deduce type as (const char*)
	
	for statement below:

	auto s = "Bimal"s;
	now auto will deduce type as (std::string)
	*/

	/* 
	'ms' ms suffix fo 'milliseconds' type. Note how 'auto' deduces the type
	on its own
	*/
	auto y = 150ms;
	cout << " y = 150ms : "; print(y);

	auto z = x + y;
	cout << " z = x + y : "; print(z);

	constexpr auto timeLimit = 3s;
	/* 
	we're passing a 'chrono::seconds' as parameter to print which takes
	'chrono::milliseconds' as argument. Note that the program still compiles.
	This is because of amazing feature of chrono lib to automatically convert
	between time units.
	*/
	cout << "\n Time limit is "; print(timeLimit);
	
	/*Even for comparison operators, chrono lib handles the different units*/
	if (z < timeLimit) {
		cout << " All right! \n";
	} else {
		cout << " Out of time! \n";
  	}
	/*
	Also, the chrono lib performs all the conversions at compile-time, so, 
	there are no run-time overheads with using chrono lib.
	*/
}

