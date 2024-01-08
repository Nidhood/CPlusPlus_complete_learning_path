//
// Created by nidhood on 6/01/24.
//


#include <iostream>
#include <string>

// First we are going to talk about the erase() function, which is used to erase a substring from a string.

int main() {

    std::string str{"I'm going to be the best roboticist in the world!"}; // This is the string.
    std::cout << "The initial string is: '" << str << "'" << std::endl;

    // Now we are going to erase the substring "best" from the string.
    str.erase(20, 5); // This is the substring, which is conformed by the index of the first letter of the substring, and the length of the substring.
    std::cout << "The string is now: '" << str << "'" << std::endl << std::endl;

    // Also we can erase a substring from a string using iterators.
    std::string str2{"I'm going to be the best roboticist in the world!"}; // This is the string.
    std::cout << "The initial string is: '" << str2 << "'" << std::endl;

    // Now we are going to erase the substring "best" from the string.
    auto first = begin(str2) + 20;
    auto last = first + 5;
    str2.erase(first, last); // This is the substring, which is conformed by the index of the first letter of the substring, and the length of the substring.
    std::cout << "The string is now: '" << str2 << "'" << std::endl << std::endl;

    // Now we are interested in the replace() function, which is used to replace a substring from a string.
    std::string str3{"I'm going to be the best roboticist in the world!"}; // This is the string.
    std::cout << "The initial string is: '" << str3 << "'" << std::endl;

    // Now we are going to replace the substring "world" from the string with the string "universe".
    str3.replace(43, 5, "universe"); // This is the substring, which is conformed by the index of the first letter of the substring, and the length of the substring.
    std::cout << "The string is now: '" << str3 << "'" << std::endl << std::endl;

    // Like we did with the erase() function, we can also replace a substring from a string using iterators.
    std::string str4{"I'm going to be the best roboticist in the world!"}; // This is the string.
    std::cout << "The initial string is: '" << str4 << "'" << std::endl;

    // Now we are going to replace the substring "world" from the string with the string "universe" using iterators.
    auto first2 = begin(str4) + 43;
    auto last2 = first2 + 5;
    str4.replace(first2, last2, "universe"); // This is the substring, which is conformed by the index of the first letter of the substring, and the length of the substring.
    std::cout << "The string is now: '" << str4 << "'" << std::endl << std::endl;

    // This time we are goint to use the assign() function, which means that we will remove the string and replace it with another string.
    std::string str5{"I'm going to be the best roboticist in the world!"}; // This is the string.
    std::cout << "The initial string is: '" << str5 << "'" << std::endl;

    // Now we are going to assign the string "I'm going to be the best roboticist in the universe!" to the string.
    str5.assign("I'm going to be the best roboticist in the universe!");
    std::cout << "The string is now: '" << str5 << "'" << std::endl;

    return 0;
}