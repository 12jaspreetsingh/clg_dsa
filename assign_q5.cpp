#include <iostream> // For input/output operations (cin, cout)
#include <vector>   // For using std::vector
#include <limits>   // For std::numeric_limits

void getMatrixInput(std::vector<std::vector<int>>& matrix, int rows, int cols) {
    matrix.assign(rows, std::vector<int>(cols));

    std::cout << "Enter elements for the " << rows << "x" << cols << " matrix:" << std::endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << "Enter element at [" << i << "][" << j << "]: ";

            while (!(std::cin >> matrix[i][j])) {
                std::cout << "Invalid input. Please enter an integer: ";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
    }
}


void displayMatrix(const std::vector<std::vector<int>>& matrix, const std::string& message = "Matrix elements: ") {
    if (matrix.empty() || (matrix.size() > 0 && matrix[0].empty())) {
        std::cout << "Matrix is empty." << std::endl;
        return;
    }
    std::cout << message << std::endl;
    for (const auto& row : matrix) {
        for (int element : row) {
            std::cout << element << "\t";
        }
        std::cout << std::endl;
    }
}


void sumRowsAndColumns() {
    std::cout << "\n--- Sum of Rows and Columns ---" << std::endl;
    int rows, cols;

    std::cout << "Enter the number of rows for the matrix: ";

    while (!(std::cin >> rows) || rows <= 0) {
        std::cout << "Invalid number of rows. Please enter a positive integer: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "Enter the number of columns for the matrix: ";

    while (!(std::cin >> cols) || cols <= 0) {
        std::cout << "Invalid number of columns. Please enter a positive integer: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::vector<std::vector<int>> myMatrix;
    getMatrixInput(myMatrix, rows, cols);
    displayMatrix(myMatrix, "Original Matrix:");

    // --- Calculate Sum of Each Row ---
    std::cout << "\n--- Sum of Rows ---" << std::endl;
    for (int i = 0; i < rows; ++i) {
        long long rowSum = 0;
        for (int j = 0; j < cols; ++j) {
            rowSum += myMatrix[i][j];
        }
        std::cout << "Sum of Row " << (i + 1) << ": " << rowSum << std::endl;
    }


    std::cout << "\n--- Sum of Columns ---" << std::endl;
    for (int j = 0; j < cols; ++j) {
        long long colSum = 0;
        for (int i = 0; i < rows; ++i) {
            colSum += myMatrix[i][j];
        }
        std::cout << "Sum of Column " << (j + 1) << ": " << colSum << std::endl;
    }
}

int main() {

    sumRowsAndColumns();

    return 0;
}
