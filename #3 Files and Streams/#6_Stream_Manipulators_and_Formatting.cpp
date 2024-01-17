//
// Created by nidhood on 14/01/24.
//

#include <iostream>
#include <fstream>
#include <iomanip> // -> setw()

// We can push a "manipulator" into a stream to affect the stream's behabiour.
// We already learn about them, like std::flush and std::endl, which are used to flush the buffer and insert a new line respectively.
// The C++ library define a number of manipulators, which are used to format the output (most of these are in <iostream>).
int main() {

    int x = 2;
    bool id_negative = x < 0;

    std::cout << "The value of is_negative is: " << id_negative << std::endl; // -> This will print 1 if the value is true and 0 if the value is false.
    std::cout << "is_negative is " << std::boolalpha << id_negative << std::endl; // -> This will print true if the value is true and false if the value is false.
    std::cout << "x == 2 is "  << (x == 2) << std::endl; // -> This will print 1 if the value is true and 0 if the value is false.
    std::cout << "The numerical value of \"false\" is " << std::noboolalpha << false << std::endl << std::endl; // -> This will print 0 if the value is true and 0 if the value is false.

    // Now, we can use the setw() manipulator to set the width of the next output field (because by default there is no one).
    std::cout << std::setw(15) << "Penguins " << 5 << std::endl; // -> This will print "      Penguins5" (15 spaces before the word "Penguins" and no spaces before the number 5).
    std::cout << std::setw(15) << "Polar bears " << 7 << std::endl << std::endl; // -> This will print "   Polar bears7" (12 spaces before the word "Polar bears" and no spaces before the number 7).

    // The left manipulator can be used to left-justify the output.
    std::cout << std::left << std::setw(15) << "Penguins " << 5 << std::endl; // Here we are justifying the output to the left, which is the next output field (just if we restore the default manipulator settings it will be the same before we change it).
    std::cout << std::setw(15) << "Polar Bears " << 7 << std::endl << std::endl;

    // The sticky manipulator can be used to set the justification for all subsequent output.
    std::cout << std::setfill('#');
    std::cout << std::left << std::setw(15) << "Penguins" << 5 << std::endl;
    std::cout << std::setw(15) << "Polar Bears" << 7 << std::endl;
    std::cout << std::right;
    std::cout << std::setfill(' ');
    std::cout << std::setw(15) << "Hippopotamuses" << 11 << std::endl;

    return 0;
}
