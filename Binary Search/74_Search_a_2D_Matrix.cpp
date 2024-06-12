#include<bits/stdc++.h>
using namespace std;

#define ll                long long

#define endl               "\n"
#define nl                 cout<<"\n"
#define forn(i,e)          for(ll i=0;i<e;i++)
#define print(aaa)         for(auto a : aaa) cout<<a<<" "; cout<<endl;


bool searchMatrix(vector<vector<int>>& matrix, int target) {
    
    int m = matrix.size(),  n = matrix[0].size();
    // cout<<n<<" "<<m<<endl;

    for(int i = 0; i < m; i++){
        int l = 0, r = n - 1;
        int mid;

        while(r - l > 0){
            mid = (r + l) / 2;
            if(matrix[i][mid] < target){
                l = mid + 1;
            }
            else {
                r = mid;
            }
        }
        if(matrix[i][l] == target){
            return true;
        }
        else if(matrix[i][r] == target){
            return true;
        }
    }

    return false;
}


signed main()
{
    int n, m;
    cin>>n>>m;
    vector<vector<int>>v;

    forn(j,m){
        vector<int>vv(n);
        forn(i,n)cin>>vv[i];
        v.push_back(vv);
    }

    // for(auto vv : v){
    //     print(vv);
    // }

    cout<<searchMatrix(v, 3888);
}