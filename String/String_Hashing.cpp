#include<bits/stdc++.h>
using namespace std;

#define int long long
const int M = 1e9 + 7;
const int N = 2e5 + 10;


int32_t main(){
    int n;
    cin >> n;
    vector<string> v(N);

    for(int i = 0; i < n; i++)cin >> v[i];

    for(int i = 0; i < n; i++)cout <<v[i] << endl;
}