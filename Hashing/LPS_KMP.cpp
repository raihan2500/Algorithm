#include<bits/stdc++.h>
using namespace std;
#define print(arr)         for(auto x: arr)cout<<x<<' '; cout<<endl;
#define int        long long
const int M = 1e9 + 7;

vector<int> LPS(string str){
    int n = str.size();
    vector<int> v(n);
    int index = 0;
    
    for(int i = 1; i < n;){
        if(str[index] == str[i]){
            v[i] = index + 1;
            index++, i++;
        }else {
            if(index != 0){
                index = v[index - 1];
            }else {
                index = 0, i++;
            }
        }
    }
    return v;
}


int32_t main(){
    string str;
    cin >> str;
    print(LPS(str));
}