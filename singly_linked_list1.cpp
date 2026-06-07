// Program: Demonstration of compare Two Linked Lists using Singly Linked List
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

void insertAtTail(Node* &head,int val){

    Node* n = new Node(val);

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

bool identical(Node* head1,Node* head2){

    while(head1!=NULL && head2!=NULL){

        if(head1->data != head2->data){
            return false;
        }

        head1=head1->next;
        head2=head2->next;
    }

    if(head1==NULL && head2==NULL){
        return true;
    }

    return false;
}

int main(){

    Node* head1=NULL;
    Node* head2=NULL;

    insertAtTail(head1,1);
    insertAtTail(head1,2);
    insertAtTail(head1,3);

    insertAtTail(head2,1);
    insertAtTail(head2,2);
    insertAtTail(head2,3);

    if(identical(head1,head2)){
        cout<<"Lists are Identical";
    }
    else{
        cout<<"Lists are Not Identical";
    }

    return 0;
}
