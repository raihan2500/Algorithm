#include<bits/stdc++.h>
using namespace std;

#define int long long
const int M = 1e9 + 7;
const int N = 2e5 + 10;

vector<vector<int>> fib_base = {{1, 1}, {1, 0}}; //for Fibonacci number
vector<vector<int>> matrixMult(vector<vector<int>> a, vector<vector<int>> b){
    int m = a.size(), n = a[0].size(), l = b[0].size();
    vector<vector<int>> ans(m, vector<int> (l));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < l; j++){
            for(int k = 0; k < n; k++){
                ans[i][j] += a[i][k] * b[k][j] % M;
                ans[i][j] %= M;
            }
        }
    }
    return ans;
}

vector<vector<int>> binExpMatrix(vector<vector<int>> v, int p){
    if(p <= 1)return v;
    vector<vector<int>> u = binExpMatrix(v, p / 2);
    if(p & 1)return matrixMult(matrixMult(u, u), v);
    return matrixMult(u, u);
}

int32_t main(){
    int n;
    cin >> n;
    if(n == 0)cout << 0 << endl;
    else cout << binExpMatrix(fib_base, n)[0].back() << endl;
}