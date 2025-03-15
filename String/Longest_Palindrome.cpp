#include<bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include<algo/debug.h>
#include<algo/resources.h>
#else
#   define clog if (0) cerr
#   define DB(...)
#   define db(...) "" 
#endif

#define int long long
const int M = 1e9 + 7;
const int N = 2e5 + 10;
string preprocess(string &str){
    string res = "*";
    for(auto &i : str){
        res.push_back('$');
        res.push_back(i);
    }
    res += "$#";
    return res;
}


string LPS(string &inp){
    
    string str = preprocess(inp);
    int n = str.size(), c = 0, r = 0, mx = 0;;
    vector<int> lps(n, 0);

    for(int i = 1; i < n - 1; i++){
        int mirror = 2 * c - i;
        
        if(i < r){
            lps[i] = min(r - i, lps[mirror]);
        }

        while(str[i + lps[i] + 1] == str[i - lps[i] - 1]){
            lps[i]++;
        }

        if(i + lps[i] > r){
            c = i;
            r = i + lps[i];
        }

        if(lps[i] > lps[mx])mx = i;
    }

    return inp.substr((mx - lps[mx]) / 2, lps[mx]);
}

int32_t main(){
    string str;
    cin >> str;
    cout << LPS(str) << endl;
}