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

int pal[5005][5005];
int v[N];

int32_t main(){
  int n; cin >> n;
  for(int i = 0; i < n; i++)cin >> v[i];

  for(int i = 0; i < n; i++){
    int l = i, r = i;
    while(l >= 0 and r < n and v[l] == v[r]){
      pal[l][r] = 1;
      l--; r++;
    }
  }
  for(int i = 0; i < n - 1; i++){
    int l = i, r = l + 1;
    while(l >= 0 and r < n and v[l] == v[r]){
      pal[l][r] = true;
      l--; r++;
    }
  }

}
