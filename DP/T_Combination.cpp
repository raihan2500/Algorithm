#include<bits/stdc++.h>
using namespace std;

int arr[35][35];

int comb(int n, int r){
    if(n < r)return  0;
    if(r == 0)return 1;
    if(r == 1)return n;
    if(n == 1)return 1;

    if(arr[n][r] == 0)arr[n][r] = comb(n - 1, r - 1);
    if(arr[n][r + 1] == 0)arr[n][r + 1] = comb(n - 1, r);

    return arr[n][r] + arr[n][r + 1];
}

int main(){
    int n, r;
    cin>>n>>r;
    cout<<comb(n, r);
}