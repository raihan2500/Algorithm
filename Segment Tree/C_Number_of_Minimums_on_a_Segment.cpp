#include<bits/stdc++.h>
using namespace std;

typedef                    long long ll;
typedef                    long double ld;
#define int                long long

#define yes                cout<<"YES\n"
#define no                 cout<<"NO\n"
#define nl                 cout<<"\n"
#define endl               "\n"

#define lin(n)             int n;cin>>n;
#define vin                vector<int>
#define pr                 pair<int, int>
#define pb(n)              push_back(n)
#define pp                 pop_back()
#define all(x)             x.begin(),x.end()

#define fi                 first
#define se                 second

#define forn(i,e)          for(int i=0;i<e;i++)
#define Forn(i,e)          for(int i=1;i<=e;i++)
#define rforn(i,s)         for(int i=s-1;i>=0;i--)
#define print(arr)         for(auto x: arr)cout<<x<<" ";nl;
#define mprint(mp)         for(auto a : mp)cout<<a.first<<" "<<a.second<<endl;

#define fast_in_out        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const long long INF = 1e18;
const int M = 1e9 + 7;
const int N = 2e5 + 100;


template<class Type>
class segTree{
    #define int long long
    private:
        int n, q;
        const int N = 1e6 + 10;
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
                return {INF, -1};
            }
            if(lo >= l and hi <= r)return tree[node];

            int mid = (lo + hi) / 2;
            Type q1 = query(2 * node, lo, mid, l, r);
            Type q2 = query(2 * node + 1, mid + 1, hi, l, r);
            Type q;

            //Edit here
            if(q1.first < q2.first)q = q1;
            else if(q2.first < q1.first) q = q2;
            else{
                q.first = q1.first;
                q.second = q1.second + q2.second;
            }            
            
            return q;
        }

        void update(int node, int lo, int hi, int pos, int val){
            if(hi < pos or lo > pos)return;
            if(hi == lo){
                tree[node].first = val;
                tree[node].second = 1;
                return;
            }

            int mid = (lo + hi) / 2;
            update(2 * node, lo, mid, pos, val);
            update(2 * node + 1, mid + 1, hi, pos, val);

            //Edit here
            if(tree[2 * node].first < tree[2 * node + 1].first){
                tree[node] = tree[2 * node];
            }else if(tree[2 * node + 1].first < tree[2 * node].first){
                tree[node] = tree[2 * node + 1];
            }else{
                tree[node].first = tree[2 * node].first;
                tree[node].second = tree[2 * node].second + tree[2 * node + 1].second;
            }
        }

        void build(int node, int lo, int hi){
            if(lo == hi){
                tree[node].first = v[lo];
                tree[node].second = 1;
                return;
            }

            int mid = (lo + hi) / 2;
            build(2 * node, lo, mid);
            build(2 * node + 1, mid + 1, hi);

            //Edit here
            if(tree[2 * node].first < tree[2 * node + 1].first){
                tree[node] = tree[2 * node];
            }else if(tree[2 * node + 1].first < tree[2 * node].first){
                tree[node] = tree[2 * node + 1];
            }else{
                tree[node].first = tree[2 * node].first;
                tree[node].second = tree[2 * node].second + tree[2 * node + 1].second;
            }
            
        }
};



int32_t main(){
    fast_in_out;
    int n, m;
    cin >> n >> m;
    vin v(n);
    forn(i,n)cin >> v[i];

    segTree<pair<int, int>> tree(v);

    while(m--){
        int type, l, r;
        cin >> type >> l >> r;
        
        if(type == 1){
            tree.Update(l, r);
        }else{
            pair<int, int> ans = tree.Query(l, --r);
            cout << ans.first <<" " << ans.second << endl;
        }
    }
    
}