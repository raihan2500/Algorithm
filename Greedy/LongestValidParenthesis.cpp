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


int longestValidParentheses(string str){
  int len = 0;
  stack<int> st; st.push(-1);
  
  for(int i = 0; i < str.size(); i++){
    if(str[i] == '('){
      st.push(i);
    }else{
      st.pop();
      if(st.empty()){
        st.push(i);
      }else{
        len = max(len, i - st.top());
      }
    }
  }
  return len;
}

int32_t main(){
  string str = "())(()))()";
  cout << longestValidParentheses(str) << endl; 
}