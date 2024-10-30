#include<bits/stdc++.h>
using namespace std;

#define int long long
const int M = 1e9 + 7;
const int N = 2e5 + 10;


int binExp(int a, int b){
    int ans = 1;
    while(b > 0){
        if(b & 1)ans = ((ans % M) * (a % M)) % M;
        b >>= 1;
        a = ((a % M) * (a % M)) % M;
    }
    return ans;
}

int mmiOfX(int b){ return binExp(b, M - 2); }

int Add(int a, int b){return ((a % M) + (b % M)) % M;}
int Sub(int a, int b){ a %= M, b %= M; if(a > b)swap(a, b); return ((a % M) - (b % M)) % M;}
int Mul(int a, int b){return ((a % M) * (b % M)) % M;}
int div(int a, int b){return ((a % M) * (mmiOfX(b) % M)) % M;}


int n;
vector<vector<int>> muliplyMatrix(vector<vector<int>> a, vector<vector<int>> b){
    vector<vector<int>> ans(n, vector<int> (n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k ++){
                ans[i][j] = Add(ans[i][j], Mul(a[i][k], b[k][j]));
            }
        }
    }
    return ans;
}

vector<vector<int>> binExpMatrix(vector<vector<int>> v, int p){
    if(p <= 1){
        return v;
    }
    vector<vector<int>> u = binExpMatrix(v, p / 2), temp;
    temp = muliplyMatrix(u, u);
    if(p & 1)return muliplyMatrix(temp, v);
    else return temp;  

}

int32_t main(){
    n = 2;
    vector<vector<int>> v = {{1, 1}, {1, 0}}, ans;


    int k; 
    while(cin >> k){
        ans = binExpMatrix(v, k - 1);
        if(k == 0)ans[0][0] = 0;

        cout << "The Fibonacci number for " << k <<" is " << ans[0][0] << endl;
    }
}