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

vector<int> z_func(string str){
    int n = str.size();
    vector<int> z(n);
    for(int i = 1, l = 0, r = 0; i < n; i++){
        if(i <= r)z[i] = min(r - i + 1, z[i - l]);
        while(i + z[i] < n and str[z[i]] == str[i + z[i]])z[i]++;
        if(i + z[i] - 1 > r)l = i, r = i + z[i] - 1;
    }
    return z;
}

int32_t main(){
    string str;
    cin >> str;

    print(z_func(str));
}