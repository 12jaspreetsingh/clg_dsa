#include<bits/stdc++.h>
using namespace std;
void swap(int &a, int &b) {
    int temp=a;
    a=b;
    b=temp;
}

void bubble_sort(int arr[], int size) {
    for (int i=0;i<size-1;i++) {
        bool swapped=false;
        for ( int j=0;j<size-i-1;j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j],arr[j+1]);
                swapped=true;
            }
        }
        if (!swapped) break;
    }
}
int main() {
    int arr[]={64,34,25,12,22,11,90};
    int size=sizeof(arr) /sizeof(arr[0]);
    bubble_sort(arr,size);
    for (int i=0;i<size;i++) {
        cout<<" "<<arr[i];
    }

}