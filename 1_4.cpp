#include <iostream>
using namespace std;

class queue {
    static const int size = 10;
public:
    int q1[size];
    int start = -1;
    int end = -1;

    void push(int n) {
        if (end == size - 1) {
            cout << "Queue full" << endl;
            return;
        }
        if (start == -1) {
            start = 0;
        }
        end++;
        q1[end] = n;
        cout << n << " entered" << endl;
    }

    int pop() {
        if (start == -1 || start > end) {
            cout << "No element to pop" << endl;
            return -1;
        }
        int cd = q1[start];
        start++;
        cout << cd << " deleted" << endl;

        if (start > end) {
            start = end = -1;
        }
        return cd;
    }

    bool isEmpty() {
        return (start == -1);
    }

    bool isFull() {
        return (end == size - 1);
    }

    int top() {
        if (start == -1 || start > end) {
            cout << "Queue is empty! No front element." << endl;
            return -1;
        }
        return q1[start];
    }

    void display() {
        if (start == -1 || start > end) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = start; i <= end; i++) {
            cout << q1[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    queue q;
    int choice, value;

    do {
        cout << "\nQueue Menu\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Check if Empty\n";
        cout << "6. Check if Full\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.push(value);
                break;

            case 2:
                q.pop();
                break;

            case 3:
                cout << "Front element: " << q.top() << endl;
                break;

            case 4:
                q.display();
                break;

            case 5:
                if (q.isEmpty())
                    cout << "Queue is empty.\n";
                else
                    cout << "Queue is not empty.\n";
                break;

            case 6:
                if (q.isFull())
                    cout << "Queue is full.\n";
                else
                    cout << "Queue is not full.\n";
                break;

            case 0:
                cout << "Exiting program\n";
                break;

            default:
                cout << "Invalid choice! Try again\n";
        }
    } while (choice != 0);

    return 0;
}
