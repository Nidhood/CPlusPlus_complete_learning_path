#include <iostream>
#include <string>
#include <vector>

// An important method is '.c_str()', which is the way to return a copu of the string's data as C-style
// string (that means that is returned an array of char termined by null character).
// Example:

std::string str{"Hello world!"};

const char *pChar = str.c_str(); // Is important to know that always it's return as a pointer to const
                                // char.


// What's substr() function does?
// ---> 'substr()' returns a substring, this substring starts at the index corresponding to its 
// argument.

auto s1 = str.substr(6); // Start since indexing position 6, so returns "world!".
auto s2 = str.substr(6, 2); // Here we're selecting a range of the substring, so in this case it
                            // returns "wo".
// Constructors:
std::string triple_x(3, 'x'); // The arguments indicates that three times the char 'x' will be assigned.
std::string hello1(str, 1); // Like a normal substring method, here we're passing a variable with the
                            // range of words of 'str', this case starts with 1 so the word is 
                            // "ello world!"
std::string hello2(str, 1, 3); // Knowing the range, like the above example, the substring will be
                               // "ell".

// How we can search strings?
// ---> The find() member function looks for the first occurrence of its argument in the string. 
// The search is case sensitive. 
// It's important to know that the argument to these member functions can be a char, a 
// std::string or a C-style string.
// It will returns the index of the dirst march.
// If there is no match, it returns string::npos.

void print(int *arr, size_t size) {
    for( int i = 0; i < size; i++) {
        std::cout << arr[i] << ", ";
    }
};

int main() {
    str.find('o'); // Returns the index of 4
    str.find("or"); // Returns the index of 7
    str.find('O'); // Because there is not match, its returns string::npos (can be use like a if 
                   // conditions).

    size_t pos = str.find('O');            

    // There exists another form thats it's finding the index of the word but in the otherwise, since 
    // the end, it is using rfind(). By default, the search starts form the end of the string. We can 
    // change this by passing a second argument.

    str.rfind('o', 5); // Returns the position of the word by the index 4.

    // What's assing() method do?
    // ---> 'assign() will remove all the characters rfom a string and replace them with other characters.
    str.assign("Goodbye");
    std::cout << str;         

    // How we convert numbers to strings of characters?
    // Using to_string() method!!!
    int val = 4;
    auto new_value{std::to_string(val)};

    // How we convert strings to numbers?
    // ---> We can use atoi, atof, atolol, atoll.

    // But how we secure the convertion only of number strings into a number (ignoring posible
    // characters inside the string) ?
    // ---> Inside the function to convert a string to number, there is another argument that
    // returns the number of number processed:

    std::string str2{"12s345"};
    size_t n_proccessed;
    auto i = std::stoi(str2, &n_proccessed);
    if(n_proccessed < str2.size()) std::cout << "\nThere is some words!" << std::endl;

    // We can do base convertion!!!
    // ---> An optional third argument gives the base!
    std::cout << std::stoi("2a", nullptr, 16) << std::endl; // Converts to hexadecimal number!
    
    // what's the data() method?
    
    std::vector<int> numbers{1, 2, 3, 4, 5};
    print(numbers.data(), numbers.size());
    std::cout << std::endl;
    return 0;
}