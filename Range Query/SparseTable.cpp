#include<bits/stdc++.h>
using namespace std;

vector<int> input;
vector<vector<int>> sparse;

vector<vector<int>> preProcess(vector<int> input, int n){

    vector<vector<int>> sparse(n, vector<int> (log2(n) + 1));
    for(int i = 0; i < n; i++)sparse[i][0] = i;
    
    for(int j = 1; (1 << j) <= n; j++){
        int p = (1 << j);
        for(int i = 0; i + p - 1 < n; i++){
            if(input[sparse[j][j - 1]] < input[sparse[i + (p / 2)][j - 1]]){
                sparse[i][j] = sparse[i][j - 1];
            }else{
                sparse[i][j] = sparse[i + (p / 2)][j - 1];
            }
        }
    }

    return sparse;
}

int Query(int lo, int hi){
    int l = hi - lo + 1;
    int k = log(l);
    return min(input[sparse[lo][k]], input[sparse[lo + l - (1 << k)][k]]);
}


int32_t main(){
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        input.push_back(x);
    }

    sparse = preProcess(input, n);

    while(q--){
        int l, r;
        cin >> l >> r;
        cout << Query(--l, --r) << endl;
    }


}