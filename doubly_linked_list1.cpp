// Program: Demonstration Reverse of Doubly Linked List Operations
// Topic: Doubly Linked List in C++
#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val){
        data = val;
        prev = NULL;
        next = NULL;
    }
};

class List{

    Node* head;
    Node* tail;

public:

    List(){
        head = tail = NULL;
    }

    void insertAtTail(int val){

        Node* newNode = new Node(val);

        if(head == NULL){
            head = tail = newNode;
        }
        else{
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void reverseDLL(){

        Node* curr = head;
        Node* temp = NULL;

        while(curr != NULL){

            temp = curr->prev;

            curr->prev = curr->next;

            curr->next = temp;

            curr = curr->prev;
        }

        if(temp != NULL){
            head = temp->prev;
        }
    }

    void display(){

        Node* temp = head;

        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }
};

int main(){

    List l;

    l.insertAtTail(1);
    l.insertAtTail(2);
    l.insertAtTail(3);
    l.insertAtTail(4);

    l.reverseDLL();

    l.display();

    return 0;
}
