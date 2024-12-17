#include<bits/stdc++.h>
using namespace std;

struct student{
    string name;
    int age;

    void display(){
        cout << "In structure " << endl;
        cout << "Name: " << name <<endl;
        cout << "Age: " << age <<endl;
        cout << endl;
    }
};

class Studnet{
    public:
        string name;
        int age;
        void display(){
            cout << "In class " << endl;
            cout << "Name: " << name <<endl;
            cout << "Age: " << age <<endl;
            cout << endl;
        }
};

int main(){
    struct student raihan;
    raihan.name = "Raihan Ahmed";
    raihan.age = 22;
    raihan.display();


    Studnet ratul;
    ratul.name = "Ratul";
    ratul.age = 14;
    ratul.display();

}