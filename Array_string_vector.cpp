#include <iostream>

// C-Style String:
// A C-Style string is an array of const char, this is used to detect the end of the string.
const char *str = "Hello"; // each space in the char arry are conformed by => "[H][e][l][l][o][\0]"
// This is used to detect the end for the string.

// The string class:

/*
class std::string {
    char *data;
    size_t n;
}
*/


// It's important to know that string works like dynamic arry, but they are used like a local variable.
std::string hello{"Hello"}; // It's most efficient, and decrease the amount of leaks putting the pointers in the heap of the memory.

int main(){
    std::string str = "I'm going to be the best roboticist in the world!";
    std::cout << "The string is '" << str << "', it have the size of " << str.size() 
    << " words!" << std::endl;
    return 0;
}