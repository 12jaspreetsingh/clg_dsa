#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data1, Node* next1 = nullptr) {
        data = data1;
        next = next1;
    }
};

Node* ConverArr2ll(vector<int>& arr) {
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void printll(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data;
        if (temp->next != NULL) cout << " -> ";
        temp = temp->next;
    }

    cout << endl;
}

void findMiddle(Node* head) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    cout << "Middle Element is " << slow->data << endl;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    Node* head = ConverArr2ll(arr);

    cout << "Linked List: ";
    printll(head);

    findMiddle(head);
}
