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


struct point{
  int x, y;
  point(int x = 0, int y = 0) : x(x), y(y){};
} p0;

int orientation(point &a, point &b, point &c){
  int cross = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
  if(!cross)return 0;  //colinear
  return cross > 0 ? 1 : -1;       // +1 = CCW(left), -1 = CW(right)
}

bool comp(point &a, point &b){
  int dir = orientation(p0, a, b);
  if(dir == 0){
    if(a.y == b.y)return a.x < b.x;
    return a.y < b.y;
  }
  return dir > 0; //Take left point
}

vector<point> grahamScan(vector<point> v){
  int n = v.size();
  for(int i = 0; i < n; i++){
    if(v[i].y < v[0].y or (v[i].y == v[0].y and v[i].x < v[0].x)){
      swap(v[i], v[0]);
    }
  }
  p0 = v[0];
  sort(v.begin() + 1, v.end(), comp);

  int m = 1;
  for(int i = 1; i < n; i++){
    while(i + 1 < n and orientation(p0, v[i], v[i + 1]) == 0)i++;
    v[m++] = v[i];
  }
  if(m < 3)return {};

  vector<point>ans = {v[0], v[1], v[2]};
  for(int i = 3; i < m; i++){
    while(ans.size() > 1 and orientation(ans[ans.size() - 2], ans[ans.size() - 1], v[i]) != 1){
      ans.pop_back();
    }
    ans.push_back(v[i]);
  }
  return ans;
}

int32_t main(){
  int n; cin >> n;
  vector<point> v(n), ans;
  for(int i = 0; i < n; i++){
    cin >> v[i].x >> v[i].y;
  }

  ans = grahamScan(v);
  cout << ans.size() << endl;
  for(auto i : ans)cout << i.x <<" " << i.y << endl;

}