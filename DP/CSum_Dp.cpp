#include<bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include<algo/debug.h>
#include<algo/resources.h>
#else
#   define clog if (0) cerr
#   define DB(...)
#   define db(...) "" 
#endif

#define int long long
const int M = 1e9 + 7;
const int N = 2e5 + 10;

/*
You are given N dices and a value W. 
Each dices has F faces from 1 to F.
Calculate in how many ways you can set the top
faces so that summation of all the top faces is
equal to W module 1e9 + 7;
Constrain: 1<= N, F <= 1000 and 0 <= W <= 15000
*/

int n, f, w, dp[1001][15001];
int csum[1001][15001];

int naiveDP(){
    dp[n + 1][0] = 1;
    for(int i = n; i >= 1; i--){
        for(int j = 1; j <= w; j++){
            for(int k = 1; k <= f; k++){
                if(j < k)break;
                dp[i][j] += dp[i + 1][j - k];
            }
        }
    }
    return dp[1][w];
    //time complexity O(N * F * W);
}

int csumDP(){
    for(int i = 1; i <= w; i++)csum[n + 1][i] = 1;
    dp[n + 1][0] = csum[n + 1][0] = 1;

    for(int i = n; i >= 1; i--){
        for(int j = 1; j <= w; j++){
            if(j - f - 1 >= 0){
                dp[i][j] = csum[i + 1][j - 1] - csum[i + 1][j - f - 1];
            }else{
                dp[i][j] = csum[i + 1][j - 1];
            }
            csum[i][j] = csum[i][j - 1] + dp[i][j];
        }
    }
    return dp[1][w];
}

int32_t main(){
    cin >> n >> f >> w;

    cout << naiveDP() << endl;
    cout << csumDP() << endl;

    for(int i = 1; i <= n + 1; i++){
        for(int j = 0; j <= w; j++){
            clog << csum[i][j] <<" ";
        }clog << endl;
    }

}