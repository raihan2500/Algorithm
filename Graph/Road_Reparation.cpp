#include<bits/stdc++.h>
using namespace std;

#define int long long
const int M = 1e9 + 7;
const int N = 2e5 + 10;
class grp{public: int x, y, z; grp(){} grp(int a, int b, int c){x = a; y = b; z = c;}};

vector<grp> graph;

class dsu{
    private:
        int n;
        vector<int> par, sz;
        void make(){
            for(int i = 1; i <= n; i++){
                par[i] = i;
                sz[i] = 1;
            }
        }
    public:
        dsu(int n){
            this->n = n;
            par = vector<int> (n + 1);
            sz = par;
            make();
        }


        int Find(int v){
            if(par[v] == v)return v;
            return par[v] = Find(par[v]);
        }

        void Union(int u, int v){
            u = par[u];
            v = par[v];

            if(u != v){
                if(sz[u] < sz[v])swap(u, v);
                par[v] = u;
                sz[u] += sz[v];
            }
        }

};


int32_t main(){
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int x, y, z;
        cin >> x >> y >> z;
        graph.push_back({x, y, z});
    }
    sort(graph.begin(), graph.end(), [](grp a, grp b){return a.z < b.z;});

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

    int temp = obj.Find(1);

    for(int i = 1; i <= n; i++){
        if(obj.Find(i) != temp){
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }

    cout << total_cost << endl;

  
}