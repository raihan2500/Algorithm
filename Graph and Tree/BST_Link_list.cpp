#include<bits/stdc++.h>
using namespace std;

#define nl cout << endl;

struct Node{
    int value;
    Node *left, *right;
    Node(int val = 0){
        left = right = nullptr;
        value = val;
    }
};
typedef Node* node;

void display(vector<vector<int>> &graph){
    for(auto &v : graph){
        for(auto &i : v){
            if(i == 0)cout << ' ';
            else cout << i <<" ";
        }
        cout << endl;
    }
}

struct BST{
    node root;
    int mx_size, sz = 1;
    vector<vector<int>> graph;
    BST(int n = 100){
        mx_size = n;
        root = nullptr;
        graph = vector<vector<int>> (n + 1, vector<int> (n + 1));
    }

    void insert(int value, node ptr = nullptr, int i = 0, int j = 8){
        if(ptr == nullptr)ptr = root;
        if(root == nullptr){
            graph[i][j] = value;
            node new_node = new Node(value);
            root = new_node;
            return;
        }
        
        if(ptr->value == value)return;
        if(value > ptr->value){
            if(ptr->right != nullptr){
                insert(value, ptr->right);
            }else{
                node new_node = new Node(value);
                sz++;
                if(sz > mx_size){
                    cout << "Overflow" << endl;
                    return;
                }
                ptr->right = new_node;
            }
        }
        if(value < ptr->value){
            if(ptr->left != nullptr){
                insert(value, ptr->left);
            }else{
                node new_node = new Node(value);
                sz++;
                if(sz > mx_size){
                    cout << "Overflow" << endl;
                    return;
                }
                ptr->left = new_node;
            }
        }
    }

    node ptr;
    bool search(int value){
        ptr = root;
        while(ptr != nullptr){
            if(ptr->value == value)return true;
            if(value > ptr->value)ptr = ptr->right;
            else ptr = ptr->left;
        }
        return false;
    }

    void inOrder(node ptr = nullptr, bool start = true){
        if(start){start = false; ptr = root;}
        if(ptr == nullptr)return;

        inOrder(ptr->left, false);
        cout << ptr->value << " ";
        inOrder(ptr->right, false);
    }
};

int32_t main(){
    int n;
    cin >> n;
    BST bst(n);
    
    for(int i = 0; i < n; i++){
        int val; 
        cin >> val;
        bst.insert(val);
    }

    cout << "In order: ";
    bst.inOrder();nl;

    display(bst.graph);


    int query; cin >> query;
    while(query--){
        int val;
        cin >> val;
        cout << val <<" ";
        if(bst.search(val))cout << "Found" << endl;
        else cout << "Not found" << endl;
    }
}