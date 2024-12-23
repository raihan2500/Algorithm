#include<bits/stdc++.h>
using namespace std;

#define int long long
const int M = 1e9 + 7;
const int N = 2e5 + 10;

int fermat(int n){
    int a = ceil(sqrt(n));
    int b2 = a * a - n;
    int b = round(sqrt(b2));

    while(b * b != b2){
        a++;
        b2 = a * a - n;
        b = round(sqrt(b2));
    }

    return a + b;
}

int32_t main(){
    int n;
    cin >> n;
    cout << fermat(M * 3) << endl;
}