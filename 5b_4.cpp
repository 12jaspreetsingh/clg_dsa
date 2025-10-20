#include <bits/stdc++.h>
using namespace std;

class st {
    queue<int> q;
public:
    void push(int x) {
        int s = q.size();
        q.push(x);

        for (int i = 0; i < s; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    void pop() {
        q.pop();
    }
    int top() {
        return q.front();
    }
    bool empty() {
        return q.empty();
    }
};

int main() {
    st s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element " << s.top() << endl;
    s.pop();

    cout << "Top element " << s.top() << endl;
    s.pop();

    cout << "Top element " << s.top() << endl;
    s.pop();

    if (s.empty())
        cout << "Stack is now empty\n";
}
