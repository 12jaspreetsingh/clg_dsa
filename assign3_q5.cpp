#include <iostream>
#include <stack>
using namespace std;

int evalPostfix(string expr) {
    stack<int> s;
    for (char c : expr) {
        if (isdigit(c)) s.push(c - '0');
        else {
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();
            if (c == '+') s.push(a + b);
            else if (c == '-') s.push(a - b);
            else if (c == '*') s.push(a * b);
            else if (c == '/') s.push(a / b);
        }
    }
    return s.top();
}

int main() {
    cout << evalPostfix("231*+9-");
}
