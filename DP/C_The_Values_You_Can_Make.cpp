#include<bits/stdc++.h>
using namespace std;
#define print(arr)         for(auto x: arr)cout<<x<<' '; cout<<endl;
#define int        long long
const int M = 1e9 + 7;
const int N = 501;
int n, k, dp_counter = 0;
vector<int> v;

void recur(int n, int sum, vector<int> ans){
    dp_counter++;
    if(sum > k)return;

    if(sum == k){
        print(ans);
        return;
    }
    if(n == -1)return;

    recur(n - 1, sum, ans);
    
    if(sum + v[n] > k)return;
    ans.push_back(v[n]);
    recur(n - 1, sum + v[n], ans);

}


int32_t main(){
    cin>>n>>k;
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());
    // print(v);
    recur(n - 1, 0, {});
    cout<<dp_counter<<endl;
}