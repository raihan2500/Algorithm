#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<int> v(n), lis;
    
    for(int i = 0; i < n; i++){
        cin>>v[i];
    }   


    lis.push_back(v[0]);

    for(int i = 1; i < n; i++){
        
        if(lis.back() < v[i]){
            lis.push_back(v[i]);
        }else {
            int index = lower_bound(lis.begin(), lis.end(), v[i]) - lis.begin();
            lis[index] = v[i];
        }
    }

    cout<<lis.size()<<endl;

}