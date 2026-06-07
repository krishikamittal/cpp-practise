// Program: Demonstration of Move Last Node to Front using Doubly Linked list
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

    void moveLastToFront(){

        if(head == NULL || head == tail){
            return;
        }

        Node* last = tail;

        tail = tail->prev;

        tail->next = NULL;

        last->next = head;

        head->prev = last;

        last->prev = NULL;

        head = last;
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
