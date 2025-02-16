#include <iostream>
#include <vector>

// Brace intitialations:
int x{7};
std::string s{"Let us begin"};

// Also can be used int containers:
std::vector<int> vec{4,2,3,5,1};

// Conversions that not allowed:
// int x = 7.7;
// int x{7.7};

// Consistent declarations:
// std::vector<int> old_one(4); // Elements = 0, 0, 0, 0
// std::vector<int> old_one(4, 2); // Elements = 2, 2, 2, 2
// std::vector<int> uni{1}; // Elements = 1
// std::vector<int> uni{1, 4}; // Elements = 1, 4

// Avoids ambiguity:
// Class myClass(); ---> Object creation or function declaration?
// Class myClass{}; ---> Object creation!

// Same to typedef vector<int> intVect;
// using IntVec = vector<int>;

using IntVec = std::vector<int>;

// Null and nullptr:
// ---> nullptr is literal representing a null pointer, it's compatible with any pointer type, but
// cannot be converted to an integer.

// ---> The traditional NULL has the value of 0.

// Example:

void func( int i ) {
    std::cout << "func( int ) called!\n";
};

void func( int *i ) {
    std::cout << "func( int * ) called!\n";
};

int main(){
    func(nullptr);
    return 0;
}