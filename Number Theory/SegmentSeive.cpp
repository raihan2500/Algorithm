#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
bool isPrime[N];
vector<int> primes;

void seive(){
    for(int i = 2; i < N; i++){
        if(!isPrime[i]){
            for(int j = i * 2; j < N; j += i){
                isPrime[j] = 1;
            }
        }
    }
    for(int i = 2; i < N; i++){
        if(!isPrime[i]){
            primes.push_back(i);
        }
    }
}

void segmentSeive(int l, int r){
    int n = r - l + 1;
    vector<bool> isPrime(n);
    
    for(int i = 0; primes[i] * primes[i] <= r; i++){
        int st = ceil(l * 1.0 / primes[i]) * primes[i];

        for(int j = st; j <= r; j += primes[i]){
            if(j == primes[i])continue;
            isPrime[j - l] = true;
        }
    }

    for(int i = 0; i < n; i++){
        if(!isPrime[i]){
            if(i + l > 1){
                cout << i + l << endl;
            }
        }
    }
}

int main(){
    seive();

    int test;
    cin >> test;
    while(test--){
        int l, r;
        cin >> l >> r;
        segmentSeive(l, r);
        cout << endl;
    }

}