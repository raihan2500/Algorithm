#include<bits/stdc++.h>
using namespace std;
#define print(arr)         for(auto x: arr)cout<<x<<' '; cout<<endl;
#define int        long long
const int M = 1e9 + 7;

int func(int aa, int bb){
    __int128_t a = aa, b = bb;
    a--; b--;
    if(b < a)swap(a, b);
    return ((b * (b + 1) / 2) - (a * (a + 1) / 2)) % M;
}


int32_t main(){
    int a, b;
    cin >> a >> b;

    cout<<func(a, b)<<endl;
}