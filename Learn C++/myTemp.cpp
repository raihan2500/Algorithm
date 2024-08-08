#include<bits/stdc++.h>
using namespace std;
template<typename T> using vin = vector<T>;

int main(){
    vin <string> v(3);

    for(int i = 0;i < 3; i++)cin>>v[i];
    for(auto a : v)cout<<a<<' ';

}