#include<bits/stdc++.h>
using namespace std;
#define print(arr)         for(auto x: arr)cout<<x<<' '; cout<<endl;
#define int        long long
const int M = 1e9 + 7;


int32_t main(){
    int n, m, sum = 0;
    cin>>n>>m;
    for(int i = 1; i <=m; i++){
        cout<<n<<" % "<<i<<"\t= "<<n % i<<endl;
        sum += n % i;
    }
    cout<<sum<<endl;
    
}