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
        real = r; imag = i;
    }
    void display() const{
        cout << real <<" " << imag <<"i" << endl;
    }

    Complex operator+(const Complex &c) const{
        return Complex(real + c.real, imag + c.imag);
    }

    Complex operator-(const Complex &c) const{
        return Complex(real - c.real, imag - c.imag);
    }

    Complex operator*(const Complex &c) const{
        return Complex(real * c.real - imag * c.imag, real * c.imag + imag * c.real);
    }

    Complex operator/(const Complex &c) const{
        int num = c.real * c.real + c.imag * c.imag;
        Complex temp = Complex(real, imag) * c;
        return Complex(temp.real / num, temp.imag / num);
    }

    bool operator==(const Complex &c) const{
        return real == c.real && imag == c.imag;
    }


    Complex& operator=(const Complex &c){
        if (this != &c) {
            real = c.real;
            imag = c.imag;
        }
        return *this;
    }

    Complex& operator+=(const Complex &c){
        real += c.real;
        imag += c.imag;
        return *this;
    }

    Complex& operator-=(const Complex &c){
        real -= c.real;
        imag -= c.imag;
        return *this;
    }

    Complex& operator*=(const Complex &c){
        int r = real * c.real - imag * c.imag;
        int i = real * c.imag + imag * c.real;
        real = r;
        imag = i;
        return *this;
    }

    Complex& operator/=(const Complex &c){
        int num = c.real * c.real + c.imag * c.imag;
        int r = real * c.real + imag * c.imag;
        int i = imag * c.real - real * c.imag;
        real = r / num;
        imag = i / num;
        return *this;
    }

    Complex& operator++(){
        real++;
        return *this;
    }

};


int32_t main(){
    Complex c1(12, 5), c2(2, 4);
    Complex c3 = c1 * c2;
    c1.display();
    c2.display();

    c3 *= c1 * c2;
    c3.display();

    
}