#include<bits/stdc++.h>
using namespace std;
#define print(v) 	for(auto a :v)cout<<a<<' ';cout<<"\n";

const int N = 1e6 + 10;
vector<int> divisors[N];

int32_t main(){

	for(int i = 1; i < N; i++){
		for(int j = i; j < N; j+= i){
			divisors[j].push_back(i);
		}
	}

	int num;
    cin>>num;
    print(divisors[num]);
	

}