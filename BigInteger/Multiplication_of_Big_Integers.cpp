#include<bits/stdc++.h>
using namespace std;

//using u128 = __uint128_t;
#define int                 long long

#define endl                "\n"
#define yes                 cout<<"YES\n"
#define no                  cout<<"NO\n"
#define nl                  cout<<"\n"
#define cnl                 clog<<"\n"

#define lin(n)              int n;cin>>n;
#define vin                 vector<int>
#define pr                  pair<int, int>
#define pp                  pop_back()
#define pb(n)               push_back(n)
#define all(x)              x.begin(),x.end()
#define ppfr(v)             v.erase(v.begin());
#define sum_all(v)          accumulate(all(v), 0ll)

#define forn(i,n)           for(int i = 0; i < n; i++)
#define Forn(i,n)           for(int i = 1; i <= n; i++)
#define rforn(i,n)          for(int i = n - 1; i >= 0; i--)
#define print(arr)          for(auto x: arr)cout<<x<<" ";nl;
#define mprint(mp)          for(auto a : mp)cout<<a.first<<" "<<a.second<<endl;

#define _log2(n)            31 - __builtin_clz(n)
#define pop_count(n)        __builtin_popcount(n)

mt19937                     rng(chrono::steady_clock::now().time_since_epoch().count());
#define rng(x,y)            uniform_int_distribution<int>(x,y)(rng)

#ifdef DEBUG
#include<algo/debug.h>
#else
#   define clog if (0) cerr
#   define NB 2500
#   define db(...) "" 
#endif

// const int M = 998244353;
const long long INF = 1e18;
const int M = 1e9 + 7;
const int N = 2e5 + 100;
const double PI = acos(-1);


void fft(vector<complex<double>>& a, bool invert) {
    int n = a.size();
    if (n <= 1) return;

    vector<complex<double>> even(n / 2), odd(n / 2);
    for (int i = 0; i < n / 2; i++) {
        even[i] = a[i * 2];
        odd[i] = a[i * 2 + 1];
    }

    fft(even, invert);
    fft(odd, invert);

    double angle = 2 * PI / n * (invert ? -1 : 1);
    complex<double> w(1), wn(cos(angle), sin(angle));
    for (int i = 0; i < n / 2; i++) {
        a[i] = even[i] + w * odd[i];
        a[i + n / 2] = even[i] - w * odd[i];
        if (invert) {
            a[i] /= 2;
            a[i + n / 2] /= 2;
        }
        w *= wn;
    }
}

// Function to multiply two large integers represented as strings
string multiply(const string& a, const string& b) {
    int n = 1;
    while (n < a.size() + b.size()) n <<= 1;
    n <<= 1;

    vector<complex<double>> fa(n), fb(n);
    for (int i = 0; i < a.size(); i++) fa[i] = complex<double>(a[a.size() - 1 - i] - '0', 0);
    for (int i = 0; i < b.size(); i++) fb[i] = complex<double>(b[b.size() - 1 - i] - '0', 0);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++) fa[i] *= fb[i];
    fft(fa, true);

    vector<int> result(n);
    for (int i = 0; i < n; i++) result[i] = round(fa[i].real());

    for (int i = 0; i < n - 1; i++) {
        result[i + 1] += result[i] / 10;
        result[i] %= 10;
    }

    while (result.size() > 1 && result.back() == 0) result.pop_back();

    string res;
    for (int i = result.size() - 1; i >= 0; i--) res.push_back(result[i] + '0');
    return res;
}


void _(){
    string a, b;
    cin >> a >> b;
    bool af = a.front() == '-';
    bool bf = b.front() == '-';
    if(af)ppfr(a);
    if(bf)ppfr(b);
    string mult = multiply(a, b);
    af ^= bf;
    if(mult == "0")af = 0;
    cout << (af ? "-" : "") << mult << endl;
}

int32_t main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int test = 1;  
    cin>>test;
    for(int i = 1; i <= test; i++){
        // cout << "Case " << i <<": ";
        _();
    }
    return 0;
}