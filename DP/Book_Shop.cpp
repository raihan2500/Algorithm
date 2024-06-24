#include<bits/stdc++.h>
using namespace std;
#define print(arr)         for(auto x: arr)cout<<x<<' '; cout<<endl;
#define int        long long
const int M = 1e9 + 7;

int n, x;
vector<pair<int, int>> v;

int recur(int n, int sum, int cost){
    int x = 0 , y = 0;
    // cout<<sum<<' '<<cost<<endl;
    
    if(n == -1){
        return sum;
    }

    if(cost > x){
        cout<<sum<<endl;
        
        return sum;
    }
    

    x = recur(n - 1, sum, cost);
    y = recur(n - 1, sum, cost + v[n].first) + v[n].second;

    return max(x, y);
}



int32_t main(){

    cin>>n>>x;
    for(int i = 0; i < n; i++){
        int fi; cin>>fi;
        v.push_back({fi, 0});
    }
    for(int i = 0; i < n; i++){
        cin>>v[i].second;
    }

    cout<<recur(n - 1, 0, 0)<<endl;



    
}
using namespace std;
#define print(arr)         for(auto x: arr)cout<<x<<' '; cout<<endl;
#define int        long long
const int M = 1e9 + 7;

int n, x;
vector<pair<int, int>> v;

int recur(int n, int sum, int cost){
    int x = 0 , y = 0;
    // cout<<sum<<' '<<cost<<endl;
    
    if(n == -1){
        return sum;
    }

    if(cost > x){
        cout<<sum<<endl;
        
        return sum;
    }
    

    x = recur(n - 1, sum, cost);
    y = recur(n - 1, sum, cost + v[n].first) + v[n].second;

    return max(x, y);
}



int32_t main(){

    cin>>n>>x;
    for(int i = 0; i < n; i++){
        int fi; cin>>fi;
        v.push_back({fi, 0});
    }
    for(int i = 0; i < n; i++){
        cin>>v[i].second;
    }

    cout<<recur(n - 1, 0, 0)<<endl;



    
}