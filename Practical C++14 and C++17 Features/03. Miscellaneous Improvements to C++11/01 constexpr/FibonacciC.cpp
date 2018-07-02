// Demo code containing a **constexpr** Fibonacci function.
// This function is executed at **compile-time**.

#include <iostream>
using namespace std;

constexpr int Fibonacci(int n) {
	switch (n) {
		// F_0 = 0
		case 0: return 0;

		// F_1 = 1
		case 1: return 1;

		// F_n = F_(n-1) + F_(n-2)
		default:
			return Fibonacci(n-1) + Fibonacci(n-2);
	}
}

int main() {
	// Verify **compile-time** execution of Fibonacci()
	// using static_assert
	/* 
	assert is used for runtime check, whereas static_assert is done at compile
	time. We used static_assert here to verify that Fibonacci() function ran at 
	compile time
	*/
	static_assert(Fibonacci(10) == 55, "Unexpected Fibonacci number.");
}

