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

vector<int> build_suffix_array(string s) {
    s += "$"; // শেষে একটা ছোট (lexicographically smallest) চর যোগ করা হলো
    int n = s.size();
    vector<int> sa(n), c(n);
    
    // **ধাপ 1:** প্রথম অক্ষর দিয়ে sort করা
    vector<pair<char,int>> a(n);
    for(int i=0; i<n; i++) 
        a[i] = {s[i], i}; // প্রতিটি অক্ষর ও তার ইনডেক্স জোড়া হিসেবে রাখছি

    sort(a.begin(), a.end()); // প্রথম অক্ষর অনুযায়ী sort

    for(int i=0; i<n; i++) 
        sa[i] = a[i].second; // sort করা suffix-এর starting index

    // এখন প্রতিটি suffix কে class দিচ্ছি (একই অক্ষর মানে একই class)
    c[sa[0]] = 0;
    for(int i=1; i<n; i++) {
        if(a[i].first == a[i-1].first) 
            c[sa[i]] = c[sa[i-1]];
        else 
            c[sa[i]] = c[sa[i-1]] + 1;
    }
    // clog << db(sa) << db(c);

    int k = 0;
    // প্রতিবার 2^k দৈর্ঘ্যের prefix অনুযায়ী sort করা হবে
    while((1 << k) < n) {
        // **ধাপ 2:** এখন pair হিসেবে নিচ্ছি (বর্তমান class, পরের 2^k দূরের class)
        vector<pair<pair<int,int>, int>> b(n);
        for(int i=0; i<n; i++)
            b[i] = {{c[i], c[(i + (1 << k)) % n]}, i};
        
        sort(b.begin(), b.end()); // এই pair অনুযায়ী sort

        for(int i=0; i<n; i++) 
            sa[i] = b[i].second; // sort করা suffix-এর starting index
        
        // **ধাপ 3:** নতুন class তৈরি করছি
        vector<int> c_new(n);
        c_new[sa[0]] = 0;
        for(int i=1; i<n; i++) {
            if(b[i].first == b[i-1].first) 
                c_new[sa[i]] = c_new[sa[i-1]];
            else 
                c_new[sa[i]] = c_new[sa[i-1]] + 1;
        }
        c = c_new;
        k++;
    }
    return sa;
}


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
  v = ans;
  fill(cnt.begin(), cnt.end(),0);

  for(int i = 0; i < n; i++) cnt[v[i].first.first]++;
  for(int i = 1; i <= mx; i++) cnt[i]+=cnt[i-1];
  for(int i = n - 1; i>=0; i--){
    ans[--cnt[v[i].first.first]] = v[i];
  }
  v = ans;
}

vector<int> suffix_array(string str){
  str.push_back('#');
  int n = str.size();
  vector<int> sa(n), c(n);
  vector<pair<pair<int, int>, int>> v(n);
  
  for(int i = 0; i < n; i++)v[i] = {{str[i], 0}, i};
  counting_sort(v);
  for(int i = 0; i < n; i++)sa[i] = v[i].second;

  for(int i = 1; i < n; i++){
    if(v[i].first == v[i - 1].first){
      c[sa[i]] = c[sa[i - 1]];
    }else{
      c[sa[i]] = c[sa[i - 1]] + 1;
    }
  }

  for(int k = 0; (1 << k) < n; k++){
    for(int i = 0; i < n; i++){
      v[i] = {{c[i], c[(i + (1 << k)) % n]}, i};
    }
    counting_sort(v);
    for(int i = 0; i < n; i++)sa[i] = v[i].second;
    c[sa[0]] = 0;
    for(int i = 1; i < n; i++){
      if(v[i].first == v[i - 1].first){
        c[sa[i]] = c[sa[i - 1]];
      }else{
        c[sa[i]] = c[sa[i - 1]] + 1;
      }
    }
  }
  return sa;
}



int32_t main(){
  clog << build_suffix_array("banana");
  clog << suffix_array("banana");
  
}