// Program: Demonstration of Move Last Node to Front using Singly Linked List Operations
// Topic: Singly Linked List in C++

#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int val){
        data = val;
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
            tail = newNode;
        }
    }

    void moveLastToFront(){

        Node* temp = head;

        while(temp->next != tail){
            temp = temp->next;
        }

        tail->next = head;

        head = tail;

        tail = temp;

        tail->next = NULL;
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

    l.moveLastToFront();

    l.display();

    return 0;
}
