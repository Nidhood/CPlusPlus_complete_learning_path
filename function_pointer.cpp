#include <iostream>

// What's function pointer?
// ---> A function's exectable code is stored in memory, we can get a pointer whose address is the 
// start of this code.

// void(* func_ptr)( int, int ) = &func;
// func_ptr is a pointer to the function.
// We can use a type alias for a function pointer's type:
// using pfunc = void(*)(int, int);

// When we use function pointers?
// Useful for writing callbacks, "Raw" pointers (overwritten, null or uninitialized).

void func(int x, int y) {
    std::cout << x << " + " << y << " = " << x + y << std::endl; 
}

// We can use type alias for a function pointer's type (its like type of function to work as 
//                                                      argument inside function).
using pfunc = void(*)(int, int); 

void some_func(int x, int y, pfunc func_ptr) {
    (*func_ptr)(x, y);
}

pfunc other_func() {
    return func;
}

int main(){

    // Like a normal function we can call the function by dereferencing like a normal pointer value.
    // (*func_ptr)(1, 2);

    // It's important to know that function pointer is a "first class object", that means that we
    // can pass a function pointer as argument to another function, and also we can return pointer
    // from a call to another function.

    // Example #1:
    auto func_ptr = &func;
    (*func_ptr)(1, 2); // Dereference the pointer function.

    // Example #2:
    auto func_ptr2 = other_func();
    some_func(1, 2, func_ptr2);
    return 0;
}
