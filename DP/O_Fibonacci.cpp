#include<bits/stdc++.h>
using namespace std;

int arr[40];


int fib(int n){
    if(n == 0)return 0;
    if(n == 1)return 1;

    if(arr[n + 1] == 0)arr[n + 1] = fib(n - 1);
    if(arr[n] == 0)arr[n] = fib(n - 2);

    return arr[n + 1] + arr[n];
}

int32_t main(){
    int n;
    cin>>n;
    cout<<fib(n - 1);
}