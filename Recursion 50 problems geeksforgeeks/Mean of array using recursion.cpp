#include<bits/stdc++.h>
using namespace std;
#define int        long long
const int M = 1e9 + 7;

float mean(vector<int> &v, int n){
    
    if(n == -1)return 0;

    //Mean({1, 2, 3, 4}) = (Mean(1, 2, 3) * 3 + 4) / 4(index)

    return (mean(v, n - 1) * n + v[n]) * 1.0 / (n +  1);

}


int32_t main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin>>v[i];
    }

    cout<<mean(v, n - 1);
    
}