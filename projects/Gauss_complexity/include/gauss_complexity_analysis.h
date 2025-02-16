#ifndef GAUSS_COMPLEXITY_ANALYSIS_H
#define GAUSS_COMPLEXITY_ANALYSIS_H

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// %                Project: Gauss - A numerical analysis tool                  %
// %                Created by: Ivan Dario Orozco Ibanez                        %
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// Conditions (initially):
// 1. Determinant of the matrix is not zero.
// 2. Is prohibited to swap rows.
//`3. n x n + 1 independent vector.
// 4. Print x1, x2, x3, ..., xn.
// 5. Print the number of operations (sums, subtractions, multiplications and divisions).
// 5. Additionally, count the number of operations whit backwards resolution.

#include <iostream>
#include <vector>
#include "utils.h"

namespace gauss_analysis {
    class Gauss
    {
        std::vector<std::vector<double>> matrix;
        std::vector<double> independent_vector;
        std::vector<double> solution;
        int n;
        long long operations_count;
        long long operations_count_swapping_rows;
        long long swap_count;

        public:
        Gauss() : n(0), operations_count(0), operations_count_swapping_rows(0), swap_count(0) {}
        ~Gauss() = default;
        Gauss(const std::vector<std::vector<double>>& matrix, const std::vector<double>& independent_vector): matrix(matrix), independent_vector(independent_vector), n(matrix.size()), operations_count(0), operations_count_swapping_rows(0), swap_count(0) {}
        void print_equations_system() const;
        haveSolution is_determinant_zero() const;
        void solve_gauss();
        void gaussian_elimination();
        void backward_substitution();
        void swapping_rows(const std::vector<std::vector<double>>& matrix_copy, const std::vector<double>& vector_copy);
        void verify_matrix_dimensions() const;
        bool verify_diagonal_elements() const;
        void print_number_of_operations() const;
        void print_number_of_operations_swapping_rows() const;
        void print_number_of_operations_backwards() const;
        void print_number_of_operations_backwards_swapping_rows() const;
        void print_solutions() const;
    };
}

#endif //GAUSS_COMPLEXITY_ANALYSIS_H