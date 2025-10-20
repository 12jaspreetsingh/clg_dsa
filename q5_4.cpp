#include<iostream>
using namespace std;





void upperTriangularMatrix(int n) {
    int size = n * (n + 1) / 2;
    int arr[size] = {0};

    // Fill example values
    for (int i = 0; i < size; i++) arr[i] = i + 1;

    cout << "\nUpper Triangular Matrix:" << endl;
    int k = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i <= j) cout << arr[k++] << " ";
            else cout << "0 ";
        }
        cout << endl;
    }
}
