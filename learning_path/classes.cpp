#include <iostream>

// Is imporant to know that by default access to members is "private".
// Another important thing it's that public members provide the interface of the class "What it does".
// and the second thing it's that private members the implementation of the class "How it does it".
// A struct is the same as a class, except all the members are public by default.
// Example:

class Test{
    int i; // By default as private.
    std::string str; // By default as private. 

    public:
    Test( int i, const std::string& str ) : i(i), str(str){
        this->i = i;
        this->str = str;
    };
    void myfuncvoid(); // Changed to public.
    int myfuncint(); // Changed to public.
    Test& operator =( const Test& other ) {
        i = other.i;
        str = other.str;
        return *this;
    }
    ~Test();
};

// Member function are implemented as global functions.
// When a member function is called on an object, the object is passed by address in hidden argument.
// Test::myfuncvoid();
// Dereferencing "this" gives acces to member of the object, the same as &test.

// Special member functions:
// ---> Construnctors. (construct the class)

/*
Test(int i, const std::string& str) : i(i), str(str){
        this->i = i;
        t
}
*/

// ---> Copy constructors. (similary to the constructor, but uses another object for initialization, 
//                          meaning that it always takes one argument)

/*
Test(const Test& other) : i(other.i), str(other.str){
        this->i = i;
        t
}
*/

// ---> Assignment operator. (assigns an existing object form another object, always takes 
//                            one argument and returns a reference to the assigned object).

/*
Test& operator =( const Test& other ) {
    i = other.i;
    str = other.str;
    return *this;
}
*/

// ---> Destructor. (Called before the class members are released in memory, 
//                  performs any tidying-up required before the object is destroyed).

int main(){
    std::string names[] = { "Fred", "Wilma", "Pebbles", "Dino", "Barney", "Betty", "Bamm-Bamm", "Hoppy"};
    std::cout << "names[1][2] = " << names[1*4 + 2] << std::endl;
    std::cout << "\nThe elements of names are:\n";
    for( int row = 0; row < 2; ++row ) {
        for( int col = 0; col < 4; ++col ) {
            std::cout << names[row*4 + col] << ", ";
        }
        std::cout << "\n";
    } 
    std::string url = R"x("file")x";
    std::cout << url;
    return 0;
}