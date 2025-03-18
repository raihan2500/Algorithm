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
const int N = 3e3 + 10;

int n;
double v[N], dp[N][N];

double recur(int i, int head){
    if(i > n)return head >= (n + 1) / 2;
    if(dp[i][head] != -1)return dp[i][head];

    double a = v[i] * recur(i + 1, head + 1);
    double b = (1 - v[i]) * recur(i + 1, head);

    return dp[i][head] = a + b;
}

int32_t main(){
    cin >> n;
    for(int i = 1; i <= n; i++)cin >> v[i];
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= n; j++){
            dp[i][j] = -1;
        }
    }

    double ans = recur(1, 0);
    cout << fixed << setprecision(9) << ans << endl;
}