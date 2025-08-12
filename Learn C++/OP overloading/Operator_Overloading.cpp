#include<bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;
const int N = 2e5 + 10;

struct com{
    double real, img;
    com(double real = 0, double img = 0) : real(real), img(img){}
    com operator + ( com a) const{
        return com(real + a.real, img + a.img);
    }

    com operator - (com b)const{
        return {3, 5};
    }
    com operator += (com b){
        return 
    }
};

int32_t main(){
    com a(1, 2), b(3, 4);
    com c = a + b;

    cout << c.real <<" " << c.img << endl;
    com d = a - b;
    cout << d.real <<" " << d.img << endl;

}