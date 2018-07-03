#include <algorithm>  // For std::find()
#include <iostream>   // For std::cout
#include <string>     // For std::string
#include <vector>     // For std::vector
using namespace std;

// Print message followed by vector content
void print(const string& message, const vector<string>& v) {
  cout << ' ' << message << ": ";
  for (const auto& s : v) {
    cout << s << ' ';
  }  
  cout << '\n';
}

int main() {
	vector<string> names{"C64", "John", "Connie", "Mike", "Beth"};
	print("Before", names);

	/*
		Just like C++11 'for' loops, now in C++17, we can declare variables
		inside the 'if' and 'switch' conditions. These variables will be local 
		to the scope of 'if' and 'switch' in which they're defined. Note that a
		variable defined in an 'if' statement will also be accessible to the
		adjoining 'else' or 'else if'.
	*/

	// Connie ==> ***
	if (const auto it = find(begin(names), end(names), "Connie");
		it != end(names)) {
		*it = "***";
	}

	// C64 ==> **
	if (const auto it = find(begin(names), end(names), "C64");
		it != end(names)) {
		*it = "**";
	}

	print("After", names);
}


