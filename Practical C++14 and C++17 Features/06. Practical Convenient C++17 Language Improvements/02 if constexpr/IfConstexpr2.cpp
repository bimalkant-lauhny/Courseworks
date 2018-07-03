#include <iostream>     // For std::cout
#include <string>       // For std::string
#include <type_traits>  // For std::is_integral
using namespace std;

/* As a solution we've used C++17 feature 'if constexpr'. Such expression is
evaluated fully at compile-time. There are no runtime checks. Hence, when
compiler deduced the type as 'int' for function call 'length(n)', it simply
compiled the code for 'if' part in function template and discarded the 'else'
part. Similarly for 'length(s)' call, compiler deduced the type to be 'std::string'
and it only compiled the 'else' part of function template'.
Amazing! It perfectly fits our logic.
*/

template <typename T>
auto length(T const& value) {
  if constexpr(is_integral<T>::value) {
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

