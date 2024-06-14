//How to find (A / B) % M
/**
 * (A / B) = A * B^-1
 * (A / B) % M = (A % M * (B^-1) % M) %M
 * 
 * So we just need to find B^-1 or Modular Multiplicative Inverse (MMI) of B
 * Here, MMI of B exists if B and M are co-prime or gcd(B, M) = 1
 * 
 * 
 * From Fermet theorem
 * B^M-2 % M = B^-1
 * Hence, B^M-2 % M = MMI of B
 * 
 * 
 * So finally MMI of B found now just apply modular arithmetic multiple rules 
 * 
 * */

#include<bits/stdc++.h>
using namespace std;
#define int        long long
const int M = 1e9 + 7;

int binExp(int a, int b){
	int ans = 1;
	while(b > 0){
		if(b & 1)
			ans = (ans * a) % M;
		a = (a * a) % M;
		b >>= 1;
	}
	return ans;
}

int32_t main(){
	int a, b;
	cin>>a >> b;
	
	//MMI of B by binary exponentiation
	int mmi_of_b = binExp(b, M - 2);

	//Done
	cout<<(a % M * mmi_of_b % M) % M <<endl;
}