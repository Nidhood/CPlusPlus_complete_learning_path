#include "gauss_complexity_analysis.h"
#include <iostream>

int main() {

    // Example 1 (class example):
    const std::vector<std::vector<double>> matrix = {
        {2, -3, 4},
        {1, 1, 2},
        {3, 5, -1}
    };
    const std::vector<double> independent_vector = {13, 4, -4};

    // Example 2 (4x4 matrix):
    const std::vector<std::vector<double>> matrix2 = {
        {1, 2, -1, 1},
        {2, -1, 2, 3},
        {-1, 3, 3, -2},
        {3, -2, 1, 1}
    };
    const std::vector<double> independent_vector2 = {0, 7, 17, -2};


    // Example 3 (Swapping rows):
    const std::vector<std::vector<double>> matrix3 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 0}
    };
    const std::vector<double> independent_vector3 = {14, 32, 23};

    // Create the object of the class Gauss:
    gauss_analysis::Gauss gauss(matrix, independent_vector);


    // Print the equation's system:
    gauss.print_equations_system();
    try {

        // Solve the system of equations using the Gauss method:
        gauss.solve_gauss();
    } catch (const std::runtime_error& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return 0;
}