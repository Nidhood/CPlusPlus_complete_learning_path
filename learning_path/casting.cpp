#include <iostream>

// What's a const_char?
// ---> 'const_char' is used to convert a const expression to the non-const equivalent.
void print( char *str ){
    std::cout << str << std::endl;
    return;
}

// What's a reinterpret_cast?
// ---> 'reinterpret_cast' is used to convert data in a buffer to untyped binary data (Manly used in low level work like communication with hardware, operating system, binary files).

// What's dynamic_cast?
// ---> 'dynamic_cast' is used to convert a pointer to a base class object to a pointer to a derived class object (also applies to references), and it's important o know that unlike the other types, it is done at runtime.


int main(){
    const char *msg = "Hello, world!";
    print(const_cast<char *>(msg));
    return 0;
}