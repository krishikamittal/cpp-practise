// Program: Demonstration of Intersection of Two Linked Lists using Singly Linked List Operations
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

    Node* getHead(){
        return head;
    }

    void intersection(List &l2){

        Node* temp1 = head;
        Node* temp2 = l2.getHead();

        while(temp1 != NULL && temp2 != NULL){

            if(temp1 == temp2){

                cout<<"Intersection at node "<<temp1->data;
                return;
            }

            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        cout<<"No Intersection";
    }
};

int main(){

    Node* common = new Node(3);
    common->next = new Node(4);
    common->next->next = new Node(5);

    List l1;
    List l2;

    l1.insertAtTail(1);
    l1.insertAtTail(2);

    l2.insertAtTail(6);
    l2.insertAtTail(7);

    l1.getHead()->next->next = common;
    l2.getHead()->next->next = common;

    l1.intersection(l2);

    return 0;
}
