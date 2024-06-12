#include<bits/stdc++.h>
using namespace std;

typedef                    long long ll;
#define nl                 cout<<"\n"
#define forn(i,e)          for(ll i=0;i<e;i++)

int main()
{
    //Swap with xor
    int a = 4, b = 6;
    cout<<a<<" "<<b<<endl;
    a = a ^ b; // a = 2; b = 6 
    b = b ^ a; // a = 2; b = 4;
    a = a ^ b; // a = 6; b = 4; 
    cout<<a<<" "<<b<<endl;

    /**
     * Given array a of n integer. All integers 
     * are present in even count except one.
     * Find thata one integer which has odd count 
     
     * in O(N) time complexity and O(1) space;
     * N < 10 ^ 5
     * a[i] < 10 ^ 5
    */
   int n, x, ans =0;
   cin >> n;
   for(int i = 0 ; i < n;i++){
    cin >> x;
    ans ^= x;
   }
   cout<<ans<<endl;
    
}