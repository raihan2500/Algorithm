#include<bits/stdc++.h>
using namespace std;

int main()
{
	string str;
	cin>> str;
	cout<<str<<endl;
	int lo = 0, hi = str.size(), mid;

	while(hi > lo){
		mid = (hi + lo) / 2;
		if(str[mid] == 'f'){
			hi = mid ;
		}
		else{
			lo = mid + 1;
		}
	}

	cout<<lo<<" "<<hi<<endl;


	return 0;
}