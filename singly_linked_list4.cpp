// Program: Demonstration of Remove Duplicate Nodes using Singly Linked List
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

    void removeDuplicates(){

        Node* temp = head;

        while(temp != NULL && temp->next != NULL){

            if(temp->data == temp->next->data){

                Node* todelete = temp->next;

                temp->next = temp->next->next;

                delete todelete;
            }
            else{
                temp = temp->next;
            }
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
    l.insertAtTail(1);
    l.insertAtTail(2);
    l.insertAtTail(2);
    l.insertAtTail(3);

    l.removeDuplicates();

    l.display();

    return 0;
}
