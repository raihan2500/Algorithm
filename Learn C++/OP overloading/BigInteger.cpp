#include<bits/stdc++.h>
using namespace std;

#define int long long
const int M = 1e9 + 7;
const int N = 2e5 + 10;


class BigInt{
private:
    string digits;
public:
    BigInt(long long n = 0){
      while(n > 0){
        digits.push_back(n % 10);
        n /= 10;
      }  
    }

    BigInt(string s){
        for(int i = s.size() - 1; i >= 0; i--){
            digits.push_back(s[i] - '0');
        }
    }

    BigInt(const char *s){
        for(int i = strlen(s) - 1; i >= 0; i--){
            digits.push_back(s[i] - '0');
        }
    }

    BigInt(BigInt &a){
        digits = a.digits;
    }

    //cin >>
    friend istream &operator>>(istream &in, BigInt &a){
        string s;
        in >> s;
        a.digits.clear();
        for(int i = s.size() - 1; i >= 0; i--){
            a.digits.push_back(s[i] - '0');
        }
        return in;
    }

    //cout <<
    friend ostream &operator<<(ostream &out, const BigInt &a) {
        for (int i = a.digits.size() - 1; i >= 0; i--) {
            out << (char)(a.digits[i] + '0');
        }
        return out;
    }


    friend BigInt &operator+=(BigInt &a, const BigInt &b){
        int t = 0, s, i;
        int n = a.digits.size(), m = b.digits.size();
        if(m > n){
            a.digits.append(m - n, 0);
        }
        n = a.digits.size();

        for(int i = 0; i < m; i++){
            s = a.digits[i] + b.digits[i] + t;
            t = s / 10;
            a.digits[i] = s % 10;
        }
        if(t)a.digits.push_back(t);
        return a;
    }

    BigInt operator+(const BigInt &a){
        BigInt temp = *this;
        temp += a;
        return temp;
    }

    friend BigInt &operator-=(BigInt&a,const BigInt &b){

    int n = a.digits.size(), m = b.digits.size();
    int i, t = 0, s;
    for (i = 0; i < n;i++){
        if(i < m)
            s = a.digits[i] - b.digits[i]+ t;
        else
            s = a.digits[i]+ t;
        if(s < 0)
            s += 10,
            t = -1;
        else
            t = 0;
        a.digits[i] = s;
    }
    while(n > 1 && a.digits[n - 1] == 0)
        a.digits.pop_back(),
        n--;
    return a;
}

};


int32_t main(){

    BigInt a, b;
    cin >> a >> b;

    BigInt c("0");
    
    c -= a;
    c -= a;
    cout << c << endl;

    // cout << a <<" + " << b <<" = ";
    // cout << c << endl;


}