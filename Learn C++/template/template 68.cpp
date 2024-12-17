#include<bits/stdc++.h>
using namespace std;

#define int long long
const int M = 1e9 + 7;
const int N = 2e5 + 10;

template<class T>
class myClass{
    public:
        T data;
        myClass(T data){
            this->data = data;
        }
        
        void display();
};

template<class T>
void myClass<T> :: display(){
    cout << data << endl;
}

void func(int a){
    cout << "I am 1st func() " << a << endl;
}

template<class T>
void func(T a){
    cout <<"I am templatised func() " << a << endl;
}



int32_t main(){
    // myClass <int> obj(555);
    // cout << obj.data << endl;

    myClass <string> obj2("Raihan Ahmed");
    cout << obj2.data << endl;

    obj2.display();
    func(50); //Exaxt match the highest priority
}