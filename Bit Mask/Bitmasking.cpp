#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define nl cout << "\n"
#define forn(i, e) for (ll i = 0; i < e; i++)

int main()
{
    int n;
    cin >> n;
    vector<int> masks(n, 0);
    for (int i = 0; i < n; i++)
    {
        int number_of_days;
        cin >> number_of_days;
        for (int j = 0; j < number_of_days; j++)
        {
            int days; 
            cin>>days;
            masks[i]|=(1<<days);
        }
    }
    
    int max_days = 0;
    for(int i = 0; i < n-1; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            int intersection (masks[i]& masks[j]);
            // cout<<intersection<<" ";
            int common_days = __builtin_popcount(intersection);
            max_days = max(max_days,common_days);
        }
    }
    cout<<max_days<<endl;

}