#include <iostream>
#include <fstream>
#include <vector>
#include <string>

// What's important about files?
// ---> It's important to know that files doesn't distinwish between file formats.

// What's operation can be done with fstream opeartions?
// Open file, Write file, Read file and Close file.


// There is another important concept about he files, as data passes between 
// the program and the file, it may be temporaly stored in a memory buffer, which 
// makes large data transfers more efficient, but less timely.

// What's the types of file streams?
// ---> iostream. (ostream : cout) (istream : cin).
// ---> fstream. (ofstream : file stream for writing) (ifstream : file stream for reading).

// Whats's the communication channel?
// the communication chanenel it's the way how can the program can reseive data from the file.
// It is important to know the stream's state before using it



// For reading from a file, it's more efficent to read all the line, we use getline().


int main() {
    
    // Example of stream for reading a file constructor:
    std::string str{"text_in.txt"};
    std::ifstream read_file(str);

    if (read_file) {
        std::string text{""};
        while (getline(read_file, text)) {
            std::cout << text << std::endl;
        }
        read_file.close();
    }

    // Example of stream for writing a file constructor:
    std::ofstream write_file{"out_file.txt"};

    if (write_file) {
        std::vector< std::string > words = {"The", "fucking", "duck", "is", "shitting","in", "my", "room!"};
        for (auto word : words)
            write_file << word << " ";
        write_file.close();
    };

    // When fstream's dstructor is called, the file is automatically closed this will
    // cause any unsaved data to be written to the file, if an fstream object goes oute
    //  of scope after we have finished with it, we do not need to explicitly call close().

    // What's the concept of buffer inside stream?
    // ---> C++ stream use "buffering" to minimize calls to the operating system during write
    // operations, data is temporarily held in a memory buffer the size of this buffer is chosen
    // to match the maximum amount of data that the operating system will accept.  When the buffer
    // is full the stream will remove the data from the vuffer and send it to the operating system,
    //  this is know as "flushing" the output buffer. 

    // When the stream buffer flushed?
    // ---> usually this is at the end of every line, coyt is always flushed  buffer is full,
    // there is no direct way to flush input streams.

    // How we use std::flush?
    // ---> 'sts::flush' allows us to control when the stream's buffer is flushed, all the data
    // in the buffer is immediately sent to its deestination.
    // cout << i << flush; // It will appear immediately on the screen! same is the function of endl.
    // this tool shoul only be used if the data really needs to be up date.

    // What's unbuffered input and output?
    // ---> Streams have a member function for reading or writing data, one character at time.
    // 'get()' fetches the next character from an input stream.
    // 'put()' sends its argument to an output stream.
    
    char c;
    while(std::cin.get(c)) // Read a character until we get end-of-input
        std::cout.put(c); // Display the character.

    // ---> For reading and writing many characters, exist:
    // write() : our buffer will constain all the data we want to send.
    // read() : the buffer must be large enough to store all the data we expect to recieve.

    const int filesize{10}; // The size of the memory buffer.
    char filebuf[filesize]; // The memory buffer.
    // ifile.read(filebuf, filesize); // Fetch data from the file into the memory buffer.
    // cout.write(filebuf, filesize); // Send the data from the memory buffer to output.

    // How I can see the bytes thas has been seended or received?
    // ---> The gcount() member function will return the number of characters that were actually received.
    // auto nread = ifile.gcount(); // How many bytes did we recieve?
    return 0;
}