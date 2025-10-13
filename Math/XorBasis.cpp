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

const int LG = 31;

int sz = 0;
int basis[LG];

void insert(int mask){
  for(int i = LG - 1; i >= 0; i--){
    if((mask & (1 << i)) == 0)continue;
    if(!basis[i]){
      basis[i] = mask;
      sz++; return;
    }
    mask ^= basis[i];
  }
}

int32_t main(){
  
}