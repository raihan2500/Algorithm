#include<bits/stdc++.h>
using namespace std;
const int N = 1e7 + 10;

vector<bool> P(N, 1);
vector<int> prime;

vector<int> lp(N), hp(N);

void seive(){
	P[0] = P[1] = 0;

	for(int i = 2; i * i <= N; i++){
		if(P[i]){
            hp[i] = i;

			for(int j = i * 2; j <= N; j += i){
                //For prime Number
				P[j] = 0;

				// Heighest prime number set or unset no matter the present prime number is the highest prime number now
				hp[j] = i;
				
				// Number that's lowest prime number hasn't set yet only in this case set their lowest prime number
				if(lp[j] == 0){
					lp[j] = i;
				}
			}
		}
	}

	for(int i = 0; i <= N; i++){
		if(P[i]){
			prime.push_back(i);
		}
	}
}



int32_t main(){
	seive();

	int q;
	cin>>q;
	cout<<lp[q]<<' '<<hp[q]<<endl;

}