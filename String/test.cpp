#include<bits/stdc++.h>
using namespace std;

#define int long long
#ifdef DEBUG
#include<algo/debug.h>
#include<algo/resources.h>
#else
#   define clog if (0) cerr
#   define NB 420
#   define db(...) "" 
#endif

const int M = 1e9 + 7;
const int N = 2e5 + 10;

void counting_sort(vector<pair<pair<int,int>,int>> &v){
  int n = v.size();
  int mx = 0;
  for(int i = 0; i < n; i++)mx = max({mx, v[i].first.first, v[i].first.second});
  vector<pair<pair<int,int>,int>> ans(n);
  vector<int> cnt(mx+1);
  for(int i = 0; i < n; i++) cnt[v[i].first.second]++;
  for(int i = 1; i <= mx; i++) cnt[i]+=cnt[i-1];
  for(int i = n - 1; i>=0; i--){
    ans[--cnt[v[i].first.second]] = v[i];
  }
  swap(ans,v);
  fill(cnt.begin(), cnt.end(),0);

  for(int i = 0; i < n; i++) cnt[v[i].first.first]++;
  for(int i = 1; i <= mx; i++) cnt[i]+=cnt[i-1];
  for(int i = n - 1; i>=0; i--){
    ans[--cnt[v[i].first.first]] = v[i];
  }
  v = ans;
}


int32_t main(){
  
}