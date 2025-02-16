//
// Created by nidhood on 14/01/24.
//

#include <iostream>
#include <iomanip> // For manipulators

int main() {

    // We need to remember that scientific notation is used to represent floating point numbers, which means that:
    // 1. In scientific notation, digits are displayed with the decimal point placed after the first significant digit (Known also as mantissa).
    // 2. It is followed by an "exponent" which gives the power of 10 by which the first number is multiplied, like:
    // -> 2.99792458e+008 represents 2.99792458 x 10^8 which is 299792458
    // -> 1.6e-19 represents 1.6 x 10^-19 which is 0.00000000000000000016
    // -> 3.14159265358979323846e+000 represents 3.14159265358979323846 x 10^0 which is 3.14159265358979323846
    double pi{3.14159265358979323846};
    std::cout << pi << std::endl; // 3.14159
    double c{299'792'458};
    std::cout << c << std::endl << std::endl; // 299792458

    // We can use the scientific notation to display the floating point numbers in a more readable way.
    // We can use the std::scientific manipulator to display the floating point numbers in scientific notation.
    std::cout << std::scientific << pi << std::endl; // 3.141593e+00

    // We can also display in uppercase scientific notation by using std::uppercase manipulator.
    std::cout << std::uppercase << pi << std::endl << std::endl; // 3.14159E+00

    // We can also display the floating point numbers in fixed notation by using std::fixed manipulator.
    std::cout << std::fixed << c << std::endl; // 3.141593
    double e{1.602e-19};
    std::cout << e << std::endl << std::endl << std::endl; // 160200000000000000000

    // We called "sticky" manipulators because they remain in effect until we change them, so to display the floating point numbers in default notation we need to use std::defaultfloat manipulator.
    std::cout << std::defaultfloat << e << std::endl; // 1.602e-19

    // We can also use the std::setprecision manipulator to set the number of digits to be displayed after the decimal point.
    std::cout << "Pi to 3 significant digits: " << std::setprecision(3) << pi << std::endl; // 3.14
    std::cout << "Pi to 6 significant digits: " << std::setprecision(6) << pi << std::endl; // 3.141592654// 3.141592654
    return 0;
}