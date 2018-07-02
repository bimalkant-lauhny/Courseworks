// Demo of the [[deprecated]] attribute

/*
If a programmer wants to discourage others from using some construct, s/he can
use [[deprecated]] attribute. So now, the others are able to use the deprecated
construct, but they will get compile time warnings for using them. Futhermore, 
C++14 also supports custom warning message.
*/

#include <iostream>
using namespace std;

// Deprecate this function
[[deprecated("DoSomething() is inefficient; use DoSomethingBetter() instead.")]]
void DoSomething() {
	cout << "I'm doing something the obsolete way.\n";
}

void DoSomethingBetter() {
	cout << "I'm doing something in a better way.\n";
}

int main() {
	// You should get a warning when compiling this code
	DoSomething();
}


