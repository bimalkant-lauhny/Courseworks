#include <iostream>
#include <memory>
using namespace std;
 
int main() {
  	auto p = make_unique<int>(64);
  	
	/*
	This time the code compiles. We have passed the unique_ptr p. But we could
	not write like -
	[p]() {}
	because that would be a pass by value which requires copying parameter, and,
	a unique_ptr cannot be copied.
	
	We could pass like -
	[&p]() {}
	which would be a pass by reference. Don't know why lecture did not show this!

	unique_ptr can be moved.
	we can see below that we are moving p to ptr. All of this is performed inside
	capture list. This type of assignment inside a list is called 
	'init-capture list'. A simpler example would be -
	[x, &y, v=64] () {}
	So, in example above, v is initialized with 64 inside capture list. v is now
	accessible inside lambda function with init value 64.
	*/
  	auto lambda = [ptr = move(p)](){ 
    	cout << " Inside the lambda -- value = " << *ptr << '\n'; 
  	};

  	lambda(); 
}

