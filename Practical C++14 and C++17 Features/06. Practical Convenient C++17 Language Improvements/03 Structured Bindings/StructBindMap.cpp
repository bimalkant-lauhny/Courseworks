#include <iostream> // for std::cout
#include <map>      // for std::map
#include <string>   // for std::string
using namespace std;

/* Structure Bindings are a convenient C++17 feature that allows programmers
to declare and initialize multiple variable at same time. (it is just like 
tuple declaration and initialization in Python! remember? Ex.
x, y = pair
where pair = (1, 2), then, x= 1 & y = 2.
*/

int main() {
	map<string, string> italianDictionary{
		{"casa",   "home"},
		{"gatto",  "cat"},
		{"tavolo", "table"}

		// ...
	};
	
	/*
	'insert()' call to a 'map' returns a 'std::pair'. The 'pair.first' is an 
	'iterator' and 'pair.second' is a 'boolean'. If the key-val pair already
	exists in the map, the iterator points to the existing pair and boolean 
	is 'false'. If the key-val pair does not exist then iterator points to
	newly inserted key-val pair and boolean value is 'true'.
	*/
	
	/*
	Note in line below, the pair.first element got assigned to variable 'pos'
	and pair.second element got assigned to 'success' variable.
	*/	
	auto [pos, success] = italianDictionary.insert({"sedia", "chair"});
		if (success) {
			cout << " Insertion OK.\n\n";
	}

	/*Similar scenario here. The key got assigned to 'italian' and val got
	assigned to 'english'*/
	for (const auto& [italian, english] : italianDictionary) {
		cout << ' ' << italian << ": " << english << '\n';
	}
}

