#include<bits/stdc++.h>
using namespace std;


template<class Type>
class segTree{
    #define int long long
    private:
        const int N = 1e6 + 10;
        int n;
        vector<int> v;
        vector<Type> tree = vector<Type> (4 * N);

    public:
        segTree(vector<int> v){
            this->v = v;
            n = v.size();
            build(1, 0, n - 1);
        }

        void Update(int pos, int val){
            update(1, 0, n - 1, pos, val);
        }
        Type Query(int l, int r){
            return query(1, 0, n - 1, l, r);
        }

    private:
        Type query(int node, int lo, int hi, int l, int r){

            if(hi < l or lo > r){
                //Edit here
                return 0;
            }
            if(lo >= l and hi <= r)return tree[node];

            int mid = (lo + hi) / 2;
            Type q1 = query(2 * node, lo, mid, l, r);
            Type q2 = query(2 * node + 1, mid + 1, hi, l, r);

            //Edit here
            return q1 + q2;
        }

        void update(int node, int lo, int hi, int pos, int val){
            if(hi < pos or lo > pos)return;
            if(hi == lo){
                tree[node] = val;
                return;
            }

            int mid = (lo + hi) / 2;
            update(2 * node, lo, mid, pos, val);
            update(2 * node + 1, mid + 1, hi, pos, val);

            //Edit here
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }

        void build(int node, int lo, int hi){
            if(lo == hi){
                tree[node] = v[lo];
                return;
            }

            int mid = (lo + hi) / 2;
            build(2 * node, lo, mid);
            build(2 * node + 1, mid + 1, hi);

            //Edit here
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
};


int32_t main(){
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    segTree<int> seg(v);

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