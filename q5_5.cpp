
#include<iostream>
using namespace std;




void symmetricMatrix(int n) {
    int size = n * (n + 1) / 2;
    int arr[size] = {0};


    for (int i = 0; i < size; i++) arr[i] = i + 1;

    cout << "\nSymmetric Matrix:" << endl;
    int k = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i >= j) {
                cout << arr[(i * (i - 1)) / 2 + (j - 1)] << " ";
            } else {
                cout << arr[(j * (j - 1)) / 2 + (i - 1)] << " ";
            }
        }
        cout << endl;
    }
}
