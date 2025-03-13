#include<bits/stdc++.h>
using namespace std;

#define nl cout << endl;

struct BST{
    int root = 0, cnt = 0, N;
    vector<int> info, avail, left, right;

    BST(int n){
        N = n;
        info = vector<int> (N + 1);
        avail = info;
        left = info;
        right = info;
    }

    int get(){
        if(cnt >= N)return -1;
        cnt++;
        return cnt;
    }

    void insert(int value, int ptr = 0){
        if(ptr == 0)ptr = root;
        if(root == 0){
            get();
            info[cnt] = value;
            root = cnt;
            return;
        }
        
        if(info[ptr] == value)return;
        else if(value > info[ptr]){
            if(right[ptr]){
                insert(value, right[ptr]);
            }else{
                if(get() == -1){
                    cout << "Overflow" << endl;
                    return;
                }
                info[cnt] = value;
                right[ptr] = cnt;
            }
        }else{
            if(left[ptr]){
                insert(value, left[ptr]);
            }else{
                if(get() == -1){
                    cout << "Overflow" << endl;
                    return;
                }
                info[cnt] = value;
                left[ptr] = cnt;                
            }
        }
    }

    int ptr;
    bool search(int value){
        ptr = root;
        if(ptr == 0)return false;
        while(ptr != 0){
            if(info[ptr] == value)return true;
            if(value > info[ptr]){
                ptr = right[ptr];
            }else{
                ptr = left[ptr];
            }
        }
        return false;
    }

    void preOrder(int v = 1){
        if(v == 0)return;

        cout << info[v] << " ";
        preOrder(left[v]);
        preOrder(right[v]);
    }

    void inOrder(int v = 1){
        if(v == 0)return;

        inOrder(left[v]);
        cout << info[v] << " ";
        inOrder(right[v]);
    }

    
    void postOrder(int v = 1){
        if(v == 0)return;

        postOrder(left[v]);
        postOrder(right[v]);
        cout << info[v] << " ";
    } 

    
};


int32_t main(){
    int n;
    cin >> n;
    BST bst(n);
    for(int i = 0; i < n; i++){
        int value; 
        cin >> value;
        bst.insert(value);
    }

    //For overflow
    bst.insert(50);

    //Pre order
    cout << "Pre order: ";
    bst.preOrder(); nl;

    //In order
    cout << "In order: ";
    bst.inOrder(); nl;

    //Post order
    cout << "Post order: ";
    bst.postOrder(); nl;


    cout << "\nQueries" << endl; 
    int query; cin >> query;
    while(query--){
        int value; 
        cin >> value;
        cout << value <<" ";

        if(bst.search(value))cout << "Found" << endl;
        else cout << "Not found" << endl;
    }
}