#include<bits/stdc++.h>
using namespace std;

#define int long long
const int M = 1e9 + 7;
const int N = 2e5 + 10;

class Dsu{
    private:
        int n;
        vector<int> par, sz;
        void make(){
            for(int v = 1; v <= n; v++){
                par[v] = v; 
                sz[v] = 1;
                sizes.insert(1);
            }
        }
    public:
        multiset<int> sizes;
        Dsu(int n){
            this->n = n;
            par = vector<int> (n + 1);
            sz = vector<int> (n + 1);
            make();
        }
        
        int Find(int v){
            if(par[v] == v)return v;
            return par[v] = Find(par[v]);
        }

        void merge(int a, int b){
            sizes.erase(sizes.find(sz[a]));
            sizes.erase(sizes.find(sz[b]));
            sizes.insert(sz[a] + sz[b]);
        }

        void Union(int a, int b){
            a = Find(a);
            b = Find(b);

            if(a != b){
                if(sz[a] < sz[b])swap(a, b);
                par[b] = a;
                merge(a, b);
                sz[a] += sz[b];
            }
        }
};

int32_t main(){
    int n, m;
    cin >> n >> m;
    Dsu dsu(n);

    while(m--){
        int u, v;
        cin >> u >> v;
        dsu.Union(u, v);
        cout << *dsu.sizes.rbegin() - *dsu.sizes.begin() << endl;
    }
  
}