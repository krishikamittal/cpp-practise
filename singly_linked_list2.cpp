// Program: Demonstration of Merge Two Sorted Linked Lists using Singly Linked List Operations
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

    void merge(List &l2){

        Node* temp1 = head;
        Node* temp2 = l2.getHead();

        while(temp1 != NULL && temp2 != NULL){

            if(temp1->data < temp2->data){

                cout<<temp1->data<<" ";
                temp1 = temp1->next;
            }
            else{

                cout<<temp2->data<<" ";
                temp2 = temp2->next;
            }
        }

        while(temp1 != NULL){

            cout<<temp1->data<<" ";
            temp1 = temp1->next;
        }

        while(temp2 != NULL){

            cout<<temp2->data<<" ";
            temp2 = temp2->next;
        }
    }
};

int main(){

    List l1;
    List l2;

    l1.insertAtTail(1);
    l1.insertAtTail(3);
    l1.insertAtTail(5);

    l2.insertAtTail(2);
    l2.insertAtTail(4);
    l2.insertAtTail(6);

    l1.merge(l2);

    return 0;
}
