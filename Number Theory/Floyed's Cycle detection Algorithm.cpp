#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        next = NULL;
    }
};

Node* head = NULL;

class LinkedList{
public:
    void insert(int value){
        Node* newNode = new Node(value);
        if(head == NULL){
            head = newNode;
        }else{
            newNode->next = head;
            head = newNode;
        }
    }

    Node* detectLoop(){
        if(head == NULL || head->next == NULL){
            return NULL;
        }
        Node *slowPointer = head, *fastPointer = head;

        while(slowPointer != NULL && fastPointer != NULL && fastPointer->next != NULL){
            slowPointer = slowPointer->next;
            fastPointer = fastPointer->next->next;

            if(slowPointer == fastPointer){
                break;
            }
        }
        if(slowPointer != fastPointer){
            return NULL;
        }

        slowPointer = head;
        while (slowPointer != fastPointer){
            slowPointer = slowPointer->next;
            fastPointer = fastPointer->next;
        }
        return slowPointer;        
    }
};

int main(){
    LinkedList l1;

    l1.insert(10);
    l1.insert(20);
    l1.insert(3);
    l1.insert(4);
    l1.insert(5);
    l1.insert(6);
    l1.insert(3);

    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }    

    temp->next = head;

    Node* loopStart = l1.detectLoop();
    if(loopStart == NULL){
        cout<<"Loop doesn't exists"<<endl;
    }else{
        cout<<"Loop does exists and starts from:"
            <<loopStart->data<<endl;
    }
    
}