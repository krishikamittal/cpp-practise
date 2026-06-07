// Program: Demonstration of Merge Two Sorted Linked Lists using Singly Linked List Operations
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

void merge(Node* head1,Node* head2){

    while(head1!=NULL && head2!=NULL){

        if(head1->data < head2->data){
            cout<<head1->data<<" ";
            head1=head1->next;
        }
        else{
            cout<<head2->data<<" ";
            head2=head2->next;
        }
    }

    while(head1!=NULL){
        cout<<head1->data<<" ";
        head1=head1->next;
    }

    while(head2!=NULL){
        cout<<head2->data<<" ";
        head2=head2->next;
    }
}

int main(){

    Node* head1=NULL;
    Node* head2=NULL;

    insertAtTail(head1,1);
    insertAtTail(head1,3);
    insertAtTail(head1,5);

    insertAtTail(head2,2);
    insertAtTail(head2,4);
    insertAtTail(head2,6);

    merge(head1,head2);

    return 0;
}
