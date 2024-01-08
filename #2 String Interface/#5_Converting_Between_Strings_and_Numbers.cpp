//
// Created by nidhood on 7/01/24.
//

#include <iostream>
#include <string>

int main() {

    // First we want to convert a number to a string, we can do this by using the to_string function
    std::string pi{std::to_string(3.14159)};
    std::string str{"The value of pi is "};

    // We can concatenate the two strings together using the + operator.
    str += pi;
    std::cout << str << std::endl << std::endl;

    // Now we want to convert a string to a integer, we can do this by using the stoi function
    std::string str2{"1234"};
    std::cout << "Initially, the type of the number is: " << typeid(str2).name() << std::endl;
    int num{std::stoi(str2)};
    std::cout << "Now type of the variable number is: " << typeid(num).name() << std::endl << std::endl;

    // It is importat to mention that the stoi function will throw an exception if the string is not a valid number and leading whitespace is ignored.
    std::string str3{"  314 159"};
    std::cout << "The number is: " << std::stoi(str3) << std::endl << std::endl;

    // We can also specify a second argument to the stoi function, which is a pointer to a size_t variable, which will be used to store the number of characters processed.
    size_t n_processed;
    auto i = std::stoi(str3, &n_processed);

    // Now we can check if the string is a valid number by comparing the size of the string with the number of characters processed.
    if(n_processed < str3.size())
        std::cout << "The string is not a valid number" << std::endl << std::endl;
    else
        std::cout << "The number is: " << i << std::endl << std::endl << std::endl;

    // Another useful thing about the stoi function is that it can be used to convert a string to a number with a different base, just by passing the base as a third argument.
    // It is important to mention that by default the base is 10.
    std::string str4{"101010"};
    std::cout << "The string is: " << str4 << std::endl;
    std::cout << "The number in base 2 is: " << std::stoi(str4, nullptr, 2) << std::endl << std::endl;

    std::string str6{"77"};
    std::cout << "The string is: " << str6 << std::endl;
    std::cout << "The number in base 8 is: " << std::stoi(str6, nullptr, 8) << std::endl << std::endl;

    std::string str5{"FF"};
    std::cout << "The string is: " << str5 << std::endl;
    std::cout << "The number in base 16 is: " << std::stoi(str5, nullptr, 16) << std::endl << std::endl;
    return 0;
}
