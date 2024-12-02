#include<bits/stdc++.h>
using namespace std;

#define int long long
const int M = 1e9 + 7;
const int N = 2e3 + 10;

int n, W;
vector<int> wt(N),  val(N);
int dp[N][N];
bool trace[N][N];

int recur(int ind, int w){

    if(w == W)return 0;
    if(ind >= n)return 0;

    if(dp[ind][w] != -1)return dp[ind][w];

    int a = 0, b = 0;
    if(wt[ind] + w > W){
        a = recur(ind + 1, w);
        trace[ind][w] = false;

    }else{
        int in = val[ind] + recur(ind + 1, w + wt[ind]);
        int ex = recur(ind + 1, w);
        if(in > ex){
            trace[ind][w] = true;
        }else{
            trace[ind][w] = false;
        }
        b = max(in, ex);
    }

    return dp[ind][w] = max(a, b);
}

void tracedValue(){
    int i = 0, j = 0;
    while(i < n){
        if(trace[i][j]){
            cout << val[i] <<" ";
            j += wt[i];
        }else{
            i++;
        }
    }
    cout << endl;
}

int32_t main(){
    memset(dp, -1, sizeof(dp));
    cin >> n >> W;
    for(int i = 0; i < n; i++){
        cin >> wt[i] >> val[i];
    }

    cout << recur(0, 0) << endl;
    tracedValue();
}