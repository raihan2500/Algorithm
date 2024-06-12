#include<bits/stdc++.h>
using namespace std;

#define ll                long long

#define endl               "\n"
#define nl                 cout<<"\n"
#define forn(i,e)          for(ll i=0;i<e;i++)
#define print(aaa)         for(auto a : aaa) cout<<a<<" "; cout<<endl;

int sz ;

void combination(vector<string> &Ans , vector<string> &str, string & digits, int n, string ans){


    if(n == sz){
        Ans.push_back(ans); 
        // cout<<ans<<endl;
        return;
    }

    // string s;
    // cout<<str[0];

    for(int i = 1; i <= str[digits[n]-50].size(); i++){

        string s = ans + str[digits[n] - 50][i-1];

        combination(Ans, str, digits, n + 1 ,s);
    }
    

}



vector<string> letterCombinations(string digits) {
    vector<string>hello;
    vector<string>str;
    sz = digits.size();
    str.push_back("abc");
    str.push_back("def");
    str.push_back("ghi");
    str.push_back("jkl");
    str.push_back("mno");
    str.push_back("pqrs");
    str.push_back("tuv");
    str.push_back("wxyz");
    if(digits.size()==0)return hello;

    // print(str[0]);

    // cout<<str[digits[1]-50]<<endl;
    
    combination(hello, str, digits, 0, {});
    
    print(hello);


    return hello;        
}

signed main()
{
    string str;
    cin>>str;
    letterCombinations(str);   
}