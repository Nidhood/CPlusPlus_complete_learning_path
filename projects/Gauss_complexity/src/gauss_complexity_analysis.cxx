#include "gauss_complexity_analysis.h"
#include <Eigen/Dense>
#include <iomanip>

// Print the equations system in a nice format 😎.
void gauss_analysis::Gauss::print_equations_system() const
{
    std::vector<size_t> max_widths(this->matrix[0].size(), 0);
    for (size_t i = 0; i < this->matrix.size(); ++i) {
        for (size_t j = 0; j < this->matrix[i].size(); ++j) {
            if (const size_t width = std::to_string(this->matrix[i][j]).length(); width > max_widths[j]) {
                max_widths[j] = width;
            }
        }
    }
    std::cout << "Sistema de ecuaciones lineales:\n";
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            std::cout << std::setw(max_widths[j]) << matrix[i][j];
            if (j < matrix[i].size() - 1) {
                std::cout << "x" << static_cast<char>('a' + j) << " + ";
            } else {
                std::cout << "x" << static_cast<char>('a' + j) << " = ";
            }
        }
        std::cout << independent_vector[i] << "\n";
    }
}

// Using Eigen library to calculate the determinant of the matrix, if the determinant is zero, the system of equations does not have a solution.
haveSolution gauss_analysis::Gauss::is_determinant_zero() const
{
    Eigen::MatrixXd A(this->n, this->n);
    for (int i = 0; i < this->n; i++)
    {
        for (int j = 0; j < this->n; j++)
        {
            A(i, j) = this->matrix[i][j];
        }
    }
    std::cout << "Determinante de la matriz: " << A.determinant() << std::endl;
    if (A.determinant() == 0)
    {
        return haveSolution::NOT_HAVE_SOLUTION;
    }
    return haveSolution::HAVE_SOLUTION;
}

// Solve the system of equations using the Gauss method and return the solution.
void gauss_analysis::Gauss::solve_gauss() {

    // Verify if the matrix and independent vector have the correct dimensions and independent vector e(n x n + 1, respectively).
    verify_matrix_dimensions();

    // Verify if the system has a unique solution (determinant is not zero).
    if (is_determinant_zero() == haveSolution::NOT_HAVE_SOLUTION) {
        std::cout << "El sistema no tiene solución única." << std::endl;
        return;
    }

    // Verify if the diagonal elements are not close to zero.
    if (!verify_diagonal_elements()) {
        std::cout << "Hay elementos diagonales cercanos a cero. Se requiere intercambio de filas." << std::endl;
    }

    this->solution.resize(this->matrix.size(), 0.0);
    this->operations_count = 0;
    this->operations_count_swapping_rows = 0;

    // Copy the matrix and independent vector for the swapping rows version
    const auto matrix_copy = this->matrix;
    const auto vector_copy = this->independent_vector;

    // Gaussian elimination without swapping rows
    gaussian_elimination();
    print_number_of_operations();

    // Gaussian elimination with swapping rows
    swapping_rows(matrix_copy, vector_copy);
    print_number_of_operations_swapping_rows();

    // Backward substitution
    backward_substitution();
    print_number_of_operations_backwards();
    print_number_of_operations_backwards_swapping_rows();

    // Print the solution of the system of equations.
    print_solutions();
}

// Gaussian elimination.
void gauss_analysis::Gauss::gaussian_elimination() {
    const int n = this->matrix.size();

    for (int i = 0; i < n; i++) {
        const double pivot = this->matrix[i][i];

        for (int j = i + 1; j < n; j++) {
            const double factor = this->matrix[j][i] / pivot;
            this->operations_count++; // Division

            for (int k = i; k < n; k++) {
                this->matrix[j][k] -= factor * this->matrix[i][k];
                this->operations_count += (n - 1); // Multiplication and subtraction
            }

            this->independent_vector[j] -= factor * this->independent_vector[i];
            this->operations_count += (n - 1); // Multiplication and subtraction
        }
    }
}

// Backward substitution.
void gauss_analysis::Gauss::backward_substitution() {
    const int n = this->matrix.size();

    for (int i = n - 1; i >= 0; i--) {
        double sum = 0.0;
        for (int j = i + 1; j < n; j++) {
            sum += this->matrix[i][j] * this->solution[j];
            this->operations_count += (n - 1); // Multiplication and sum
            this->operations_count_swapping_rows += (n - 1); // Multiplication and sum
        }
        this->solution[i] = (this->independent_vector[i] - sum) / this->matrix[i][i];
        this->operations_count += (n - 1); // Division and subtraction
        this->operations_count_swapping_rows += (n - 1); // Division and subtraction
    }
}

// Swapping rows.
void gauss_analysis::Gauss::swapping_rows(const std::vector<std::vector<double>>& matrix_copy, const std::vector<double>& vector_copy) {
    const int n = matrix_copy.size();
    this->operations_count_swapping_rows = 0;

    // Copy the matrix and independent vector
    auto local_matrix = matrix_copy;
    auto local_vector = vector_copy;

    for (int i = 0; i < n - 1; i++) {

        // Find the row with the maximum element in the current column
        int max_row = i;
        for (int j = i + 1; j < n; j++) {
            if (std::abs(local_matrix[j][i]) > std::abs(local_matrix[max_row][i])) {
                max_row = j;
            }
        }

        // Do the swap
        if (max_row != i) {
            std::swap(local_matrix[i], local_matrix[max_row]);
            std::swap(local_vector[i], local_vector[max_row]);
            this->swap_count++;
            this->operations_count_swapping_rows += n;
        }

        // Gaussian elimination
        for (int j = i + 1; j < n; j++) {
            if (std::abs(local_matrix[i][i]) < 1e-10) continue;

            double factor = local_matrix[j][i] / local_matrix[i][i];
            this->operations_count_swapping_rows++; // Division

            for (int k = i; k < n; k++) {
                local_matrix[j][k] -= factor * local_matrix[i][k];
                this->operations_count_swapping_rows += (n - 1); // Multiplication and subtraction
            }

            local_vector[j] -= factor * local_vector[i];
            this->operations_count_swapping_rows += (n - 1); // Multiplication and subtraction
        }
    }
}

// Verify if the matrix and independent vector have the correct dimensions and independent vector e(n x n + 1, respectively).
void gauss_analysis::Gauss::verify_matrix_dimensions() const {

    // Not null matrix and independent vector.
    if (matrix.empty() || independent_vector.empty()) {
        throw std::runtime_error("La matriz o el vector independiente están vacíos");
    }

    // Verify that the matrix is square (nxn)
    const int rows = matrix.size();
    for (const auto& row : matrix) {
        if (row.size() != rows) {
            throw std::runtime_error("La matriz debe ser cuadrada (nxn)");
        }
    }

    // Verify that the independent vector has dimension n
    if (independent_vector.size() != rows) {
        throw std::runtime_error("El vector independiente debe tener la misma dimensión que la matriz");
    }
}

// Verify if the diagonal elements are not close to zero (Aii≠0).
bool gauss_analysis::Gauss::verify_diagonal_elements() const {
    for (int i = 0; i < n; i++) {
        if (std::abs(matrix[i][i]) < 1e-10) {
            return false;
        }
    }
    return true;
}

// Print the solution of the system of equations.
void gauss_analysis::Gauss::print_solutions() const {
    std::cout << "Soluciones:\n";
    for (size_t i = 0; i < this->solution.size(); i++) {
        std::cout << "x" << (i + 1) << " = " << this->solution[i] << std::endl;
    }
}

// Print the number of operations (sums, subtractions, multiplications and divisions) when solving the system of equations.
void gauss_analysis::Gauss::print_number_of_operations() const {
    std::cout << "Total de operaciones: " << this->operations_count << std::endl;
}

// Print the number of operations (sums, subtractions, multiplications and divisions) when solving the system of equations backwards.
void gauss_analysis::Gauss::print_number_of_operations_backwards() const {
    std::cout << "Total de operaciones para la resolucion hacia atras: " << this->operations_count << std::endl;
}

// Print the number of operations (sums, subtractions, multiplications and divisions) when swapping rows.
void gauss_analysis::Gauss::print_number_of_operations_swapping_rows() const {
    std::cout << "Total de operaciones con intercambio de filas: " << this->operations_count_swapping_rows << " (número de intercambios realizados: " << this->swap_count << ")" << std::endl;
}

// Print the number of operations (sums, subtractions, multiplications and divisions) when solving the system of equations backwards with swapping rows.
void gauss_analysis::Gauss::print_number_of_operations_backwards_swapping_rows() const {
    std::cout << "Total de operaciones para la resolucion hacia atras con intercambio de filas: " << this->operations_count_swapping_rows << std::endl;
}