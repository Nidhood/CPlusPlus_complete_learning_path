//
// Created by nidhood on 14/01/24.
//

#include <iostream>
#include <fstream>
#include <limits> // -> numeric_limits

int main() {

    // We learned before about the files modes, now we are going to learn about the stream membered functions and state.
    std::ofstream bind_out_file_1{"../bind_example.txt", std::ios::out}; // This is the constructor of the ofstream class, which takes the path of the file that we want to write and the mode that we want to use.
    bind_out_file_1.close();

    // Also we can use a membered function to open a file, which is called open and it takes the path of the file that we want to write and the mode that we want to use.
    std::ofstream bind_out_file_2; // Here we have the object without no bind to a file.
    bind_out_file_2.open("../bind_example.txt", std::ios::out); // Here we are binding the object to a file.
    bind_out_file_2.close();

    // So in both cases:
    // -> The file mode will be applied to the file.
    // -> If the output file does not already exist, it will ve created.

    // Now we can use the is_open() membered function to check if the file is open or not.
    std::ofstream bind_out_file_3; // Here we have the object without no bind to a file.
    bind_out_file_3.open("../bind_example.txt", std::ios::out); // Here we are binding the object to a file.

    // Check if the file is open.
    if(bind_out_file_3.is_open()) {
        std::cout << "The file is open!" << std::endl;
    } else {
        std::cout << "The file is not open!" << std::endl;
    }
    bind_out_file_3.close();

    // Now we can learn about the state member functions, which are:
    int x{0};

    std::cout << "Please enter a number: ";
    std::cin >> x;

    if(std::cin.good()) // -> good(): Returns true if none of the error flags are set.
        std::cout << "You entered the number: " << x << std::endl;
    else if(std::cin.fail()) // -> fail(): Returns true if any of the error flags are set.
        std::cout << "Please try again and enter a valid number!" << std::endl;
    else if(std::cin.bad()) // -> bad(): Returns true if any of the error flags are set.
        std::cout << "Something terrible happened!" << std::endl;

    // We now have de eof() membered function, which returns true if the end of the file has been reached.
    std::ifstream bind_in_file; // Here we have the object without no bind to a file.
    bind_in_file.open("../text_in.txt", std::ios::in); // Here we are binding the object to a file.
    std::string word;

    // Check if the file is open.
    if(bind_in_file.is_open()) {
        std::cout << "The file is open!" << std::endl;
    } else {
        std::cout << "The file is not open!" << std::endl;
    }

    // Read the file until the end of the file, using the eof() membered function.
    while(!bind_in_file.eof()) {
        bind_in_file >> word;
        std::cout << word << " ";
    }
    std::cout << std::endl;

    // Now we are going to learn about de ignore() membered function, which is used to ignore a number of characters from the input stream.
    x = 0;

    std::cout << "Please enter a number: ";
    std::cin >> x;

    bool succes{false};
    while(!succes) {
        if(std::cin.good()) {
            std::cout << "You entered the number " << x << std::endl;
            succes = true;
        } else if (std::cin.fail()) {
            std::cout << "Please try again and enter a valid number: " << std::endl;
            std::cin.clear(); // -> clear(): Clears the error flags.

            //std::cin.ignore(20, '\n'); // -> ignore(): Ignores a number of characters from the input stream.
            // But how we to to ignore all the buffer of the input stream if we don't know how many characters we have to ignore?
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Here the numeric_limits<std::streamsize>::max() is the maximum number of characters that we can ignore, which means that we are ignoring all the buffer of the input stream.
            std::cin >> x;
        }
    }
    return 0;
}