#include <iostream>
#include <string>

// What's auto keyword?
// ---> "auto" was originally used in C to specify that a variable should be created on the stack, 
// otherwise in modern C++ it is used to indicate that the compiler should deduce the type from the
// variable's initial value.
auto i{42};             // Same int
auto str1 = "Hello";    // Same to const char str1[] = "Hello";
// auto str2 = "Hello"s;   // Same to std::string str2 {"Hello"s};


// It's important to know that auto will only give the underlying type, so const, reference, etc are ignored.
// const int& x{6};

int main() {
    return 0;
}