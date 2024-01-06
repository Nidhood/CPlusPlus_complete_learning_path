//
// Created by nidhood on 6/01/24.
//

#include <iostream>
#include <string>

// First we are going to learn about the find() function, which is used to find a substring in a string.
// Another useful function is std::string::npos, which is used to indicate that the string is not found.


int main() {

    // Always we firstly declare variables.
    std::string str{"I'm going to be the best roboticist in the world!"}; // This is the string.
    size_t pos; // This is the type of the return of the find() function.

    // Print the string.
    std::cout << "The phrase is: '" << str << "'" << std::endl << std::endl;

    // Now we are going to find the index of the first 'h' letter in the string.
    pos = str.find('h'); // The find() function returns the index of the first letter of the substring.

    // We now want to check if the letter is found.
    if(pos != std::string::npos) // If the letter is found, the function returns the index of the first letter of the substring.
        std::cout << "The index of the first 'h' letter is: " << pos << std::endl;
    else // If the letter is not found, the function returns the value of std::string::npos.
        std::cout << "The letter 'h' is not found in the string." << std::endl;

    // Now we are going to find the index of the first 'z' letter in the string.
    pos = str.find('z'); // The find() function returns the index of the first letter of the substring.

    if(pos != std::string::npos)
        std::cout << "The index of the first 'z' letter is: " << pos << std::endl;
    else
        std::cout << "The letter 'z' is not found in the string." << std::endl;

    // It is pretty useful to find the index of the first letter of a substring, but we need to ensure that the word is found in the string.
    pos = str.find('o');

    if(pos != std::string::npos) {
        str[pos] = 'p';
        std::cout << "The string is now: '" << str << "'" << std::endl;
    }
    else
        std::cout << "Could not find the search string\n";

    // Now with the rfind() function, we can find the index of the last letter of a substring.
    pos = str.rfind('o');

    if(pos != std::string::npos)
        std::cout << "The index of the last 'o' letter is: " << pos << std::endl;
    else
        std::cout << "The letter 'o' is not found in the string." << std::endl;

    // The find_first_of() function is used to find the index of the first letter of a substring, but it can be used to find the index of the first letter of a set of letters.
    std::string letters{"aeiou"}; // This is the set of letters.
    pos = str.find_first_of(letters); // The find_first_of() function returns the index of the first letter of the substring.

    if(pos != std::string::npos)
        std::cout << "The index of the first vowel is: " << pos << std::endl;
    else
        std::cout << "The vowel is not found in the string." << std::endl;

    // The find_last_of() function is used to find the index of the last letter of a substring, but it can be used to find the index of the last letter of a set of letters.
    pos = str.find_last_of(letters); // The find_last_of() function returns the index of the last letter of the substring.

    if(pos != std::string::npos)
        std::cout << "The index of the last vowel is: " << pos << std::endl;
    else
        std::cout << "The vowel is not found in the string." << std::endl;

    // The find_first_not_of() function is used to find the index of the first letter of a substring, but it can be used to find the index of the first letter of a set of letters.
    pos = str.find_first_not_of(letters); // The find_first_not_of() function returns the index of the first letter of the substring.

    if(pos != std::string::npos)
        std::cout << "The index of the first consonant is: " << pos << std::endl;
    else
        std::cout << "The consonant is not found in the string." << std::endl;

    // The find_last_not_of() function is used to find the index of the last letter of a substring, but it can be used to find the index of the last letter of a set of letters.
    pos = str.find_last_not_of(letters); // The find_last_not_of() function returns the index of the last letter of the substring.

    if(pos != std::string::npos)
        std::cout << "The index of the last consonant is: " << pos << std::endl;
    else
        std::cout << "The consonant is not found in the string." << std::endl;

    return 0;
}