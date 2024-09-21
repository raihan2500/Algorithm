#include<bits/stdc++.h>
using namespace std;

#define int long long
const int M = 1e9 + 7;
const int N = 2e5 + 10;

class Grp{
    public:
        int pref = 0, suff = 0, sum = 0, ans = 0;
        Grp(int pref, int suff, int sum, int ans){
            this->pref = pref;
            this->suff = suff;
            this->ans = ans;
            this->sum = sum;
        }
        Grp(){}
};

template<class Type>
class segTree{
    #define int long long
    private:
        const int N = 1e6 + 10;
        int n;
        vector<int> v;
        vector<Grp> tree = vector<Grp> (4 * N);

    public:
        int ans;
        segTree(vector<int> v){
            this->v = v;
            n = v.size();
            build(1, 0, n - 1);
            ans = tree[1].ans;
        }

        void Update(int pos, int val){
            update(1, 0, n - 1, pos, val);
            ans = tree[1].ans;            
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
                v[lo] = val;
                if(v[lo] <= 0){
                    tree[node] = Grp(0, 0, v[lo], 0);
                }else{
                    tree[node] = Grp(v[lo], v[lo], v[lo], v[lo]);
                }
                return;
            }

            int mid = (lo + hi) / 2;
            update(2 * node, lo, mid, pos, val);
            update(2 * node + 1, mid + 1, hi, pos, val);

            int sum = tree[2 * node].sum + tree[2 * node + 1].sum;
            int pref = max(tree[2 * node].pref, tree[2 * node].sum + tree[2 * node + 1].pref);
            int suff = max(tree[2 * node + 1].suff, tree[2 * node + 1].sum + tree[2 * node].suff);
            int ans = max(tree[2 * node].suff + tree[2 * node + 1].pref, max(tree[2 * node].ans, tree[2 * node + 1].ans));

            tree[node] = Grp(pref, suff, sum, ans);
        }


        void build(int node, int lo, int hi){
            if(lo == hi){
                if(v[lo] <= 0){
                    tree[node] = Grp(0, 0, v[lo], 0);
                }else{
                    tree[node] = Grp(v[lo], v[lo], v[lo], v[lo]);
                } 
                return;
            }

            int mid = (lo + hi) / 2;
            build(2 * node, lo, mid);
            build(2 * node + 1, mid + 1, hi);

            int sum = tree[2 * node].sum + tree[2 * node + 1].sum;
            int pref = max(tree[2 * node].pref, tree[2 * node].sum + tree[2 * node + 1].pref);
            int suff = max(tree[2 * node + 1].suff, tree[2 * node + 1].sum + tree[2 * node].suff);
            int ans = max(tree[2 * node].suff + tree[2 * node + 1].pref, max(tree[2 * node].ans, tree[2 * node + 1].ans));

            tree[node] = Grp(pref, suff, sum, ans);
        }
};



int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, q;
    cin >> n >> q;
    vector<int> v(n);

    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    segTree<int> tree(v);
    cout << tree.ans << endl;

    while(q--){
        int pos, val;
        cin >> pos >> val;
        tree.Update(pos, val);
        cout << tree.ans << endl;
    } 
}