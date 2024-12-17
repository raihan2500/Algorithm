#include<bits/stdc++.h>
using namespace std;

#define int long long
const int M = 1e9 + 7;
const int N = 2e5 + 10;

int sum(int a, int b){
    return a + b;
}

double doubleSum(double a, double b){
    return a + b;
}


template<class T1>
T1 func(T1 a, T1 b){
    return a + b;
}


int32_t main(){

    cout <<"Without using template: \n";
    int a = 5, b = 10;
    cout << sum (a, b) << endl;

    double c = 1.7, d = 2.8;
    cout << sum(c, d) << endl; // Not giving the correct ans
    //so we need a another double type function to get the sum of two double value
    cout << doubleSum(c, d) << endl <<endl;


    cout <<"Using template: \n";
    cout << func(a, b) << endl;
    cout << func(c, d) << endl;

}