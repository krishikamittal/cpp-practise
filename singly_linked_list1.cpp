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

    bool identical(List &l2){

        Node* temp1 = head;
        Node* temp2 = l2.getHead();

        while(temp1 != NULL && temp2 != NULL){

            if(temp1->data != temp2->data){
                return false;
            }

            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        if(temp1 == NULL && temp2 == NULL){
            return true;
        }

        return false;
    }
};

int main(){

    List l1;
    List l2;

    l1.insertAtTail(1);
    l1.insertAtTail(2);
    l1.insertAtTail(3);

    l2.insertAtTail(1);
    l2.insertAtTail(2);
    l2.insertAtTail(3);

    if(l1.identical(l2)){
        cout<<"Lists are Identical";
    }
    else{
        cout<<"Lists are Not Identical";
    }

    return 0;
}
