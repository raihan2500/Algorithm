#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int n, w;
int wt[105], val[105];


int recur(int ind, int wt_left){
    if(ind == n)return 0;
    if(wt_left <= 0)return 0;

    int x = recur(ind + 1, wt_left);

    int y = 0;
    if(wt_left > wt[ind])y = val[ind] + recur(ind + 1, wt_left- wt[ind]);

    return max(x, y);
    
}

int32_t main(){
    cin >> n >> w;

    for(int i = 0; i < n; i++){
        cin >> wt[i] >> val[i];
    }  
    cout << recur(0, w) << endl;
}