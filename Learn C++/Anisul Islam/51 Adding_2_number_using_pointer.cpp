#include<bits/stdc++.h>
using namespace std;

int32_t main(){
    int num1 = 10;
    int num2 = 20;

    int *p1 = &num1;
    int *p2 = &num2;
    

    int sum = *p1 + *p2;

    cout << sum << endl;

}