#include<bits/stdc++.h>
using namespace std;

int main(){
    int randomNumber = rand();

    cout << randomNumber <<endl;


    for(int i = 1; i < 5; i++){
        cout <<i <<  " random number :" <<" " << rand()%50 <<endl;
    }
}
