#include<bits/stdc++.h>
using namespace std;

class Stack{
private:
    int* arr;
    int top;
    int capacity;


public:
    Stack(int size) {
        capacity =size;
        arr= new int[capacity];
        top=-1;

    }
    ~Stack() {
        delete[] arr;
    }
    void push(int value) {
        if (isFull()) {
            cout<<"this is an overflow condition"<<endl;
            return;
        }
        arr[++top]=value;
        cout<<value<<"pushed to stack"<<endl;
    }
    int pop() {
        if (isEmpty()) {
            cout<<"this is an underflow condition"<<endl;
            return -1;
        }
        return  arr[top--];
    }
    bool isEmpty() {
        return  top == -1;
    }
    bool isFull() {
        return top ==capacity-1;
    }
    void display() {
        for (int i =top;i>=0;i--) {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    int peek() {
        return arr[top];
    }

};

void problem1() {
    cout << "\n=== PROBLEM 1: Menu Driven Stack Program ===" << endl;

    // Create a stack of size 5
    Stack s(5);

    int choice, value;  // Variables for user input

    // Main program loop
    do {
        // Display menu options
        cout << "\n--- Stack Operations Menu ---" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Check if Empty" << endl;
        cout << "4. Check if Full" << endl;
        cout << "5. Display" << endl;
        cout << "6. Peek" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        // Execute operation based on user choice
        switch(choice) {
            case 1:  // PUSH
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);  // Call push method
                break;

            case 2:  // POP
                value = s.pop();
                if (value != -1) {  // Check if pop was successful
                    cout << "Popped: " << value << endl;
                }
                break;

            case 3:  // CHECK EMPTY
                cout << "Stack is " << (s.isEmpty() ? "empty" : "not empty") << endl;
                break;

            case 4:  // CHECK FULL
                cout << "Stack is " << (s.isFull() ? "full" : "not full") << endl;
                break;

            case 5:  // DISPLAY
                s.display();
                break;

            case 6:  // PEEK
                value = s.peek();
                if (value != -1) {
                    cout << "Top element: " << value << endl;
                }
                break;

            case 0:  // EXIT
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 0);  // Continue until user chooses to exit
}
void revstr() {
    string s;

}
int main() {
    problem1();  // Call your menu-driven stack function
    return 0;
}

