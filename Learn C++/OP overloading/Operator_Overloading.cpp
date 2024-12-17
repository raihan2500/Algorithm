#include<bits/stdc++.h>
using namespace std;

#define int long long
const int M = 1e9 + 7;
const int N = 2e5 + 10;

class Complex{
private:
    int real, imag;
public:
    Complex(int r = 0, int i = 0){
        real = r;
        imag = i;
    }

    Complex operator+(Complex const& obj){
        Complex res;
        res.real = real + obj.real;
        res.imag = imag + obj.imag;
        return res;
    }

    void operator ++ (){
        real++;
        imag++;
    }

    void print(){
        cout << real << " " << imag <<"i" << endl;
    }
};

int32_t main(){
    
    Complex num(2, 3);
    Complex b(3, 4);

    Complex(num + b).print();
    num.print();
    num = num + b;
    ++num;
    num.print();

}