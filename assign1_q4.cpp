#include <iostream>
#include <vector>
#include <algorithm> // For std::reverse (optional, but convenient)
#include <limits>


void getArrayInput(std::vector<int>& arr, int size) {
    arr.clear();
    arr.reserve(size);

    std::cout << "Enter " << size << " elements:" << std::endl;
    for (int i = 0; i < size; ++i) {
        int element;
        std::cout << "Element " << (i + 1) << ": ";
        while (!(std::cin >> element)) {
            std::cout << "Invalid input. Please enter an integer: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        arr.push_back(element);
    }
}

// Function to display the elements of a 1D array
void display1DArray(const std::vector<int>& arr, const std::string& message = "Array elements: ") {
    if (arr.empty()) {
        std::cout << "Array is empty." << std::endl;
        return;
    }
    std::cout << message;
    for (int element : arr) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}


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
    if (matrix.empty() || matrix[0].empty()) {
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


void reverseArray() {
    int size;
    std::cout << "\n--- Reversing Array Elements ---" << std::endl;
    std::cout << "Enter the size of the array: ";
    while (!(std::cin >> size) || size <= 0) {
        std::cout << "Invalid size. Please enter a positive integer: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::vector<int> arr;
    getArrayInput(arr, size);
    display1DArray(arr, "Original array: ");


    int start = 0;
    int end = arr.size() - 1;
    while (start < end) {

        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        // Move pointers
        start++;
        end--;
    }

    display1DArray(arr, "Reversed array: ");
}


void matrixMultiplication() {
    std::cout << "\n--- Matrix Multiplication ---" << std::endl;
    int r1, c1, r2, c2;

    std::cout << "Enter rows for Matrix A: ";
    while (!(std::cin >> r1) || r1 <= 0) { /* validation */ std::cout << "Invalid. Enter positive: "; std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); }
    std::cout << "Enter columns for Matrix A: ";
    while (!(std::cin >> c1) || c1 <= 0) { /* validation */ std::cout << "Invalid. Enter positive: "; std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); }

    std::cout << "Enter rows for Matrix B: ";
    while (!(std::cin >> r2) || r2 <= 0) { /* validation */ std::cout << "Invalid. Enter positive: "; std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); }
    std::cout << "Enter columns for Matrix B: ";
    while (!(std::cin >> c2) || c2 <= 0) { /* validation */ std::cout << "Invalid. Enter positive: "; std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); }

    if (c1 != r2) {
        std::cout << "Matrix multiplication not possible! Columns of Matrix A must be equal to rows of Matrix B." << std::endl;
        return;
    }

    std::vector<std::vector<int>> matA;
    getMatrixInput(matA, r1, c1);
    displayMatrix(matA, "Matrix A:");

    std::vector<std::vector<int>> matB;
    getMatrixInput(matB, r2, c2);
    displayMatrix(matB, "Matrix B:");


    std::vector<std::vector<int>> resultMat(r1, std::vector<int>(c2, 0));


    for (int i = 0; i < r1; ++i) {
        for (int j = 0; j < c2; ++j) {
            for (int k = 0; k < c1; ++k) {
                resultMat[i][j] += matA[i][k] * matB[k][j];
            }
        }
    }

    displayMatrix(resultMat, "Result of Matrix A * Matrix B:");
}

void transposeMatrix() {
    std::cout << "\n--- Transpose of a Matrix ---" << std::endl;
    int rows, cols;

    std::cout << "Enter rows for the original matrix: ";
    while (!(std::cin >> rows) || rows <= 0) { /* validation */ std::cout << "Invalid. Enter positive: "; std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); }
    std::cout << "Enter columns for the original matrix: ";
    while (!(std::cin >> cols) || cols <= 0) { /* validation */ std::cout << "Invalid. Enter positive: "; std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); }

    std::vector<std::vector<int>> originalMat;
    getMatrixInput(originalMat, rows, cols);
    displayMatrix(originalMat, "Original Matrix:");


    std::vector<std::vector<int>> transposeMat(cols, std::vector<int>(rows));


    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            transposeMat[j][i] = originalMat[i][j];
        }
    }

    displayMatrix(transposeMat, "Transpose Matrix:");
}


int main() {
    int choice;
    do {
        std::cout << "\n--- Problem 4 Sub-parts ---" << std::endl;
        std::cout << "1. Reverse an Array" << std::endl;
        std::cout << "2. Matrix Multiplication" << std::endl;
        std::cout << "3. Transpose of a Matrix" << std::endl;
        std::cout << "4. Go back to main menu / Exit Problem 4" << std::endl;
        std::cout << "Enter your choice: ";

        while (!(std::cin >> choice)) {
            std::cout << "Invalid input. Please enter a number: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        switch (choice) {
            case 1:
                reverseArray();
                break;
            case 2:
                matrixMultiplication();
                break;
            case 3:
                transposeMatrix();
                break;
            case 4:
                std::cout << "Exiting Problem 4 section." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 4);

    return 0;
}
