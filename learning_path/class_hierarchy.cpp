#include <iostream>

// Base class is the father of all derived classes.
// Example of base class and derived classes:

// This is the base class.
class Vehicle {
    int max_speed;
    public:
    Vehicle(int max_speed) : max_speed(max_speed) {};
    void start() {
        std::cout << "The engine is starting!";
    };
    virtual void draw() const { std::cout << "I'm drawing a fucking vehicle"; };
    virtual ~Vehicle() { std::cout << "Goodbye from Vehicle object!\n"; };
    protected:
    void accelerate() {
        std::cout << "Increasing speed: ";
    };
};

// this is the derived class, and after ':' is the base class.
class Aeroplane : public Vehicle {
    int max_height;
    public:
    Aeroplane(int max_speed, int max_height) : Vehicle(max_speed), max_height(max_height) {}; // Initialize the Vehicle part of the object.
    void start() {
        std::cout << "Carrying out checks...";
        Vehicle::start(); // The child class can also extend the parent's member functions!
        std::cout << "Ready for take-off!";
    };
    void draw() const override { std::cout << "I'm drawing plane. ¡¿wtf?!"; };
    using Vehicle::accelerate;
    void accelerate(int height) {
        std::cout << "Accelerating a height of: " << height;
    };
    ~Aeroplane(){ std::cout << "Goodbye from Aereoplane object!\n"; };
};

void draw_shape(const Vehicle& v) {
    v.draw();
    return;
};

// It's very important to understand that all child class "inherits" all the non-private
// member functions of its parent class.

// A child class can re-implement the parent class's memeber functions, to make them more
// appropiate for the child.

// It's important to know that parent class can make its member avaible to its children, but not
// to other code, this maintains the encapsulation. (we do this using protected acces)

// If we overload an inherited function in the child class, it will "hide" all the other inherited
// function with that name (those functions cannot be called on the child class);

// This is inconsisted with OO desing principles.

// Another important keyword is 'final' that indicates the last child of a base class, since then 
// Other childs of this final class won't be able o inherits their methods or their attributes.
// Class sub_class final : base_class { ... } 

// Also we can use final in functions, this indicates that all childs of this class can inherite this
// function, but them will not be able to override it.
// void draw() const override final; 

// How I do a derived class destruction?
// ---> Its important to delete point class objects, but in case that any function is virtual inherited,
// the destuctor needs to delete since the root of all virtual function. So we use:
// virtual ~Shape(){}; // Empty virtual destructor.
// virtual ~Shape = default; // Default virtual destructor.

int main() {
    std::cout << "Creating vehicle object!\n";
    Vehicle vehicle(10);
    std::cout << "Creating aeroplane object!\n";
    Aeroplane plane(40000, 500);
    plane.accelerate();
    std::cout << std::endl;
    plane.accelerate(1000);
    std::cout << std::endl;
    Vehicle* some_vehicle = &plane;
    some_vehicle->start();
    std::cout << std::endl;
    vehicle.draw();
    std::cout << std::endl;
    plane.draw();
    std::cout << std::endl;
    some_vehicle->draw();
    std::cout << std::endl;
    draw_shape(vehicle);
    std::cout << std::endl;
    draw_shape(plane);
    std::cout << std::endl;
    draw_shape(*some_vehicle);
    std::cout << std::endl;
    return 0;
}