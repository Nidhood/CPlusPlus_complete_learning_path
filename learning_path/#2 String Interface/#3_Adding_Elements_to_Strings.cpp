//
// Created by nidhood on 6/01/24.
//

#include <iostream>
#include <string>

int main() {

    // First we are goint to learn the append() function, which is used to add a string to another string.
    std::string str{"I'm going to be the"}; // This is the string.
    std::cout << "The initial string is: '" << str << "'" << std::endl;

    // Now we are going to add the string "best roboticist in the world!" to the string.
    str.append(" best roboticist in the world!");
    std::cout << "The string is now: '" << str << "'" << std::endl;

    // The useful thing about the append() function is that it can be used to add a substring to a string.
    str.append("wow!!!!", 3, 2); // This is the substring, which is conformed by the string "wow!!!!", the index of the first letter of the substring, and the length of the substring.

    // The insert() function is used to insert a substring in a string.
    std::string str2{"for"};
    std::cout << "The initial string is: '" << str2 << "'" << std::endl;

    // Now we are going to insert the string "lde" in the string, in the index 2.
    str2.insert(2, "lde");
    std::cout << "The string is now: '" << str2 << "'" << std::endl;

    // We can also insert a substring in a string.
    std::string string{"xx"};
    std::cout << "The initial string is: '" << string << "'" << std::endl;
    std::string string2{"trombone"}; // We want to grab "bo" from this string2 and insert it in the string to form "xbox".

    // Now we are going to insert the string "bo" in the string, in the index 1.
    string.insert(1, string2, 4, 2); // This is the substring, which is conformed by the string "bo", the index of the first letter of the substring, and the length of the substring.
    std::cout << "The string is now: '" << string << "'" << std::endl;

    // We can actually also repeat a string a certain amount of times.
    std::string string3{"ha"};
    std::cout << "The initial string is: '" << string3 << "'" << std::endl;

    // Now we are going to repeat the string 5 times.
    string3.insert(2, 5, 'h'); // This is the substring, which is conformed by the string "bo", the index of the first letter of the substring, and the length of the substring.
    std::cout << "The string is now: '" << string3 << "'" << std::endl << std::endl;

    // Also the insert() function can use iterators.
    std::string string4{"word"};
    std::cout << "The initial string is: '" << string4 << "'" << std::endl;

    // Now we are going to insert the string "inserted" in the string, in the index 1.
    auto last = end(string4) - 1;
    string4.insert(last, 'l');
    std::cout << "The string is now: '" << string4 << "'" << std::endl;

    // We need to be careful with the iterators, becouse we can get iterator invalidation.
    std::string string5{"orld"};
    std::cout << "The initial string is: '" << string5 << "'" << std::endl;

    // Now we are going to insert the string "inserted" in the string, in the index 1.
    auto first = begin(string5);
    string5.insert(end(string5), 16, 'd');

    // Now for not getting iterator invalidation, we need to update the iterator.
    first = begin(string5);
    string5.insert(first, 'w');
    std::cout << "The string is now: '" << string5 << "'" << std::endl;

    return 0;
}