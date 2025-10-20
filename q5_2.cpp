#include<iostream>
using namespace std;



void triDiagonalMatrix(int n) {
    int size = 3 * n - 2;
    int arr[size] = {0};

    for (int i = 0; i < size; i++) arr[i] = i + 1;

    cout << "\nTri-diagonal Matrix:" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i - j == 0) cout << arr[i - 1] << " ";
            else if (i - j == 1) cout << arr[n + j - 1] << " ";
            else if (j - i == 1) cout << arr[2 * n + i - 2] << " "; nal
            else cout << "0 ";
        }
        cout << endl;
    }
}
