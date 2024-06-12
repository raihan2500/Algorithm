#include<bits/stdc++.h>
using namespace std;
const int M = 1e9+ 7;

int binExpIter(int a, int b)
{
    int ans = 1;

    while(b>0)
    {
        if(b&1)
            ans = (ans * 1LL * a) % M;
        a = (a  * 1LL * a) % M;
        b = b >> 1;
    }

    return ans;
}


int main()
{
    int a, b;
    cin >> a >> b;
    cout << binExpIter(a,b);
    
    return 0;
}