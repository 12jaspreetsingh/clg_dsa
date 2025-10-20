#include <bits/stdc++.h>
using namespace std;

void interleave(queue<int>& q) {
    int n = q.size();
    if (n % 2 != 0) {
        cout << "not possible as odd" << endl;
        return;
    }

    int half = n / 2;
    queue<int> q2;

    for (int i = 0; i < half; i++) {
        q2.push(q.front());
        q.pop();
    }

    while (!q2.empty()) {
        q.push(q2.front());
        q2.pop();

        q.push(q.front());
        q.pop();
    }
}

int main() {
    queue<int> q;
    int arr[] = {4, 7, 11, 20, 5, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++) {
        q.push(arr[i]);
    }

    cout << "Original Queue ";
    queue<int> temp = q;
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;

    interleave(q);

    cout << "Interleaved Queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}
