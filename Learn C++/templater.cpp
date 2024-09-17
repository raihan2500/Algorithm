#include<bits/stdc++.h>
using namespace std;

#define int long long
const int M = 1e9 + 7;
const int N = 2e5 + 10;

template<class T>
class Vector{
    T *arr;
    public:
        vector<int> v;
    void print(int i){
        cout << v[i]<<endl;
    }
};

int32_t main(){
    Vector<int> v;
    v.v.push_back(34);
    v.print(0);  
}