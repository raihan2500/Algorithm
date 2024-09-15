#include<bits/stdc++.h>
using namespace std;
#define print(arr)         for(auto x: arr)cout<<x<<' '; cout<<endl;
#define int        long long
const int M = 1e9 + 7;

class FIBONACCI{
    public:
        vector<int> nums = {0};
        FIBONACCI(){
            fib();
        }
    private:
        int cnt = 0;
        void fib(int a = 0, int b = 1){
            cnt++;
            if(cnt > 5000)return;
            nums.push_back(b);
            fib(b, (a + b) % M);
        }
};

int32_t main(){
    FIBONACCI fib;
    int n;
    
    while(cin >> n){
        cout << "The Fibonacci number for " << n <<  " is " << fib.nums[n] <<endl;
    }
    
}