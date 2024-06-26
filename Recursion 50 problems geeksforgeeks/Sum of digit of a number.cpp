#include<bits/stdc++.h>
using namespace std;
#define int        long long
const int M = 1e9 + 7;

int sumOfNumbers(int n){
    if(n <= 0)return 0;
    
    //sum(n) = sum(n / 1) + n%10;
    return sumOfNumbers(n / 10) + n % 10;
}


int32_t main(){
    int n;
    cin>>n;
    cout<<sumOfNumbers(n);
    
}