#include <iostream>

int main(void) {
    double a1 = 2.2;
    // round bracket casts are unsafe and should not be used
    auto a2 = static_cast<int>(a1);
    std::cout << a2 << std::endl;
    return 0;
}