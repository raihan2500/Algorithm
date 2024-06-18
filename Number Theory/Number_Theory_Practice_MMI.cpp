#include<bits/stdc++.h>
using namespace std;
#define int        long long
const int M = 1e9 + 7;
const int N = 1e5 + 10;

int fact[N];
void factorial(){
	fact[0] = 1;
	for(int i = 1; i < N; i++){
		fact[i] = (fact[i - 1] * i) % M; 
	}
}

int binExp(int a, int b, int m){
	int ans = 1;
	while(b > 0){
		if(b & 1) ans = (ans * a) % m;
		b >>= 1;
		a = (a * a) % m;
	}
	return ans;
}


void gojo(){
	int n, k;
	cin>>n>>k;
	int ans = fact[n];

	ans = (ans * fact[k]) % M;
	int den = (fact[k - n] * fact[n]) % M;

	ans = (ans * binExp(den, M - 2, M)) % M;
	cout<<ans<<endl;
	cout<<M<<endl;
}


int32_t main(){
	factorial();
	int test;
	cin>>test;
	while(test--){
		gojo();
	}
    
} 
