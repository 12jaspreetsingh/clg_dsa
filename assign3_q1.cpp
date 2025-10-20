#include <iostream>
using namespace std;
#define SIZE 5

class Stack {
    int arr[SIZE];
    int top;
public:
    Stack() { top = -1; }
    void push(int x) {
        if (top == SIZE - 1) cout << "Stack Full\n";
        else arr[++top] = x;
    }
    void pop() {
        if (top == -1) cout << "Stack Empty\n";
        else cout << "Popped: " << arr[top--] << "\n";
    }
    void isEmpty() { cout << (top == -1 ? "True\n" : "False\n"); }
    void isFull() { cout << (top == SIZE - 1 ? "True\n" : "False\n"); }
    void display() {
        if (top == -1) cout << "Stack Empty\n";
        else {
            for (int i = top; i >= 0; i--) cout << arr[i] << " ";
            cout << "\n";
        }
    }
    void peek() {
        if (top == -1) cout << "Stack Empty\n";
        else cout << "Top: " << arr[top] << "\n";
    }
};

int main() {
    Stack s;
    int ch, val;
    while (1) {
        cout << "1.Push 2.Pop 3.isEmpty 4.isFull 5.Display 6.Peek 7.Exit\n";
        cin >> ch;
        if (ch == 1) { cin >> val; s.push(val); }
        else if (ch == 2) s.pop();
        else if (ch == 3) s.isEmpty();
        else if (ch == 4) s.isFull();
        else if (ch == 5) s.display();
        else if (ch == 6) s.peek();
        else if (ch == 7) break;
    }
}
