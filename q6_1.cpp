#include <iostream>
using namespace std;

void transpose(int mat[][3], int t[][3]) {
    int rows = mat[0][0], cols = mat[0][1], terms = mat[0][2];
    t[0][0] = cols;
    t[0][1] = rows;
    t[0][2] = terms;

    int k = 1;
    for (int i = 0; i < cols; i++) {
        for (int j = 1; j <= terms; j++) {
            if (mat[j][1] == i) {
                t[k][0] = mat[j][1];
                t[k][1] = mat[j][0];
                t[k][2] = mat[j][2];
                k++;
            }
        }
    }
}

int main() {
    int mat[4][3] = { {3, 3, 3}, {0, 2, 3}, {1, 0, 4}, {2, 1, 5} };
    int t[4][3];

    transpose(mat, t);

    cout << "Transpose Matrix (Triplet form):\n";
    for (int i = 0; i <= t[0][2]; i++) {
        cout << t[i][0] << " " << t[i][1] << " " << t[i][2] << endl;
    }
    return 0;
}
