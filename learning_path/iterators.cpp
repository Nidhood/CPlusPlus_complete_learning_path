#include <iostream>

// Always in the final value of the pointer is not the address of any element in the array, 
// that's why since use normal index make it's work hardder we use iterators.

std::string str{"Hello"};

std::string::iterator it = str.begin(); // Always select the first element of the array, in this case is 'H'.
int main() {
    while( it != str.end() ) {
        std::cout << *it << ", "; // We desreference the addres to get the value.
        ++it; // Here we're chossing to increase the address pointer.
    }
    std::cout << std::endl;
    return 0;
}