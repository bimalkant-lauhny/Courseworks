#include <iostream>
#include <memory>
using namespace std;

/*
Note that, [] in front of a lambda function is called a capture list. Capture list
is basically used to pass parameters from outside scope to inside lambda scope.
These can be passed by value or reference. Ex.
int x = 1, y = 2;
[x, &y](string const& a, string const& b) {
	// Note that x is passed by value and y is passed by reference
	// some code for a and b
}	
*/

int main() {
	auto p = make_unique<int>(64);

	/*
	Line below has compile error. It says that it cannot capture unique_ptr p.
	This happended because p is not passed in capture list.
	*/
	auto lambda = [](){ 
	cout << " Inside the lambda -- value = " << *p << '\n'; 
	};

	lambda(); 
}

