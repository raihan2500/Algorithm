#include<bits/stdc++.h>
using namespace std;

class student{
    public:
        string name;
        int id;

        void display(){
            cout << "Name: " << name << endl;
            cout << "ID: " << id << endl;
            cout << endl;
        }
};

int main(){
    student raihan, ratul;

    raihan.name = "Raihan Ahmed";
    raihan.id = 123;

    raihan.display();

    ratul.name = "Rezaunur Rahman Ratul";
    ratul.id = 12;

    ratul.display();

}