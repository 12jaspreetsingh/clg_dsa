#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int data ;
    Node* next;
    Node* prev;

    Node(int val) {
        data=val;
        next=NULL;
        prev=NULL;

    }

};
class Doublelist {
    Node* head;
    Node* tail;
public:
    Doublelist() {
        head = tail = NULL;
    }
    void push_front( int val) {
        Node* newnode=new Node(val);
        if (head== NULL) {
            head= tail=newnode;
        }
        newnode->next=head;
        head->prev=newnode;
        head = newnode;
    }
    void push_back(int val) {
        Node* newnode= new Node(val);
        if ( head == NULL) {
            head= tail=newnode;
        }
        tail->next=newnode;
        newnode->prev= tail;
        tail= newnode;
    }
    void insert(int val, int pos) {
        Node* newnode= new Node(val);
        if ( head == NULL) {
            head = tail = newnode;
        }
        Node* temp = head;
        int count=0;

        while ( count != pos ) {
            temp=temp->next;
            count++;
        }
        Node* pretemp=temp->prev;
        newnode->prev=temp->prev;
        temp->prev=newnode;
        pretemp->next=newnode;
        newnode->next=temp;
    }
    void pop_front() {
        Node* temp= head;
        head= head->next;
        if ( head!= NULL) head->prev= NULL;
        temp->next=NULL;
        delete temp;
    }
    void pop_back() {
        Node* temp= tail;
        tail= tail->prev;
        if (tail!= NULL) tail->next= NULL;
        temp->prev=NULL;
        delete temp;
    }
    void del(int pos) {

        if (head == NULL) {
            return;
        }

        if (pos == 0) {
            pop_front();
            return;
        }

        Node* temp = head;
        int count = 0;
        while (temp != NULL && count < pos) {
            temp = temp->next;
            count++;
        }

        if (temp == NULL) {

            return;
        }

        if (temp == tail) {
            pop_back();
            return;
        }

        Node* pretemp = temp->prev;
        Node* postemp = temp->next;


        pretemp->next = postemp;
        postemp->prev = pretemp;

        temp->next = NULL;
        temp->prev = NULL;
        delete temp;
    }

    void print() {
        Node* temp = head;
        while (temp != NULL) {
            cout<<temp->data<<"<==>";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
};

int main() {
    Doublelist dll;
    dll.push_front(1);
    dll.push_front(2);
    dll.push_front(3);
    dll.push_back(0);
    dll.push_back(-1);
    dll.insert(10,1);
    dll.pop_front();
    dll.pop_back();
    // dll.del(1);
    dll.print();
}