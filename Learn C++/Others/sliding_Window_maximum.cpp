#include<bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include<bits/zzz.h>
#endif

#define int long long
const int M = 1e9 + 7;
const int N = 2e5 + 10;

int n, k;

int32_t main(){
    cin >> n >> k;
    vector<int> v(n + 1), ans;
    for(int i = 1; i <= n; i++)cin >> v[i];

    deque<int> q;

    for(int i = 1; i <= k; i++){
        while(!q.empty() and v[q.back()] < v[i]){
            q.pop_back();
        }
        q.push_back(i);
    }
    ans.push_back(v[q.front()]);

    for(int i = k + 1; i <= n; i++){
        if(q.front() == i - k){
            q.pop_front();
        }
        while(!q.empty() and v[q.back()] < v[i]){
            q.pop_back();
        }
        q.push_back(i);
        ans.push_back(v[q.front()]);
    }


    print(ans);
}