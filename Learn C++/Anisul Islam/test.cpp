#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

vector<int> primes;
bool isPrime[N];

void seive(){
    for(int i = 2; i < N; i++){
        if(!isPrime[i])
        for(int j = i + i; j < N; j += i){
            isPrime[j] = 1;
        }
    }

    for(int i = 2; i < N; i++){
        if(!isPrime[i]){
            primes.push_back(i);
        }
    }
}

int main(){
    seive();
    ofstream file1("output.txt");

    for(auto i : primes){
        file1 << i;
        file1 << "\n";
    }
    cout << endl;

}
