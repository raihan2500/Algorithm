#include<bits/stdc++.h>
using namespace std;


int32_t main(){
    
    while(1){
        int x;
        cout << "Guess the number: ";
        cin >> x;
        int y = rand() % 5;
        if(x == y)cout << "You have own." << endl;
        else cout << "You have lost." << endl;

        cout << "Random number was: " << y <<endl;
        if(x == y)break;

    }
}