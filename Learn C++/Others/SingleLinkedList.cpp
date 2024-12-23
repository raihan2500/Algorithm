#include<bits/stdc++.h>
using namespace std;

#define int long long
const int M = 1e9 + 7;
const int N = 2e5 + 10;

template<typename T>
struct Node{
    T data;
    Node* next;
};

template<typename T>
class LinkedList{
    Node<T>* head;

public:
    LinkedList():head(NULL){}

    void insert(int val){
        Node<T>* newNode;
        newNode->data = val;
        newNode->next = head;
        head = newNode;
    }

    T top(){
        // if(head == NULL)return NULL;
        return head->data;
    }
};

int32_t main(){
    LinkedList<int> list;
    list.insert(5);
    list.insert(3);

    cout << list.top();

}