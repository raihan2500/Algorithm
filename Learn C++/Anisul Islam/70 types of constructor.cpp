#include<bits/stdc++.h>
using namespace std;

class Student{
    public:
        string name;
        int age;

        Student(){
            cout << "Default Constructor " <<endl;
        };

        Student(string name, int age){
            this->name = name;
            this->age = age;
            cout << "Parameterized Constructor " <<endl;
        }

        void display(){
            cout << "Name: " << name << endl;
            cout << "Age: " << age << endl;
            cout << endl;
        }
    
};

int main(){
    Student raihan;
    Student ratul("Ratul", 14);

}