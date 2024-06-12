#include<bits/stdc++.h>
using namespace std;

#define ll                long long

#define endl               "\n"
#define nl                 cout<<"\n"
#define forn(i,e)          for(ll i=0;i<e;i++)
#define print(aaa)         for(auto a : aaa) cout<<a<<" "; cout<<endl;

vector<vector<int>>Ans;

void pascal(vector<int>v, int i, int n){

    if(i >= n){
        return;
    }
    vector<int>ans;
    ans.push_back(v[0]);
    for(int i = 0; i < v.size()-1; i++){
        ans.push_back(v[i] + v[i+1]);
    }
    ans.push_back(1);
    Ans.push_back(ans);
    pascal(ans, i +1, n);
    
}

vector<vector<int>> generate(int numRows) {

    vector<int> v {1};
    Ans.push_back(v);
    pascal(v, 0, numRows-1);

    // for(auto ans : Ans){
    //     print(ans);
    // }

    return Ans;        
}


signed main()
{
    int n;
    cin>>n;
    generate(n);


    
}