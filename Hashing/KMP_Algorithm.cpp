#include<bits/stdc++.h>
using namespace std;
#define print(arr)         for(auto x: arr)cout<<x<<' '; cout<<endl;
#define int        long long
const int M = 1e9 + 7;

vector<int> createTempArray(string pattern){
    vector<int> lps(pattern.size());
    
    int index = 0;
    for(int i = 1; i < pattern.size(); ){
        if(pattern[index] == pattern[i]){
            lps[i] = index + 1;
            index++; i++;
        }else{
            if(index != 0)index = lps[index - 1];
            else lps[i] = 0, i++;
        }
    }
    return lps;
}

void kmp(string text, string pattern){
    vector<int> lps = createTempArray(pattern);
    int i = 0, j = 0;

    while(i < text.size()){
        if(text[i] == pattern[j]){
            i++; j++;
        }else {
            if(j != 0)j = lps[j - 1];
            else i++;
        }
        if(j == pattern.size()){
            cout<<"found"<<endl;
            return;
        }
    }
    cout<<"Not found"<<endl;
}

int32_t main(){
    string pattern, text;
    getline(cin, text);
    getline(cin, pattern);

    kmp(text, pattern);
    
}