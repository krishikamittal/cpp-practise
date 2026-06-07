// Program: Demonstration of reverse Circular Linked List 
// Topic: Circular Linked List in C++
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

            tail->next = head;
        }
        else{

            tail->next = newNode;

            tail = newNode;

            tail->next = head;
        }
    }

    void reverseCLL(){

        Node* prev = tail;
        Node* curr = head;
        Node* nextptr;

        do{

            nextptr = curr->next;

            curr->next = prev;

            prev = curr;

            curr = nextptr;

        }while(curr != head);

        tail = head;
        head = prev;
    }

    void display(){

        Node* temp = head;

        do{

            cout<<temp->data<<" -> ";

            temp = temp->next;

        }while(temp != head);

        cout<<"HEAD";
    }
};

int main(){

    List l;

    l.insertAtTail(1);
    l.insertAtTail(2);
    l.insertAtTail(3);
    l.insertAtTail(4);

    l.reverseCLL();

    l.display();

    return 0;
}
