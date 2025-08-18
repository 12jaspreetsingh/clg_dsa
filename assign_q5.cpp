#include <iostream> // For input/output operations (cin, cout)
#include <vector>   // For using std::vector
#include <limits>   // For std::numeric_limits

// --- Helper Functions for Input/Display ---

// Function to get matrix input from the user
void getMatrixInput(std::vector<std::vector<int>>& matrix, int rows, int cols) {
    matrix.assign(rows, std::vector<int>(cols)); // Resize and initialize matrix with zeros

    std::cout << "Enter elements for the " << rows << "x" << cols << " matrix:" << std::endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << "Enter element at [" << i << "][" << j << "]: ";
            // Basic input validation
            while (!(std::cin >> matrix[i][j])) {
                std::cout << "Invalid input. Please enter an integer: ";
                std::cin.clear(); // Clear the error flag
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            }
        }
    }
}

// Function to display a matrix
void displayMatrix(const std::vector<std::vector<int>>& matrix, const std::string& message = "Matrix elements: ") {
    if (matrix.empty() || (matrix.size() > 0 && matrix[0].empty())) {
        std::cout << "Matrix is empty." << std::endl;
        return;
    }
    std::cout << message << std::endl;
    for (const auto& row : matrix) {
        for (int element : row) {
            std::cout << element << "\t"; // Use tab for better alignment
        }
        std::cout << std::endl;
    }
}

// --- Problem 5: Find sum of every row and every column ---
void sumRowsAndColumns() {
    std::cout << "\n--- Sum of Rows and Columns ---" << std::endl;
    int rows, cols;

    std::cout << "Enter the number of rows for the matrix: ";
    // Input validation for rows
    while (!(std::cin >> rows) || rows <= 0) {
        std::cout << "Invalid number of rows. Please enter a positive integer: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "Enter the number of columns for the matrix: ";
    // Input validation for columns
    while (!(std::cin >> cols) || cols <= 0) {
        std::cout << "Invalid number of columns. Please enter a positive integer: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::vector<std::vector<int>> myMatrix;
    getMatrixInput(myMatrix, rows, cols); // Get matrix elements from user
    displayMatrix(myMatrix, "Original Matrix:"); // Display the entered matrix

    // --- Calculate Sum of Each Row ---
    std::cout << "\n--- Sum of Rows ---" << std::endl;
    for (int i = 0; i < rows; ++i) { // Iterate through each row
        long long rowSum = 0; // Use long long to avoid overflow for large sums
        for (int j = 0; j < cols; ++j) { // Iterate through each element in the current row
            rowSum += myMatrix[i][j];
        }
        std::cout << "Sum of Row " << (i + 1) << ": " << rowSum << std::endl;
    }

    // --- Calculate Sum of Each Column ---
    std::cout << "\n--- Sum of Columns ---" << std::endl;
    for (int j = 0; j < cols; ++j) { // Iterate through each column
        long long colSum = 0; // Use long long to avoid overflow
        for (int i = 0; i < rows; ++i) { // Iterate through each element in the current column
            colSum += myMatrix[i][j];
        }
        std::cout << "Sum of Column " << (j + 1) << ": " << colSum << std::endl;
    }
}

int main() {
    // Call the function to demonstrate sum of rows and columns
    sumRowsAndColumns();

    return 0;
}
