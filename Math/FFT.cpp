#include<bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include<algo/debug.h>
#include<algo/resources.h>
#else
#   define clog if (0) cerr
#   define DB(...)
#   define db(...) "" 
#endif

#define int long long
const int M = 1e9 + 7;
const int N = 2e5 + 10;

//complex # = a + ib
using cd = complex<double>;
const double PI = acos(-1);

vector<cd> fft(vector<cd> p, int n){
    if(n == 1)return p;
    vector<cd> Pe, Po;

    for(int i = 0; 2 * i < n; i++){
        Pe.push_back(p[2 * i]);
        Po.push_back(p[2 * i + 1]);
    }
    Pe = fft(Pe, n / 2);
    Po = fft(Po, n / 2);

    double ang = (2 * PI) / n;

    //w^0 = 1 + 0i
    //W^1 = cos(ang) + isin(ang)
    cd w(1), w_delta(cos(ang), sin(ang));
    for(int i = 0; i < n / 2; i++){
        p[i] = Pe[i] + w * Po[i];
        p[i + n / 2] = Pe[i] - w * Po[i];
        w *= w_delta;
    }

    return p;
}

vector<cd> invFft(vector<cd> p, int n){
    if(n == 1)return p;
    vector<cd> Pe, Po;

    for(int i = 0; 2 * i < n; i++){
        Pe.push_back(p[2 * i]);
        Po.push_back(p[2 * i + 1]);
    }
    Pe = invFft(Pe, n / 2);
    Po = invFft(Po, n / 2);

    double ang = (-2 * PI) / n;

    //w^0 = 1 + 0i
    //W^1 = cos(ang) + isin(ang)
    cd w(1), w_delta(cos(ang), sin(ang));
    for(int i = 0; i < n / 2; i++){
        p[i] = Pe[i] + w * Po[i];
        p[i + n / 2] = Pe[i] - w * Po[i];
        w *= w_delta;
    }

    return p;
}

vector<int> multiply(vector<int> &a, vector<int> &b){
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());

    //nearest power of 2
    int n = 1 << (int)ceil(log2(a.size() + b.size()));
    fa.resize(n), fb.resize(n);

    fa = fft(fa, n);
    fb = fft(fb, n);

    //multiply value form in O(n)
    for(int i = 0; i < n; i++)fa[i] *= fb[i];
    fa = invFft(fa, n);
    vector<int> res(n);
    for(int i = 0; i < n; i++)res[i] = round(fa[i].real() / n);
    return res;
}


int32_t main(){
    int n; cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for(int i = 0; i <= n; i++)cin >> a[i];
    for(int i = 0; i <= n; i++)cin >> b[i];
    
    vector<int> res = multiply(a, b);
    print(res);
}