#include<bits/stdc++.h>
using namespace std;
template<typename T> T add3(){};

template<class Y>
class boy{
    public:
    Y name;
};


int add(int a, int b){
    return a + b;
}

double add2(double a, double b){
    return a + b;
}

int main(){
    cout << add(3, 4)<<endl;
    boy<string> person;
    person.name = "Prince";

    cout<<person.name<<endl;
    
    
}