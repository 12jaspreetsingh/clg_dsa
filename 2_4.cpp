#include <iostream>
using namespace std;

class queue {
    static const int size = 10;   // max size
public:
    int q1[size];
    int curr_size = 0;
    int start = -1;
    int end = -1;

    void push(int n) {
        if (curr_size == size) {
            cout << "Queue full" << endl;
            return;
        }
        if (curr_size == 0) {
            start = 0;
            end = 0;
        } else {
            end = (end + 1) % size;
        }
        q1[end] = n;
        curr_size++;
        cout << n << " entered" << endl;
    }

    int pop() {
        if (curr_size == 0) {
            cout << "No element to pop" << endl;
            return -1;
        }
        int cd = q1[start];
        if (curr_size == 1) {
            start = end = -1;
        } else {
            start = (start + 1) % size;
        }
        curr_size--;
        cout << cd << " deleted" << endl;
        return cd;
    }
    bool isEmpty() {
        return (curr_size == 0);
    }


    bool isFull() {
        return (curr_size == size);
    }
    int top() {
        if (curr_size == 0) {
            cout << "Queue is empty! No front element." << endl;
            return -1;
        }
        return q1[start];
    }
    void display() {
        if (curr_size == 0) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue elements ";
        int i = start;
        for (int count = 0; count < curr_size; count++) {
            cout << q1[i] << " ";
            i = (i + 1) % size;
        }
        cout << endl;
    }
};

int main() {
    queue q;
    int choice, value;

    do {
        cout << "Queue Menu\n";
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
                q.top();
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
                cout << "Invalid choice Try again\n";
        }
    } while (choice != 0);

    return 0;
}
