#include<bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1e18;

vector<int> arr;
vector<int> segTree; 

void constructTree(int lo, int hi, int pos){
    if(lo == hi){
        segTree[pos] = arr[lo];
        return;
    }
    int mid = (lo + hi) / 2;

    constructTree(lo, mid, 2 * pos + 1);
    constructTree(mid + 1, hi, 2 * pos + 2);
    segTree[pos] = min(segTree[2 * pos + 1], segTree[2 * pos + 2]);
}

int rangeQuery(int qlo, int qhi, int lo, int hi, int pos){
    if(qlo <= lo && qhi >= hi){ //Total overlap
        return segTree[pos];
    }
    if(qlo > hi || qhi < lo){//No overlap
        return INF;
    }
    
    //Partial overlap
    int mid = (lo +  hi) / 2;
    return min(rangeQuery(qlo, qhi, lo, mid, 2 * pos + 1), rangeQuery(qlo, qhi, mid + 1, hi, 2 * pos + 2));
}


int32_t main(){
    int n, m, q;
    cin >> n >> q;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }

    if(__builtin_popcount(n) == 1)m = n * 2;
    else{
        bitset<32> b(n);
        for(int i = 31; i >= 0; i--){
            if(b[i]){
                m = 1 << (i + 2);
                break;
            }
        }
    }

    for(int i = 0; i < m; i++){
        segTree.push_back(INF);
    }
    constructTree(0, n - 1, 0);
    
    while(q--){
        int l, r;
        cin >> l >> r;
        l--; r--;
        cout<<rangeQuery(l, r, 0, n - 1, 0)<<endl;
    }

}
//https://www.youtube.com/watch?v=ZBHKZF5w4YU