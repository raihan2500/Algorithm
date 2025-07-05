#include<bits/stdc++.h>
using namespace std;

#define int long long
#ifdef DEBUG
#include<algo/debug.h>
#include<algo/resources.h>
#else
#   define clog if (0) cerr
#   define NB 420
#   define db(...) "" 
#endif

const int M = 1e9 + 7;
const int N = 2e5 + 10;


const int K = 26;
struct Node{
    int next[K];
    bool output = false;
    
    char pch;
    int p, link = -1;
    int go[K];

    Node(int p = -1, char ch = '#') : p(p), pch(ch){
        memset(next, -1, sizeof(next));
        memset(go, -1, sizeof(go));
    }
};

vector<Node> t(1);

void add(string &s){
    int it = 0;
    for(auto c : s){
        c -= 'a';
        if(t[it].next[c] == -1){
            t[it].next[c] = t.size();
            t.emplace_back(it, c + 'a');
        }
        it = t[it].next[c];
    }
    t[it].output = true;
}

int go(int v, char ch);
int get_link(int v){
    if(t[v].link != -1)return t[v].link;
    if(v == 0 or t[v].p == 0){
        t[v].link = 0;
    }else{
        t[v].link = go(get_link(t[v].p), t[v].pch);
    }
    return t[v].link;
}

int go(int v, char ch){
    int c = ch - 'a';
    if(t[v].go[c] != -1)return t[v].go[c];
    if(t[v].next[c] == -1){
        t[v].go[c] = (v == 0) ? 0 : go(get_link(v), ch);
    }else{
        t[v].go[c] = t[v].next[c];
    }
    return t[v].go[c];
}


int32_t main(){
  
}