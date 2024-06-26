/** Fermet theorem
 * a^(P - 1) % P = 1
 * 
 * 1. if P is a prime number
 * 2. if (a % P != 0)
 */


#include<bits/stdc++.h>
using namespace std;
#define int long long

int binExp(int a, int b, int m){
    int ans = 1;
    while(b > 0){
        if(b & 1)ans = (ans * a) % m;
        b >>= 1;
        a = (a * a) % m;
    }
    return ans;
}


bool isPrime(int m){
    if(m == 1)return false;
    int n = 2;
    if(binExp(2, m - 1, m) == 1)return true;
    else return false;
}


int32_t main(){
    int n;
    cin>>n; 

    if(isPrime(n))cout<<"Prime"<<endl;
    else cout<<"Not prime"<<endl;  
}


/**But there is a bad news in this approach
 * there exist some number (ex: 561) they are not prime also follow fermet theorem
 * This numbers are called Carmichael Numbers
 *  
 * 
 * The Fermat test is still being used in practice, as it is very fast and 
 * Carmichael numbers are very rare. E.g. there only exist 646 such numbers below  10^9 .
 */