#include<bits/stdc++.h>
using namespace std;

string dna = "AGTC";
char what(set<char> &s){
    for(auto &i : dna){
        if(!s.count(i))return i;
    }
    return 'A';
}

int32_t main(){
    string str, ans;

    int n = str.size();
    set<char> s;
    for(int i = 0; i < n; i++){
        s.insert(str[i]);
        while(s.size() == 3 and i < n){
            s.insert(str[i]);
            if(s.size() == 4){
                ans.push_back(str[i]);
                s.clear(); break;
            }
            i++;
        }
    }
    ans.push_back(what(s));
    cout << ans << endl;
}