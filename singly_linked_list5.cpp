// Program: Demonstration of Move Last Node to Front using Singly Linked List Operations
// Topic: Singly Linked List in C++

#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int val){
        data=val;
        next=NULL;
    }
};

void insertAtTail(Node* &head,int val){

    Node* n=new Node(val);

    if(head==NULL){
        head=n;
        return;
    }

    Node* temp=head;

    while(temp->next!=NULL){
        temp=temp->next;
    }

    temp->next=n;
}

void moveLastToFront(Node* &head){

    Node* temp=head;

    while(temp->next->next!=NULL){
        temp=temp->next;
    }

    Node* last=temp->next;

    temp->next=NULL;

    last->next=head;

    head=last;
}

void display(Node* head){

    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}

int main(){

    Node* head=NULL;

    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);

    moveLastToFront(head);

    display(head);

    return 0;
}
