#include<bits/stdc++.h>
using namespace std;
#define int         long long
const int M = 1e9 + 7;


//Recursive method
int power(int a, int b){
    if(b == 0)return 1;
    
    int res = power(a, b/2);
    if(b&1)return ((res * res) % M * a) % M;
    else return (res * res) % M;

}


//Iterative method 
int powerItMethod(int a, int b){
    int ans = 1;
    while(b > 0){
        if(b & 1)ans = (ans * a) % M;
        b >>= 1;
        a = (a * a) % M;
    }
    return ans;
}


int32_t main(){
    int a, b;
    cin>>a>>b;
    cout<<power(a, b)<<endl;    
    cout<<powerItMethod(a, b);

}