#include<bits/stdc++.h>
using namespace std;
const int N = 1e7 + 10;

vector<bool>isPrime(N, 1);

int main()
{
	isPrime[0] = 0; isPrime[1] = 0;

	
	for(int i = 2; i < N; i++){
		if(isPrime[i] == true){
			for(int j = 2 * i; j * j < N; j+=i){
				isPrime[j] = false;
			}
		}
	}
	for(int i = 0; i < 100; i++){
		if(isPrime[i] == 1){
			cout<<i<<endl;
		}
	}

	return 0;
}
//Time complexity nlog(log(n))
// n* (n / 2 + n / 3 + n / 5 + ......)