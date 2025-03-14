#include<bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include<algo/debug.h>
#include<algo/resources.h>
#else
#   define clog if (0) cerr
#   define DB(...)
#   define db(...) "" 
#endif

#define int long long
const int M = 1e9 + 7;
const int N = 2e5 + 10;

struct Trie{
    struct node{
        bool end = false;
        node* next[26] = {nullptr};
    };
    
    node* root;
    Trie(){root = new node();}

    void insert(string str){
        int i = 0;
        node* it = root;
        while(i < str.size()){
            if(it->next[str[i] - 'a'] == nullptr){
                it->next[str[i] - 'a'] = new node();
            }
            it = it->next[str[i] - 'a']; i++;
        }
        it->end = true;
    }

    bool search(string str){
        int i = 0;
        node* it = root;
        while(i < str.size()){
            if(it->next[str[i] - 'a'] == nullptr)return false;
            it = it->next[str[i] - 'a']; i++;
        }
        return it->end == true;
    }
};

int32_t main(){
    Trie obj;
    obj.insert("hello");
    obj.insert("raihan");
    obj.insert("welcome");

    cout << obj.search("hello") << endl;
    cout << obj.search("hell") << endl;
    cout << obj.search("raihan") << endl;
    
    
}