#include <bits/stdc++.h>
using namespace std;

class st {
    queue<int> q1, q2;
public:
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }
    void pop() {
        q1.pop();
    }
    int top() {
        return q1.front();
    }
    bool empty() {
        return q1.empty();
    }
};

int main() {
    st s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.top() << endl;
    s.pop();

    cout << "Top element: " << s.top() << endl;
    s.pop();

    cout << "Top element: " << s.top() << endl;
    s.pop();

    if (s.empty())
        cout << "Stack is now empty\n";
}
