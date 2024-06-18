//Accepted

#include<bits/stdc++.h>
using namespace std;
#define print(arr)         for(auto x: arr)cout<<x<<' '; cout<<endl;
#define int        long long
const int M = 1e9 + 7;

int binExp(int a, int b, int m){
    int ans = 1;
    while (b > 0)
    {
        if(b & 1)ans = (ans * a) % m;
        b >>= 1;
        a = (a * a )% m;
    }
    return ans;    
}

//a < M;
//b < 10^10^5

int32_t main(){
    int a, B = 0;
    string b;
    
    cin>>a>>b;
    //Convert the string to an integer number mod (count of co-prime between 1 and M) or Phi(M)
    //in this case M is a prime number so Phi(M) = M - 1

    
    for(int i = b.size() - 1, j = 0; i >= 0; i--, j++){
        B = (B + (b[i] - 48) * binExp(10, j, M - 1)) % (M -  1);
    }
    cout<<binExp(a, B, M)<<endl;
}