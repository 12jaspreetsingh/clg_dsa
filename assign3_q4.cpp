#include <iostream>
#include <stack>
using namespace std;

int prec(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    if (c == '^') return 3;
    return 0;
}

string infixToPostfix(string expr) {
    stack<char> s;
    string res = "";
    for (char c : expr) {
        if (isalnum(c)) res += c;
        else if (c == '(') s.push(c);
        else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                res += s.top(); s.pop();
            }
            s.pop();
        } else {
            while (!s.empty() && prec(s.top()) >= prec(c)) {
                res += s.top(); s.pop();
            }
            s.push(c);
        }
    }
    while (!s.empty()) {
        res += s.top(); s.pop();
    }
    return res;
}

int main() {
    cout << infixToPostfix("A*(B+C)");
}
