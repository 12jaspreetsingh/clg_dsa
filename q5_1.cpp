#include <iostream>
using namespace std;

void diagonalMatrix(int n) {
    int arr[n] = {0};

    // Set diagonal
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }


    cout << "Diagonal Matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) cout << arr[i] << " ";
            else cout << "0 ";
        }
        cout << endl;
    }
}
