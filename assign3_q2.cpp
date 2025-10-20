#include <iostream>
#include <stack>
using namespace std;

int main() {
    string str = "DataStructure", rev = "";
    stack<char> s;
    for (char c : str) s.push(c);
    while (!s.empty()) {
        rev += s.top();
        s.pop();
    }
    cout << rev;
}
