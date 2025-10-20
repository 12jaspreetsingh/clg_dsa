#include <iostream>
using namespace std;

void multiply(int a[][3], int b[][3], int c[][3]) {
    if (a[0][1] != b[0][0]) {
        cout << "Invalid dimensions for multiplication!\n";
        return;
    }

    int bt[20][3];
    int m = a[0][0], n = a[0][1], p = b[0][1];
    int totalA = a[0][2], totalB = b[0][2];


    bt[0][0] = b[0][1]; bt[0][1] = b[0][0]; bt[0][2] = b[0][2];
    int k=1;
    for (int i=0; i<b[0][1]; i++) {
        for (int j=1; j<=totalB; j++) {
            if (b[j][1] == i) {
                bt[k][0] = b[j][1];
                bt[k][1] = b[j][0];
                bt[k][2] = b[j][2];
                k++;
            }
        }
    }

    int r=1;
    for (int i=0; i<m; i++) {
        for (int j=0; j<p; j++) {
            int sum=0;
            for (int x=1; x<=totalA; x++) {
                if (a[x][0]==i) {
                    for (int y=1; y<=bt[0][2]; y++) {
                        if (bt[y][0]==j && a[x][1]==bt[y][1]) {
                            sum += a[x][2]*bt[y][2];
                        }
                    }
                }
            }
            if (sum!=0) {
                c[r][0]=i; c[r][1]=j; c[r][2]=sum;
                r++;
            }
        }
    }
    c[0][0]=m; c[0][1]=p; c[0][2]=r-1;
}

int main() {
    int a[4][3] = { {2,3,3}, {0,0,1}, {0,2,2}, {1,1,3} };
    int b[4][3] = { {3,2,3}, {0,1,4}, {1,0,5}, {2,1,6} };
    int c[20][3];

    multiply(a, b, c);

    cout << "Multiplication Result (Triplet form):\n";
    for (int i=0; i<=c[0][2]; i++) {
        cout << c[i][0] << " " << c[i][1] << " " << c[i][2] << endl;
    }
    return 0;
}
