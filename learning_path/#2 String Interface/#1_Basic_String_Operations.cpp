//
// Created by nidhood on 6/01/24.
//

#include <iostream>
#include <string>

int main() {

    // First we are going to define the basic Operations.
    std::string str1{"One"}, str2{"Two"}; // This is the string.
    std::cout << "The initial strings are: '" << str1 << "' and '" << str2 << "'" << std::endl;

    // Assigment.
    str1 = str2;
    std::cout << "The strings are now: '" << str1 << "' and '" << str2 << "'" << std::endl;

    // Appending.
    str2 += " and Three";
    std::cout << "The string is now: '" << str1 << "'" << std::endl;

    // Concatenation.
    std::string str3{str1 + " " + str2};
    std::cout << "The string is now: '" << str3 << "'" << std::endl;

    // Comparison.
    if(str1 == str2)
        std::cout << "The strings are equal" << std::endl;
    else
        std::cout << "The strings are not equal" << std::endl;

    if(str1 < str2)
        std::cout << "The string '" << str1 << "' is less than the string '" << str2 << "'" << std::endl << std::endl;
    else
        std::cout << "The string '" << str1 << "' is not less than the string '" << str2 << "'" << std::endl << std::endl;

    // Now we are goint to talk about the C-Style String Operations, std::string has a member function called
    // c_str() which returns a pointer to a null-terminated array of characters.
    std::string str4{"Hello World!"};
    std::cout << "The string is: " << str4 << std::endl;

    // Now we are going to get a pointer to the first character of the string.
    const char *pChar{str4.c_str()};
    std::cout << "The pointer to the first character of the string is: " << pChar << std::endl << std::endl;

    // Now there is the substr() function, which is used to get a substring from a string.
    std::string str5{"Hello Fellow Roboticists!"};
    std::cout << "The string is: " << str5 << std::endl;

    // Now we are going to get a substring from the string.
    std::string str6{str5.substr(6, 5)}; // This is the substring, which is conformed by the index of the first letter of the substring, and the length of the substring.
    std::cout << "The substring is: " << str6 << std::endl << std::endl;

    // Now we are going to see the diferents ways to construct a string.
    // Default constructor.
    std::string str7; // This is the string.

    // Contruct with a string literal, which means that this parcticular string is a constant.
    std::string str8{"Hello World!"}; // This is the string.

    // Contructor withc a count and an initial value.
    std::string str9{4, 'a'}; // This is the string.
    std::cout << "The string is: " << str9 << std::endl;

    // Contructor with an initialiser list.
    std::string str10{'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '!'}; // This is the string.
    std::cout << "The string is: " << str10 << std::endl;

    // Contructor with a intialized substring.
    std::string str11{str10, 6, 5}; // This is the string.
    std::cout << "The string is: " << str11 << std::endl;
    return 0;

}
