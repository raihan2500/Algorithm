#include<bits/stdc++.h>
using namespace std;

#define print(aaa)          for(auto a : aaa)cout<<a<<"";cout<<endl;


void permutation(set<int>s, set<vector<int>>&ss, vector<int>v, vector<int> ans, int n, int i){
    
    // cout<<v[i]<<" ";
    // cout<<n<<endl;
    if(ans.size() == n){
        ss.insert(ans);
        return;
    }
    if(s.count(i)==1){
        return;
    }

    s.insert(i);
    ans.push_back(v[i]);


    for(int j = 0; j < n; j++){
        // cout<<endl;
        // if(s.count(j)==0)
             permutation(s, ss, v, ans, n, j);

    }


}


vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> Ans;
    set<vector<int>>ss;
    int i = 0;

    for(int i = 0; i< nums.size(); i++)
        permutation({}, ss, nums, {}, nums.size(), i);

    for(auto ans : ss){
        Ans.push_back(ans);
    }
    

    return Ans;        
}

int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i = 0; i < n; i++){
        cin>>v[i];
    }

    permute(v);
}