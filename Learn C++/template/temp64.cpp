#include<bits/stdc++.h>
using namespace std;

#define int long long
const int M = 1e9 + 7;
const int N = 2e5 + 10;


class Vec{
    public:
        vector<int> v;
        Vec(vector<int> v){
            this->v = v;
        }

        int sum(){
            int s = 0;
            for(auto i : v)s += i;
            return s;
        }
};

//Using template
template<class T>
class TVec{
    public:
        vector<T> v;
        TVec(vector<T> v){
            this->v = v;
        }

        T sum(){
            T s;
            for(T i : v)s += i;
            return s;
        }
};

int32_t main(){
    vector<int> v = {1, 2, 3};
    Vec obj(v);
    cout << obj.sum() << endl;

    vector<float> f = {1.1, 2.2, 3.3};
    // Vec obj2(f); //For float it is not working

    TVec tobj(v);
    TVec tobj2(f);
    
    cout << tobj.sum() << endl;
    cout << tobj2.sum() << endl;

    vector<string> str = {"raihan ", "ahmed ", "niloy "};

    TVec tobj3(str);
    cout << tobj3.sum() << endl;


}