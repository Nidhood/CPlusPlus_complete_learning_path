//
// Created by nidhood on 7/01/24.
//

#include <iostream>
#include <string>

// Declare the function.
bool yes_or_no(const std::string& input);
bool equal_strings(const std::string &str1, const std::string &str2);

int main() {
    // First we are going to talk about de tolwer() function, which is used to convert uppercase letters to lowercase letters.
    std::string input;
    std::cout << "Do you want to enter a string which starts with y or y?" << std::endl;
    std::cin >> input;

    // Now we are going to convert the first letter of the string to lowercase.
    if(yes_or_no(input))
        std::cout << "Evidently you do!" << std::endl << std::endl;
    else
        std::cout << R"(I will take that as a "no")" << std::endl << std::endl;

    // Now we wan to use the toupper() function to conver a string to uppercase.
    std::string str{"Hello world!"};
    std::cout << "The initial string is: " << str << std::endl;

    // Now we are going to convert the string to uppercase each character at a time.
    for(auto& c : str)
        c = static_cast<char>(toupper(static_cast<unsigned char>(c))); // We need to cast the char to an unsigned char, because the toupper() function expects an unsigned char.

    std::cout << "The string is now: " << str << std::endl << std::endl;

    // Now we are going to talk about the tolower() function, which is used to convert uppercase letters to lowercase letters.
    std::string str2{"HeLlO WoRlD!"};
    std::cout << "The initial string is: " << str2 << std::endl;

    // Now we are going to convert the string to lowercase each character at a time.
    for(auto& c : str2)
        c = static_cast<char>(tolower(static_cast<unsigned char>(c))); // We need to cast the char to an unsigned char, because the toupper() function expects an unsigned char.
    std::cout << "The string is now: " << str2 << std::endl << std::endl;

    // We have the equal_string() function, which is used to compare two strings.
    std::string str3{"Hello World!"};
    std::string str4{"Hello World!"};
    std::string str5{"Hello Universe!"};
    std::string str6{"Hello works!"};

    // Now we are going to compare the strings str3 and str4.
    if (equal_strings(str3, str4))
        std::cout << "The strings are equal" << std::endl;
    else
        std::cout << "The strings are not equal" << std::endl;

    // Now we are going to compare the strings str3 and str5.
    if (equal_strings(str3, str5))
        std::cout << "The strings are equal" << std::endl;
    else
        std::cout << "The strings are not equal" << std::endl;

    // Now we are going to compare the strings str3 and str6.
    if (equal_strings(str3, str6))
        std::cout << "The strings are equal" << std::endl;
    else
        std::cout << "The strings are not equal" << std::endl;

    return 0;
}

// Declare the function.
bool yes_or_no(const std::string& input) {
    char c = input[0];

    if(toupper(c) == 'Y')
        return true;
    return false;
}

bool equal_strings(const std::string &str1, const std::string &str2) {

    // First we compare the lengths of he two strings.
    if(str1.size() != str2.size())
        return false;

    // Now we are going to compare the two strings.
    auto str1_it = begin(str1);
    auto str2_it = begin(str2);

    // We are going to iterate through the two strings and compare each character.
    while(str1_it != end(str1) && str2_it != end(str2)){
        if(*str1_it != *str2_it)
            return false;
        str1_it++;
        str2_it++;
    }

    // Evaluated all cases we have the certain that the two strings are equal.
    return true;


}
