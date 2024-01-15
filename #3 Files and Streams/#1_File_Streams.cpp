//
// Created by nidhood on 7/01/24.
//


// We already known that we use iostream to use the input and output streams, which are ostream (output stream or cout) and istream (input stream or cin).
#include <iostream>

// Now we are going to talk about the fstream library, which is used to work with files, so like we did with the iostream library, we are going to use the ifstream (input file stream or ifstream for reading) and ofstream (output file stream or ofstream for writing) classes.
// The important thing is in the computer are many files, so we need to specify the file that we want to read or write, so we need to use the path of the file, which is the location of the file in the computer.
#include <fstream>
#include <vector>

int main() {

    // First we want to open a file for reading, so we are going to use the ifstream class contructor.
    std::ifstream read_file{"../text_in.txt"}; // This is the path of the file that we want to read, that is actually in the same folder of the project.

    // Now we have a communication channel between the program and the file, so we can start to receive data from the file.
    if(read_file) {

        // The ifstream contructor returns a boolean value, which is true if the file was opened successfully, and false if the file was not opened successfully.
        std::cout << "The file was opened successfully!" << std::endl;

        // Now we want to see what is inside the file:
        std::string text;
        while(read_file >> text) {
            std::cout << text << ",";
        }
        std::cout << std::endl << std::endl;

        // Restart the pointer of the file to the beginning of the file:
        read_file.clear(); // This function is used to clear the flags of the file.
        read_file.seekg(0); // This function is used to move the pointer of the file to the beginning of the file.

        // The thing here is that maybe this way is no the best way to read a file, because we are reading the file word by word, so we are going to use the getline() function, which is used to read a file line by line.
        // The getline() function have two parameters, the first one is the file, and the second one is the string variable where we want to store the line of the file.
        while(getline(read_file, text)) // It is important to know that the getline() function let us to get the line of the file and store it in a string, so we need to use a string variable to store the line of the file.
        {
            std::cout << text << std::endl;
        }

        // Now we want to close the file, so we are going to use the close() function.
        read_file.close();
    }
    std::cout << std::endl;

    // Now we are going to open a file for writing, so we are going to use the ofstream class contructor.
    std::ofstream write_file{"../text_out.txt"}; // This is the path of the file that we want to write, that is actually in the same folder of the project.

    // Now we have a communication channel between the program and the file, so we can start to send data to the file.
    if(write_file) {
        std::cout << "Successfully opened the file!" << std::endl;

        // Now we want to write something in the file, so we are going to use the insertion operator (<<).
        std::vector<std::string> words = {"The", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog", "!"}; // This is the vector that we want to write in the file.
        for(const auto& word : words)
            write_file << word << " ";

        // Now we want to close the file, so we are going to use the close() function.
        write_file.close();
    }

    // Finally we need to know that fstream have a destructor, so when the program ends, the file is closed automatically. But it is a good practice to close the file manually like we did in the previous examples.
    return 0;
}