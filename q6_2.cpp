#include <iostream>
using namespace std;

void add(int a[][3], int b[][3], int c[][3]) {
    if (a[0][0] != b[0][0] || a[0][1] != b[0][1]) {
        cout << "Matrix dimensions do not match!\n";
        return;
    }

    int i=1, j=1, k=1;
    while (i <= a[0][2] && j <= b[0][2]) {
        if (a[i][0] < b[j][0] || (a[i][0]==b[j][0] && a[i][1] < b[j][1])) {
            c[k][0] = a[i][0]; c[k][1] = a[i][1]; c[k][2] = a[i][2];
            i++; k++;
        }
        else if (b[j][0] < a[i][0] || (b[j][0]==a[i][0] && b[j][1] < a[i][1])) {
            c[k][0] = b[j][0]; c[k][1] = b[j][1]; c[k][2] = b[j][2];
            j++; k++;
        }
        else { // same row,col
            c[k][0] = a[i][0]; c[k][1] = a[i][1]; c[k][2] = a[i][2] + b[j][2];
            i++; j++; k++;
        }
    }

    while (i <= a[0][2]) { c[k][0] = a[i][0]; c[k][1] = a[i][1]; c[k][2] = a[i][2]; i++; k++; }
    while (j <= b[0][2]) { c[k][0] = b[j][0]; c[k][1] = b[j][1]; c[k][2] = b[j][2]; j++; k++; }

    c[0][0] = a[0][0];
    c[0][1] = a[0][1];
    c[0][2] = k-1;
}

int main() {
    int a[4][3] = { {3,3,3}, {0,0,2}, {1,1,3}, {2,2,4} };
    int b[4][3] = { {3,3,3}, {0,1,5}, {1,1,6}, {2,0,7} };
    int c[10][3];

    add(a, b, c);

    cout << "Addition Result (Triplet form):\n";
    for (int i=0; i<=c[0][2]; i++) {
        cout << c[i][0] << " " << c[i][1] << " " << c[i][2] << endl;
    }
    return 0;
}
