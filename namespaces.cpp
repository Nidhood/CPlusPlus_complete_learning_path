#include <iostream>

// What's a namespace?
// ---> 'namespace is used to group together logically related symbols (typically done within libraries).
// The C++ Standart Library defines the std namespace.
// This groups together the names of all the functions, types and variables defined by it.

// Why is the reason to use namespaces?
// ---> large programs often include several libraries, so we use addresses using namespaces.
// We need to know that namespaces can be split over different parts of the code, and even
// over different files.

// What's using means?
// ---> A "using" declaration will bring a particluar version of class Test into the global namespace.
// using xyz::Test; // Now "Test" will refer to xylum's class test.

// That's means that:

// Test         // Xylum's class Test.
// abc::Test    // Alpha's class Test.
// ::Test       // Global class Test.

int main(){
    return 0;
}