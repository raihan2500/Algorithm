#include<bits/stdc++.h>
using namespace std;
#define int        long long
const int M = 1e9 + 7;

void recur(int n){
    if(n == 0)return;
    cout<<n<<endl;
    recur(n - 1);
}

int32_t main(){
    int n;
    cin>>n;
    recur(n);
}