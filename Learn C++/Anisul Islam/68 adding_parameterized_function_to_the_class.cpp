#include<bits/stdc++.h>
using namespace std;

class student{
    public:
        string name;
        int age;

        void setValue(string n, int a){
            name = n;
            age = a;
        }
        
        void display(){
            cout << "Name: " << name << endl;
            cout << "Age: " << age << endl;
            cout << endl;
        }
};

int main(){

    student raihan;
    raihan.setValue("Raihan Ahmed", 21);
    raihan.display();

}