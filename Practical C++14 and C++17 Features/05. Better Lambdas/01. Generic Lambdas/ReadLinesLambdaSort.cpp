#include <algorithm>  // for std::sort
#include <fstream>    // for std::ifstream
#include <iostream>   // for std::cout
#include <string>     // for std::string, std::getline
#include <vector>     // for std::vector
using namespace std;

/*
Lambdas are inline functions that can be directly used to be passed into
functions like sort etc.
*/

int main() { 
	// Open file for reading
	ifstream file{"data.txt"};

	// Read each line from file to vector
	vector<string> lines{};
	string line{};
	while (getline(file, line)) {
		lines.push_back(line);
	}
	
	// Sort the read lines by length (shorter first), using a lambda
	/*
	Note that before C++14, we could not use 'auto' for lambda function
	parameters. These are called as 'generic lambdas'. So after lambdas were
	introduced in C++11, we had to write full types for parameters. 
	*/	
	sort(begin(lines), end(lines), 
  		[](auto const& a, auto const& b) {
			// sorting according to string length
			return a.length() < b.length();
	  	}
	);

	// Print the sorted lines
	for (auto const& s : lines) {
	cout << s << '\n';
}
}

