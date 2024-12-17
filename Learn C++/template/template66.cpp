#include<bits/stdc++.h>
using namespace std;

#define int long long
const int M = 1e9 + 7;
const int N = 2e5 + 10;


template<class T1 = int , class T2 = string>
class Person{
    public:
        T1 age;
        T2 name;

        Person(T1 age, T2 name){
            this->age = age;
            this->name = name;            
        }

        void display(){
            cout << "Name: " << name << endl;
            cout << "Age: " << age << endl;
        }
};

int32_t main(){

    Person raihan(20, "raihan ahmed");
    raihan.display();
  

    Person uraihan("raihan", 20);
    uraihan.display();

}