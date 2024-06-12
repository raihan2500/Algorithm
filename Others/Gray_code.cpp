#include<bits/stdc++.h>
using namespace std;
int n;

vector<bool> bit2gray(int i){
	bitset<32>b(i);
    int m = n-1;
    vector<bool>v;
    v.push_back(b[m]);

    for(int i = m-1; i>=0; i--){
        v.push_back(b[i] ^ b[i+1]);
    }

    return v;

}


int main()
{
    cin>>n;
    
   	for(int i =0 ; i<=((1<<n)-1); i++){

        vector<bool> v = bit2gray(i);
        for(auto a : v)cout<<a;
        cout<<endl;
        
    }

    return 0;
}