#include<bits/stdc++.h>
using namespace std;

    vector<string> anss;

    void func(string ans, int n, int f, int l) {

        if (ans[0] == ')') {
            return;
        }

        if (f == l && ans[f + l - 1] == '(') {
            return;
        }

        if (n == 0) {
            if (f == l && f>0 && ans[ans.size() - 1] == ')') {
                anss.push_back(ans);
            }
            return;
        }

        ans.push_back('(');
        func(ans, n - 1, f + 1, l);

        ans.pop_back();
        ans.push_back(')');

        func(ans, n - 1, f, l + 1);
        return;
    }

    vector<string> generateParenthesis(int n) {

        // vector<string> str;
        string s;
        func(s, n * 2, 0, 0);

        for(auto a : anss)cout<<a<<endl;

        return anss;
    }



signed main()
{
    int n;
    cin>>n;
    generateParenthesis(n);

    
}