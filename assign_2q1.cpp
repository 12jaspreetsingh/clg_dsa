#include<bits/stdc++.h>
using namespace std;

int linear_search(int arr[], int num, int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == num) return i;
    }
}

int missing_num(int arr[], int n) {
    int sum = 0;
    int exp_sum = ((n +2)* (n+1)) / 2;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    int missing_num = exp_sum - sum;
    return missing_num;
}

int binary_search(int arr[], int number, int size) {
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int middle = left + (right - left) / 2;
        if (arr[middle] == number) {
            return middle;
        } else if (number > arr[middle]) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {1,2,4,5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int number = missing_num(arr,size);
    cout<<number<<endl;
    int index = binary_search(arr, number, size);
    if (index != -1)
        cout << "Number found at index " << index << endl;
    else
        cout << "Number not found in the list" << endl;

    return 0;
}
