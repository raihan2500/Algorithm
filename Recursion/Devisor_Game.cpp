#include<bits/stdc++.h>
using namespace std;

#define ll                long long

#define endl               "\n"
#define nl                 cout<<"\n"
#define forn(i,e)          for(ll i=0;i<e;i++)
#define print(aaa)         for(auto a : aaa) cout<<a<<" "; cout<<endl;

vector<int>v {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

bool divisorGame(int n) {
    for(int i = 0; v[i] < n; i++){
        if(n % v[i]==0){
            return false;
        }
    }

    return true;
        
}


signed main()
{
    int n;
    cin>>n;
    divisorGame(n);

}