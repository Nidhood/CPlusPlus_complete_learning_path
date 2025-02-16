//
// Created by nidhood on 14/01/24.
//

#include <iostream>
#include <fstream>

int main() {

    // First we are going to talk about the flush() function, which is used to flush the output buffer.

    // Firstly we need to understand that C++ streams use "buffering" to minimize calls to the operating system,
    // so when we use the insertion operator (<<) to send data to the output stream, the data is not sent immediately
    // to the output stream, instead the data is stored in a buffer, and when the buffer is full, the data is sent to the output stream.
    // This is called "flushing".

    // Always using ostream, the buffer is flushed when:
    // 1. The program ends normally.
    // 2. The buffer is full.
    // 3. We use the endl manipulator.

    // Understanding this, std::flush allows us to control when the stream's buffer is flushed, that means that all the data in the buffer is immediately sent to its destination.
    std::cout << "Hello, World!" << std::flush; // This is the same as std::cout << "Hello, World!" << std::endl;

    // We need to be aware that flushing the buffer is an expensive operation, so we need to use it only when we need it. It should only be used if the data really needs to be up to date.
    //  -> e.g. log file to find out why a program crashed.
    return 0;
}
