// Program: Demonstration of Intersection of Two Linked Lists using Singly Linked List Operations
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

int countNodes(Node* head){

    int count=0;

    while(head!=NULL){
        count++;
        head=head->next;
    }

    return count;
}

Node* intersection(Node* head1,Node* head2){

    while(head1!=NULL && head2!=NULL){

        if(head1==head2){
            return head1;
        }

        head1=head1->next;
        head2=head2->next;
    }

    return NULL;
}

int main(){

    Node* common = new Node(3);
    common->next = new Node(4);
    common->next->next = new Node(5);

    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = common;

    Node* head2 = new Node(6);
    head2->next = new Node(7);
    head2->next->next = common;

    Node* ans = intersection(head1,head2);

    if(ans!=NULL){
        cout<<"Intersection at "<<ans->data;
    }
    else{
        cout<<"No Intersection";
    }

    return 0;
}
