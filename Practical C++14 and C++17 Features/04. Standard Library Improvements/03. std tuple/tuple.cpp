#include <iostream>
#include <tuple>

/*
	tuple can be used as a container that holds elements of multiple types
*/

int main() {

	std::tuple<int,char> foo (10,'x');
	// using make_tuple to create a tuple
	auto bar = std::make_tuple ("test", 3.1, 14, 'y');

	// std::tuple supports 0 based indexes
	std::cout << "Element at pos 0 in bar: " << std::get<0>(bar) << std::endl;
	std::get<2>(bar) = 100;                                    // access element
	
	// std::tuple supports type based element access
	std::cout << "Element of type double in bar: " << std::get<double>(bar) 
	<< std::endl;
	/*
	Note that if there are more than one elements of same type in a tuple,
	the element access by that type will produce a compile-time error.
	*/

	int myint; 
	char mychar;
	
	// std::tie unpacks elements of a tuple into specified variables
	std::tie (myint, mychar) = foo;                            // unpack elements

	// std::ignore can be used to ignore specific elements while unpacking
	std::tie (std::ignore, std::ignore, myint, mychar) = bar;  // unpack (with ignore)

	mychar = std::get<3>(bar);
	
	// std::get supports access as well as assignment of elements
	std::get<0>(foo) = std::get<2>(bar);
	std::get<1>(foo) = mychar;

	std::cout << "foo contains: ";
	std::cout << std::get<0>(foo) << ' ';
	std::cout << std::get<1>(foo) << '\n';

	return 0;
}