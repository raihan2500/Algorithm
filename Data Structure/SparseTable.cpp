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

int t[N][18], v[N];
void build(int n){
    for(int i = 1; i <= n; i++)t[i][0] = v[i];
    for(int j = 1; (1 << j) <= n; j++){
        for(int i = 1; i + (1 << j) - 1 <= n; i++){
            t[i][j] = min(t[i][j - 1], t[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int query(int l, int r){
    int j = log2(r - l + 1);
    return min(t[l][j], t[r - (1 << j) + 1][j]);
}


int32_t main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)cin >> v[i];
    build(n);

    cout << query(1, 6) << endl;
}