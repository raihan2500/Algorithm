#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n, sum = 0;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    for(int i = 0; i < n; i++){
        if(v[i] - sum >= 2){
            cout<<sum + 1<<endl;
            return 0;
        }
        sum += v[i];
    }
    cout<<sum + 1<<endl;
}