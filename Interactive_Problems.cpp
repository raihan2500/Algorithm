#include<bits/stdc++.h>
using namespace std;

int32_t main(){
    int lo = 1, hi = 1e6, mid;
    int ans = -1 ;

    while(lo < hi){
        int mid = (lo + hi) / 2;
        cout << mid <<endl;
        cout.flush();
        string str; 
        cin >> str;

        if(str == "<"){
            hi = mid - 1;
        }else{
            ans = max(ans, mid);
            lo = mid + 1;
        }
    }
    cout<<"! "<<ans<<endl;
    cout.flush();
    
}