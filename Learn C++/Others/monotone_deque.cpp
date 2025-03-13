#include<bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include<sys/Zresource.h>
#endif

#define int long long
const int M = 1e9 + 7;
const int N = 2e5 + 10;

void problem1(){//Next greater element
    
    int n = 5;
    int arr[] = {2, 1, 2, 4, 3};
    //    ans =  4, 2, 4, -1, -1

    stack<int> st;
    vector<int> ans(n);

    for(int i = n - 1; i >= 0; i--){
        while(!st.empty() and st.top() <= arr[i]){
            st.pop();
        }
        
        if(st.empty())ans[i] = -1;
        else ans[i] = st.top();
        
        st.push(arr[i]);
    }
    print(ans);

}

int32_t main(){
    problem1();
}