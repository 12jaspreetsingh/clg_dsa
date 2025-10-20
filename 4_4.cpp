#include <bits/stdc++.h>
using namespace std;

void firstNonRepeating(string str) {
    queue<char> q;
    int freq[256] = {0};

    for (auto ch : str) {
        q.push(ch);
        freq[ch]++;

        while (!q.empty() && freq[q.front()] > 1) {
            q.pop();
        }

        if (q.empty())
            cout << "-1 ";
        else
            cout << q.front() << " ";
    }
    cout << endl;
}

int main() {
    string s = "aabc";
    cout << "Input " << s << endl;
    cout << "Output ";
    firstNonRepeating(s);
}
