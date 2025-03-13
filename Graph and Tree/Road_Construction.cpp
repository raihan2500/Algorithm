#include<bits/stdc++.h>
using namespace std;

#ifdef DEBUGd
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

int n, m;
vector<vector<int>> graph(N);

class Dsu{
    private:
        int n;
        int max_size = 1, cc;
        vector<int> par, sz;
        void make(){
            for(int v = 1; v <= n; v++){
                par[v] = v; 
                sz[v] = 1;
            }
        }
    public:
        Dsu(int n){
            this->n = n; cc = n;
            par = vector<int> (n + 1);
            sz = vector<int> (n + 1);
            make();
        }
        
        int Find(int v){
            if(par[v] == v)return v;
            return par[v] = Find(par[v]);
        }
        void Union(int a, int b){
            a = Find(a);
            b = Find(b);

            if(a != b){
                if(sz[a] < sz[b])swap(a, b);
                par[b] = a;
                sz[a] += sz[b];
                max_size = max(max_size, sz[a]);
                cc--;
            }
        }
        void query(){
            cout << cc <<" " << max_size << endl;
        }
};

void sukuna(){
    cin >> n >> m;
    Dsu dsu(n);
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        dsu.Union(x, y);
        dsu.query();
    }

}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    sukuna();
}