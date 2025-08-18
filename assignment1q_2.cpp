#include <bits/stdc++.h>
using namespace std;

int removeduplicates(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                for (int k = j; k < size - 1; k++) {
                    arr[k] = arr[k + 1];
                }
                size--;
                j--;
            }
        }
    }


    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return size;
}

int main() {
    int arr[] = {12, 12, 23, 5, 43123, 12, 23};
    int size = sizeof(arr) / sizeof(arr[0]);

    size = removeduplicates(arr, size);

    return 0;
}
