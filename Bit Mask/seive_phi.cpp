#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

//To get all number's co-prime from 1 - N
// 2 numbers A and B are co-prime if(gcd(A, B) == 1);

class PHI{
    private:
        int n;
        const int N = 1e6 + 100;
        vector<int> phi = vector<int> (N);
        vector<bool> isPrime = vector<bool> (N);
    public:
        PHI(){
            calculate();
        }
        int get(int n){
            return phi[n];
        }
    private:
        void calculate(){
            for(int i = 1; i < N; i++)phi[i]= i;

            for(int i = 2; i < N; i++){
                if(!isPrime[i]){
                    for(int j = i ; j < N; j += i){
                        isPrime[j] = true;
                        phi[j] = phi[j] / i * (i - 1);
                    }
                    isPrime[i] = 0;
                }
            }
        }
};



int main(){
    int n;
    cin >> n;
    PHI done;

    cout << done.get(7) << endl;
}