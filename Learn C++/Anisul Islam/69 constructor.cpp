#include<bits/stdc++.h>
using namespace std;

class Student{
    public:
        string name;
        int age;

        Student(){

        };

        Student(string name, int age){
            this->name = name;
            this->age = age;
        }

        void display(){
            cout << "Name: " << name << endl;
            cout << "Age: " << age << endl;
            cout << endl;
        }
    
};


class Dog{
    public:
        string name;
        string sound;
        
        Dog(string name, string sound){
            this->name = name;
            this->sound = sound;
        }

        void display(){
            cout << "Name: " << name <<endl;
            cout << "Sound: " << sound <<endl;
        }
};

int main(){



    Dog shamim("Shamim", "Ghew Ghew");
    shamim.display();
    Dog bulbul("Bulbul", "Mew mew");
    bulbul.display();
}