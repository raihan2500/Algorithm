#include<bits/stdc++.h>
using namespace std;

#define int long long
const int M = 1e9 + 7;
const int N = 2e5 + 10;


class grp{public: int x, y, z; grp(){}grp(int a, int b, int c){x = a; y = b; z = c;}};

class dsu{
    private:
        int n; vector<int> par, sz;
        void make(){
            for(int v = 1; v <= n; v++){
                par[v] = v; 
                sz[v] = 1;
            }
        }
    public:
        dsu(int n){
            this->n = n;
            par = vector<int> (n + 1); sz = vector<int> (n + 1);
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
            }
        }
};

void kruskal(){
    int n, m;
    cin >> n >> m;
    vector<grp> graph;
    for(int i = 0; i < m; i++){
        int x, y, z;
        cin >> x >> y >> z;
        graph.push_back({x, y, z});
    }
    sort(graph.begin(), graph.end(),[](grp a, grp b){return a.z < b.z;});

    int total_cost = 0;
    dsu obj(n);

    for(auto edge : graph){
        int x = edge.x;
        int y = edge.y;
        int z = edge.z;

        if(obj.Find(x) == obj.Find(y))continue;
        obj.Union(x, y);
        total_cost += z;
    }

    cout << total_cost << endl;
}


int32_t main(){
    kruskal();  
}