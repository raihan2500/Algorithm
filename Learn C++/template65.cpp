#include<bits/stdc++.h>
using namespace std;

#define int long long
const int M = 1e9 + 7;
const int N = 2e5 + 10;

/*
 template with multiple parameter
 syntax:
 template<class T1, class T2>
 */

template<class T1, class T2>
class myClass{
    public:
        T1 data1;
        T2 data2;
        
        myClass(T1 data1, T2 data2){
            this->data1 = data1;
            this->data2 = data2;
        }

        void display(){
            cout << data1 << endl;
            cout << data2 << endl;
        }
};


int32_t main(){

    myClass obj('x',  "raihan ahmed");
    myClass obj2(1234, 2423432.24232);


    obj.display();
    obj2.display();

    myClass <int, string> ob(24332, "csex");
    ob.display();
}