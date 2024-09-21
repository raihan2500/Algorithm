#include<bits/stdc++.h>
using namespace std;

#define int long long
const int M = 1e9 + 7;
const int N = 2e5 + 10;


class KMP{
    public:
        int matchCnt = 0;
        KMP(string text, string pattern){
            this->text = text;
            this->pattern = pattern;
            n = text.size();
            m = pattern.size();
            isMatchs();
        }
    private:
        string text, pattern;
        int n, m;

        vector<int> createTempArray(){
            vector<int> lps(m);
            int index = 0;

            for(int i = 1; i < m; i++){
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

        void isMatchs(){
            vector<int> lps = createTempArray();
            int i = 0, j = 0;

            while(i < n){
                if(text[i] == pattern[j]){
                    i++; j++;
                }else{
                    if(j != 0)j = lps[j - 1];
                    else i++;
                }
                if(j == m){
                    matchCnt++;
                    j = 0;
                }
            }
        }
};


int32_t main(){

    string a, b;
    cin >> a >> b;
    KMP hash(a, b);
    
    cout << hash.matchCnt << endl;
}