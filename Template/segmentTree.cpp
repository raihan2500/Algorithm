#include<bits/stdc++.h>
using namespace std;


class segTree{
    #define int long long
    private:
        int n, q;
        string type;
        const int N = 1e6 + 10;
        vector<int> v = vector<int> (N), tree = vector<int> (4 * N);
    public:
        segTree(string type, vector<int> v){
            this->v = v;
            n = v.size();
            this->type = type;
            build(1, 0, n - 1);
        }
        void Update(int l, int r){
            update(1, 0, n - 1, l, r);
        }
        int Query(int l, int r){
            return query(1, 0, n - 1, l, r);
        }

    private:
        int query(int node, int lo, int hi, int l, int r){
            if(hi < l or lo > r){
                if(type == "sum")return 0;
                if(type == "min")return 1e18;
                if(type == "max")return -1e18;
            }
            if(lo >= l and hi <= r)return tree[node];

            int mid = (lo + hi) / 2;
            int q1 = query(2 * node, lo, mid, l, r);
            int q2 = query(2 * node + 1, mid + 1, hi, l, r);

            if(type == "sum")return q1 + q2;
            if(type == "min")return min(q1, q2);
            if(type == "max")return max(q1, q2);
        }

        void update(int node, int lo, int hi, int l, int r){
            if(hi < l or lo > l)return;
            if(hi == lo){
                tree[node] = r;
                return;
            }

            int mid = (lo + hi) / 2;
            update(2 * node, lo, mid, l, r);
            update(2 * node + 1, mid + 1, hi, l, r);

            if(type == "sum")tree[node] = tree[2 * node] + tree[2 * node + 1];
            if(type == "min")tree[node] = min(tree[2 * node], tree[2 * node + 1]);
            if(type == "max")tree[node] = max(tree[2 * node], tree[2 * node + 1]);
        }

        void build(int node, int lo, int hi){
            if(lo == hi){
                tree[node] = v[lo];
                return;
            }

            int mid = (lo + hi) / 2;
            build(2 * node, lo, mid);
            build(2 * node + 1, mid + 1, hi);
            if(type == "sum")tree[node] = tree[2 * node] + tree[2 * node + 1];
            if(type == "min")tree[node] = min(tree[2 * node], tree[2 * node + 1]);
            if(type == "max")tree[node] = max(tree[2 * node], tree[2 * node + 1]);
        }
};

int32_t main(){
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    segTree seg("min", v);

    while(q--){
        int type, l, r;
        cin >> type >> l >> r;

        if(type == 2){
            cout << seg.Query(l, r - 1)<<endl;
        }else{
            seg.Update(l, r);
        }
    }    
}