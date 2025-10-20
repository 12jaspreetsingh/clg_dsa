#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* next;

    Node(int data1,Node* next1) {
        data= data1;
        next= next1;
    }
    Node(int data1) {
        data=data1;
        next=nullptr;

    }

};
Node* ConverArr2ll(vector<int> &arr) {
    Node* head= new Node(arr[0]);
    Node* mover=head;
    for (int i=1;i<arr.size();i++) {
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}
void printll(Node* head) {
    Node* temp= head;
    while (temp!=NULL) {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
Node* del_occ(Node* head, int val) {
    int count = 0;

    while (head != NULL && head->data == val) {
        Node* temp = head;
        head = head->next;
        delete temp;
        count++;
    }

    Node* curr = head;
    while (curr != NULL && curr->next != NULL) {
        if (curr->next->data == val) {
            Node* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
            count++;
        } else {
            curr = curr->next;
        }
    }

    cout << "Count " << count << endl;
    return head;
}
int main() {
    vector<int> arr = {1, 2, 1, 2, 1, 3, 1};
    int key = 1;

    Node* head = ConverArr2ll(arr);

    cout << "Original Linked List ";
    printll(head);

    head = del_occ(head, key);

    cout << "Updated Linked List ";
    printll(head);
}
