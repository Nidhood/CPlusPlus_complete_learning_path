//
// Created by nidhood on 14/01/24.
//

#include <iostream>
#include <fstream>

// It's important to know that C++ figes us a number of options for opening a file. These are called "modes".
// By default, file are opened in "text mode", which means that you can read and write the file as a stream of characters.// BY default, output files are opened in "truncate mode", which means that if the file already exists, its contents are deleted and the file is treated as a new empty file.
int main() {

    // Firstly we are going to learn about the appending mode, which is used to append data to the end of a file.
    std::cout << "Opening file..." << std::endl;
    std::ofstream out_file{"../appending_example.txt", std::ios::app}; // This is the path of the file that we want to write, that is actually in the same folder of the project.

    // Ensure that the file was opened successfully.
    if(!out_file) {
        std::cerr << "Error opening file!" << std::endl;
        return -1;
    }
    std::cout << "Successfully opened the file!" << std::endl;

    // Now we want to write something in the file, so we are going to use the insertion operator (<<) and remmeber that we are using the appending mode, so we are going to append the data to the end of the file.
    out_file << "This is a new line!" << std::endl;
    out_file.close();

    // Now we are going to learn another mode, which is truncating mode and it's used to delete the contents of the file if it already exists.
    std::cout << "Opening file in truncating mode..." << std::endl;
    std::ofstream out_file_truncating{"../truncating_example.txt", std::ios::trunc}; // This is the path of the file that we want to write, that is actually in the same folder of the project.

    // Ensure that the file was opened successfully.
    if(!out_file_truncating) {
        std::cerr << "Error opening file!" << std::endl;
        return -1;
    }

    // Now we want to write something in the file, so we are going to use the insertion operator (<<) and remmeber that we are using the appending mode, so we are going to append the data to the end of the file.
    out_file_truncating << "This is always be the first line!" << std::endl;
    out_file_truncating.close();

    // Now we are going to learn another mode, which is in mode and let's us read data from a file.
    std::cout << "Opening file in in mode..." << std::endl;
    std::ifstream out_file_in{"../in_example.txt", std::ios::in}; // This is the path of the file that we want to write, that is actually in the same folder of the project.

    // Ensure that the file was opened successfully.
    if(!out_file_in) {
        std::cerr << "Error opening file!" << std::endl;
        return -1;
    }

    // Now we want to read something in the file, so we are going to use the extraction operator (>>) and remmeber that we are using the appending mode, so we are going to append the data to the end of the file.
    std::string line;
    while(out_file_in >> line) {
        std::cout << line << " ";
    }
    out_file_in.close();

    // Now we are going to learn another mode, which is out mode and let's us write data to a file.
    std::cout << "Opening file in out mode..." << std::endl;
    std::ofstream out_file_out{"../out_example.txt", std::ios::out}; // This is the path of the file that we want to write, that is actually in the same folder of the project.

    // Ensure that the file was opened successfully.
    if(!out_file_out) {
        std::cerr << "Error opening file!" << std::endl;
        return -1;
    }

    // Now we want to write something in the file, so we are going to use the insertion operator (<<) and remmeber that we are using the appending mode, so we are going to append the data to the end of the file.
    out_file_out << "This is always a the first line!" << std::endl; // It always will be in truncating mode.
    out_file_out.close();

    // Now we are going to learn another mode, which is ate mode and let's us move the pointer of the file to the end of the file.
    std::cout << "Opening file in ate mode..." << std::endl;
    std::ofstream out_file_ate{"../ate_example.txt", std::ios::ate}; // This is the path of the file that we want to write, that is actually in the same folder of the project.

    // Ensure that the file was opened successfully.
    if(!out_file_ate) {
        std::cerr << "Error opening file!" << std::endl;
        return -1;
    }

    // As we are using the ate mode, the pointer of the file is at the end of the file, so we put the pointer at the end of the file.
    out_file_ate.seekp(0, std::ios::end);

    // Now we want to write something in the file, so we are going to use the insertion operator (<<) and remmeber that we are using the appending mode, so we are going to append the data to the end of the file.
    out_file_ate << "This is always a the first line!" << std::endl; // It always will be in truncating mode.
    out_file_ate.close();

    // Now we are going to learn another mode, which is binary mode and it's used to read and write data in binary format.
    std::cout << "Opening file in binary mode..." << std::endl;
    std::ofstream out_file_binary{"../binary_example.txt", std::ios::binary}; // This is the path of the file that we want to write, that is actually in the same folder of the project.

    // Ensure that the file was opened successfully.
    if(!out_file_binary) {
        std::cerr << "Error opening file!" << std::endl;
        return -1;
    }

    // Now we want to write something in the file, so we are going to use the insertion operator (<<) and remmeber that we are using the appending mode, so we are going to append the data to the end of the file.
    out_file_binary << "This is a new line!" << std::endl;
    out_file_binary.close();

    // Also we can combine methods like this:
    std::cout << "Opening file in out and app mode..." << std::endl;
    std::ofstream out_file_out_binary_app{"../combining_methods_example.txt", std::ios::out | std::ios::app}; // This is the path of the file that we want to write, that is actually in the same folder of the project.

    // Ensure that the file was opened successfully.
    if(!out_file_out_binary_app) {
        std::cerr << "Error opening file!" << std::endl;
        return -1;
    }

    // Now we want to write something in the file, so we are going to use the insertion operator (<<) and remmeber that we are using the appending mode, so we are going to append the data to the end of the file.
    out_file_out_binary_app << "This is a new line!" << std::endl;
    out_file_out_binary_app.close();

    // Concluding all that we learned, we need to know few restrictions:

    // -> out: Can be used only by fstream and ofstream objects.
    // -> in: Can be used only by fstream and ifstream objects.
    // -> trunc: Only used with out mode.
    // -> ate: Cannot combine with trunc, and the file always be opened in output mode.

    return 0;
}
