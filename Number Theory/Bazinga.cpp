#include<bits/stdc++.h>
using namespace std;

typedef                    long long ll;
typedef                    long double ld;
#define int                long long

#define yes                cout<<"YES\n"
#define no                 cout<<"NO\n"
#define nl                 cout<<"\n"
#define endl               "\n"

#define lin(n)             int n;cin>>n;
#define vin                vector<int>
#define pr                 pair<int, int>
#define pb(n)              push_back(n)
#define pp                 pop_back()
#define all(x)             x.begin(),x.end()

#define fi                 first
#define se                 second

#define forn(i,e)          for(int i=0;i<e;i++)
#define Forn(i,e)          for(int i=1;i<=e;i++)
#define rforn(i,s)         for(int i=s-1;i>=0;i--)
#define print(arr)         for(auto x: arr)cout<<x<<" ";nl;
#define mprint(mp)         for(auto a : mp)cout<<a.first<<" "<<a.second<<endl;

#define fast_in_out        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const long long INF = 1e18;
const int M = 1e9 + 7;
const int N = 2e5 + 100;

class SEIVE{
    private:
        int N = 1e6;
        vector<bool> isPrime;
    public:
        vin prime_numbers;
        
        SEIVE(){
            N++; this->N = N;
            isPrime = vector<bool> (N);
            generate();
        }
    
        SEIVE(int N){
            N++; this->N = N;

            isPrime = vector<bool> (N);
            generate();
        }
    private:
        void generate(){
            isPrime[0] = isPrime[1] = 1;
            for(int i = 2; i * i < N; i++){
                if(!isPrime[i]){
                    for(int j = i * i; j < N; j += i){
                        isPrime[j] = 1;

                    }
                }
            }
    
            for(int i = 2; i < N; i++){
                if(!isPrime[i]){
                    prime_numbers.push_back(i);
                }
            }
        }
};

SEIVE sv(8e7);
vin twoDist;

void sukuna(){
    lin(n);
    cout << twoDist[--n] << endl;    
}

int32_t main(){
    fast_in_out;
    int n = sv.prime_numbers.size() - 1, cnt = 0;
    for(int i = 0; i < n && cnt < 2e6 + 100; i++){
        for(int j = i + 1; j < n && 2e6 + 100; j++){
            cnt++;
            twoDist.push_back(sv.prime_numbers[i] * sv.prime_numbers[j]);
        }
    }
    sort(all(twoDist));

    // cout << twoDist.size() << endl;
    int test;	cin>>test;
    while(test--)sukuna();
    return 0;
}