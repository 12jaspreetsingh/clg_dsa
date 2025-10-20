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
Node* insert_begin(Node* head,int val) {
    Node* temp=new Node(val,head);
    return temp;
}
Node* insert_last(Node* head, int val) {
    Node* temp = head;
    while (temp->next!=NULL) {
        temp=temp->next;
    }
    Node* newNode= new Node(val);
    temp->next= newNode;
    return head;
}
Node* insert_before(Node* head, int val, int k) {
    if (head==NULL) {
        return NULL;
    }
    if (head->data==k) {
        Node* temp= new Node(val,head);
        return temp;
    }
    Node* temp = head;
    while (temp->next!=NULL) {
        if (temp->next->data==k) {
            Node*x = new Node(val,temp->next);
            temp->next=x;
            break;
        }
        temp=temp->next;
    }
    return head;
}
Node* delete_begin(Node* head) {
    if (head==NULL) {
        return NULL;
    }
    Node* temp=head;
    head=head->next;
    delete temp;
    return head;
}
Node* delete_tail(Node* head) {
    if (head==NULL || head-> next == NULL) {
        return NULL;
    }
    Node* temp = head;
    while (temp->next->next!=NULL) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next=nullptr;
    return head;
}
Node* delete_value(Node* head, int val) {
    if (head==NULL) {
        return NULL;
    }
    if (head->data==val) {
        Node* temp= head;
        head= head->next;
        delete temp;
        return head;
    }
    Node* temp = head;
    Node* prev= NULL;
    while (temp!=NULL) {
        if (temp->data==val) {
            prev->next=prev->next->next;
            delete temp;
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}
int search(Node* head, int val) {
    Node* temp = head;
    int pos = 1;
    while (temp) {
        if (temp->data == val) {
            cout << "Value " << val << " found at position " << pos<<endl;
            return pos;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Value " << val << " not found"<<endl;
    return -1;

}
void printll(Node* head) {
    Node* temp= head;
    while (temp!=NULL) {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main() {
    Node* head = NULL;
    int choice, val, ref;
    vector<int> arr = {10};
    head = ConverArr2ll(arr);

    do {
        cout << "\nSingly Linked List Menu\n";
        cout << "1. Insert at Begin\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert Before a Node\n";
        cout << "4. Delete from Begin\n";
        cout << "5. Delete from End\n";
        cout << "6. Delete a Specific Node\n";
        cout << "7. Search a Node\n";
        cout << "8. Display List\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                head = insert_begin(head, val);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> val;
                head = insert_last(head, val);
                break;
            case 3:
                cout << "Enter value to insert: ";
                cin >> val;
                cout << "Enter value before which to insert: ";
                cin >> ref;
                head = insert_before(head, val, ref);
                break;
            case 4:
                head = delete_begin(head);
                break;
            case 5:
                head = delete_tail(head);
                break;
            case 6:
                cout << "Enter value to delete: ";
                cin >> val;
                head = delete_value(head, val);
                break;
            case 7:
                cout << "Enter value to search: ";
                cin >> val;
                search(head, val);
                break;
            case 8:
                printll(head);
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 0);
}