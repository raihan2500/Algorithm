#include<bits/stdc++.h>
using namespace std;

template <class T>
class Vec{
    public:
        T *arr;
        int size;
        Vec(int size){
            this->size = size;
            arr = new T[size];
        }

        T sum(){
            T s = 0;
            for(int i = 0; i < size; i++){
                s += arr[i];
            }
            return s;
        }
};

int main(){

    Vec<int> v(5);
    v.arr[0] = 1;
    v.arr[1] = 2;
    v.arr[2] = 3;

    cout << v.sum() << endl;

    //We don't need to create a class with float data type
    Vec<float> fv(4);
    fv.arr[0] = 1.5;
    fv.arr[1] = 2.5;
    fv.arr[2] = 4.7;

    cout << fv.sum() << endl;        
}