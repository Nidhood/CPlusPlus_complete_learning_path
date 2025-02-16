#include <iostream>

// It's important to know that the implementation of the interface in a concrete way that is specefic
// to each class (a circle object can draw a circle shape, rotate it, etc).

// To create a abstract class we use complete virtual functions:
// virtual void draw() = 0; // the '= 0' means that this function is a pure virtual function.
// This makes it clear that the vitual function is not part of the implementation.

// What's is an abstract base class?
// ---> All we know abstract base class is the same of other languages as "interface".
// It's important to know that if we derived of abstract class, all methods will must ve overrided.
// And is important to know that the derive class from base abstract class will also be an 
// abstract base class!


// But if the virtual function can not be implemented neither in his derived abastract classes how
// we can implemented its function?
// ---> Virtual function implementacion, thats means that the are implemented as global functions,
// when they are called, a pointer to the object is passed as an extra argument called "this".


class Shape {
    public:
    virtual void draw() const = 0;
};

class Circle : public Shape {
    public:
    void draw() const override { std::cout << "Drawing a Circle...\n"; };
};

void draw_shape ( const Shape& s ) {
    s.draw();
    (&s)->draw();
}

int main() {
    Circle circle;
    draw_shape(circle); 
    return 0;
}