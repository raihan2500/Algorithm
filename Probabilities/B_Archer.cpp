#include<bits/stdc++.h>
using namespace std;

int32_t main(){
    double a, b, c, d;
    cin >> a >> b >> c >> d;

    double A = a / b;
    double B = c / d;
    double NA = 1 - A;
    double NB = 1 - B;

    double ans = A / (1 - (NA * NB));
    cout << fixed << setprecision(9) << ans << endl;
}