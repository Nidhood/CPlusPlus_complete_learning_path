#include <iostream>
#include <memory>
#include <vector>
// What's a smart pointers?
// ---> Smart pointers are classes which encapsulate alocated memory:
// The class has a private data member which is pointer to the memory.
// The smart pointer object has ownership of the allocated memory.
// The allocated memory can only be accessed through public member functions.
// Pointer arithmetic is not allowed.
// Smart pointers save programmers a lot of work!


struct Point {
    int x;
    int y;
    public:
    Point ( int x, int y ) : x(x) , y(y) {};
};

void func( std::unique_ptr<Point> upp) {
    std::cout << upp->x << " , " << upp->y << std::endl;
};

std::unique_ptr<Point> point_ptr (int x, int y) {
    std::unique_ptr<Point> p{ new Point (x, y) };
    return p;
};

// Unique pointers and polymorphism:
// Remembering that polymorphism is when we use a base class object to represent a derived class object.

class Shape {
    public:
    virtual void draw() const = 0;  // Remembering this is a pure virtual function or otherwise called
                                    // "interface".
    virtual ~Shape() = default;
};

class Circle : public Shape {
    public:
    void draw() const override { std::cout << "Drawing a Circle..."; };
};

class Triangle : public Shape {
    public:
    void draw() const override { std::cout << "Drawing a Triangle..."; };
};

class Square : public Shape {
    public:
    void draw() const override { std::cout << "Drawing a Square..."; };
};

// Factory function:
std::unique_ptr<Shape> create_shape( int sides ) {
    if (sides == 1)
        return std::make_unique<Circle>();
    else if (sides == 3) 
        return std::make_unique<Triangle>();
    else if (sides == 4) 
        return std::make_unique<Square>();
    else
        return nullptr;
};

int main() {

    std::unique_ptr<int> p1 {new int(42)};

    std::unique_ptr<int[]> p2 {new int [6]};

    // auto p3{ std::make_unique<int> (42) };
    // auto p4{ std::make_unique<int[]> (6)};
    
    std::cout << *p1 << std::endl;
    std::cout << p2[0] << std::endl;

    std::unique_ptr<int> p5( std::move(p1) );
    std::cout << *p5 << std::endl;
    p1 = nullptr;

    std::unique_ptr<Point> p( new Point(3, 6) );

    std::cout << p->x << " , " << p->y << std::endl;
    func( std::move(p) );
    auto new_ptr = point_ptr(1 , 2);
    func( std::move(new_ptr) );

    std::vector< std::unique_ptr<Shape> > shapes;
    auto cast {create_shape(3)};
    cast->draw();
    return 0;
}