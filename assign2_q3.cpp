#include<bits/stdc++.h>
using namespace std;
int find_num_linear(int arr[],int size,int n) {
    for (int i = 0;i<size;i++) {
        if (arr[i] != i+1) {
            return i+1;
        }
    }
    return n;
}
int find_nums_binary(int arr[],int size,int n) {
    int left=0 ;
    int right= size-1;
    while (left<=right) {
        int mid = left + (right - left)/2;
        if (arr[mid] != mid+1) {
            if ( arr[mid]==0 || arr[mid -1 ]==mid ) {
                return mid +1;
            }
            right =mid -1;
        }
        left= mid+1;
    }
    return n;
}
int main() {
    int arr[]={1,2,4,5,6};
    int size= sizeof(arr) / sizeof(arr[0]);
    int n=6;
    cout<<"the missing number is :"<<find_nums_binary(arr,size,n);

}