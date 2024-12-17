#include<bits/stdc++.h>
using namespace std;

#define int long long
const int M = 1e9 + 7;
const int N = 2e5 + 10;

template<class T>
class Node{
  private:
    T data;
    Node<T> *next;
  public:
    Node(T d){
        data = d;
        next = nullptr;
    }  
};


template<class T>
class LinkedList{
    private:
    Node<T> *top;
    
    public:
    LinkedList(){
        top = nullptr;
    }

    void push(T data){
        Node<T> newNode = Node(data);
        newNode.next = top;
        top = newNode;
    }

    T pop(){
        if(top == nullptr){
            cout << "Stack is empty!" << endl;
            return nullptr;
        }
        T data = top.data;
        top = top.next;
        cout << "Popped: " << data << endl;
        return data;
    }

    bool isEmpty(){
        return top == nullptr;
    }
};

int32_t main(){
    LinkedList<string> list;
    
    list.push("Raihan");
    list.push("Ahmed");

    list.pop();
    cout << list.isEmpty() << endl;
    list.pop();
}