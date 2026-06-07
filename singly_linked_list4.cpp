// Program: Operations on Remove Duplicate Nodes using Singly Linked List
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

void removeDuplicates(Node* head){

    Node* temp=head;

    while(temp!=NULL && temp->next!=NULL){

        if(temp->data == temp->next->data){

            Node* todelete=temp->next;

            temp->next=temp->next->next;

            delete todelete;
        }
        else{
            temp=temp->next;
        }
    }
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
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,2);
    insertAtTail(head,3);

    removeDuplicates(head);

    display(head);

    return 0;
}
