//
// Created by nidhood on 7/01/24.
//

#include <iostream>
#include <string>
#include <vector>

// Declare the function.
void print(int *arr, size_t size); // There is two arguments, the first one is a pointer to the first element of the array, and the second one is the size of the array.

// Principal function.
int main() {

    // First we are going to talk about the data() function, which is used to get a pointer to the first character of the string.
    std::string str{"Hello World!"};
    std::cout << "The string is: " << str << std::endl;

    // Now we are going to get a pointer to the first character of the string.
    std::cout << "The pointer to the first character of the string is: " << str.data() << std::endl << std::endl;

    // Now we are going to talk about the c_str() function, which is used to get a pointer to the first character of the string.
    std::vector<int> vec{1, 2, 3, 4, 5};
    std::cout << "The vector is: ";
    print(vec.data(), vec.size());
    std::cout << std::endl << std::endl;

    // Now we are going to talk about the swap() function, which is used to swap the contents of two strings.
    std::string str2{"Hello World!"};
    std::string str3{"Hello Universe!"};
    std::cout << "The initial strings are: " << str2 << " and " << str3 << std::endl;

    // Now we are going to swap the contents of the two strings.
    std::swap(str2, str3);
    std::cout << "The strings are now: " << str2 << " and " << str3 << std::endl << std::endl;

    // Also we can swap as a member function.
    std::string str4{"The dog is brown"};
    std::string str5{"The cat is black"};
    std::cout << "The initial strings are: " << str4 << " and " << str5 << std::endl;

    // Now we are going to swap the contents of the two strings.
    str4.swap(str5);
    std::cout << "The strings are now: " << str4 << " and " << str5 << std::endl << std::endl;

    return 0;
}

// First we are going to talk about the data() function, which is used to get a pointer to the first character of the string.
void print(int *arr, size_t size){

    // Like we said, the first argument is a pointer to the first element of the array, and the second one is the size of the array.
    // Which means that we can use the pointer to iterate through the array.
    for(int i = 0; i < size; i++)
        if(size - i == 1)
            std::cout << arr[i];
        else
            std::cout << arr[i] << ", ";
}
