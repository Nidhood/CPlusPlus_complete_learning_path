//
// Created by nidhood on 14/01/24.
//

#include <iostream>
#include <fstream>

int main() {

    // We were using buffering for all the streams, but there are some applications where stream vuffering is not suitable.
    // e.g. a network application:
    // -> Data must be transmitted in "packets" of a specified size.
    // -> Data may need to be transmitted at specific times.


    // Fortunately, C++ allows us to disable buffering for a stream, so we can use the unbuffered input and output. These are mainl used when the programmer needs more control over how the data is transmitted:
    // -> Networking applications.
    // -> Communicating directly with hardware.

    // So we have Input and Output of a single Character at a time:
    // -> get() fetches the next character from an input stream.
    // -> put() writes a character to an output stream.

    // These both take a char argument:
    std::cout << "Enter some text: ";
    char c;

    while(std::cin.get(c) && c != '\n') // This will read a character until we get end-of-input.
    {
        std::cout.put(c);  // Display the character.
    }
    std::cout << std::endl << std::endl;

    // Now for reading and writing many characters, there are the read() and write() member functions.
    // As we are not using a buffer managed by the stream, we have to provide out own buffer:
    // -> For write(), our buffer will contain all the data we want to send.
    // -> For read(), the buffer must be large enough to store all the data we expect to receive.

    const int filesize{10}; // The size of the memory buffer (10 bytes).
    char buffer[filesize];  // The memory buffer.

    std::ifstream in_file{"../buffer_example.txt"}; // This is the path of the file that we want to read, that is actually in the same folder of the project.

    if(!in_file) {
        std::cerr << "Error opening file!" << std::endl;
        return -1;
    }

    in_file.read(buffer, filesize); // Fetch data from the file into the memmory

    // Also we often will interested to know how much data an input stream has sent to us:
    // -> We may nned to allocate memory to process the data.
    // -> To detect partial or incomplete transfers.

    // Here is when gcount() comes in handy, which is a function that will return the numer of characters that were actually recieved.
    auto bytes_recived = in_file.gcount();

    in_file.close();                // Close the file.

    std::cout << "Read " << bytes_recived << " bytes." << std::endl;
    std::cout << "File data: ";
    std::cout.write(buffer, filesize); // Write the data to the standard output.
    std::cout << std::endl;

    return 0;
}
