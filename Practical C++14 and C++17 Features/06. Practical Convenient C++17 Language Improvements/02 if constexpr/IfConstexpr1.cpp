#include <iostream>     // For std::cout
#include <string>       // For std::string
#include <type_traits>  // For std::is_integral
using namespace std;

/*
'if' expression is checked at runtime, but, it's code must be compilable at
compiletime. For function template below we're handling a case in which a 
different set of actions take place if the type is 'int' else if the type in not
'int', other actions are taken. 
Note that this code doesn't compile. The reason being that the compiler
determines the type as 'int' for function call 'length(n)' below. So, it finds
that 'length()' is not a method for 'int' as called in line 'return value.length()'.
i.e. for each type, whole function must be consistent and compilable. But that
is not the case that fits our logic!
*/

template <typename T>
auto length(T const& value) {
  if (is_integral<T>::value) {
    // The length of an integer number is the number itself
    return value;
  } else {
    // Invoke the length method in the general case 
    return value.length();
  }
}

int main() {
  int n{64};
  string s{"Connie"};

  cout << " n = " << n << "; length(n) = " << length(n) << '\n';
  cout << " s = " << s << "; length(s) = " << length(s) << '\n'; 
}

