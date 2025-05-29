#include<bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include<algo/debug.h>
#include<algo/resources.h>
#else
#   define clog if (0) cerr
#   define DB(...)
#   define db(...) "" 
#endif

#define int long long
const int M = 1e9 + 7;
const int N = 2e5 + 10;


int32_t main(){

    //Declaring with initializing 
    tuple<int, int, string> tup = {1, 2, "raihn"};
    clog << db(tup) << endl;

    //Assigning 
    tup = make_tuple(3, 4, "hello");
    clog << db(tup) << endl;
    
    //Assigning with {}
    tup = {5, 6, "world"};
    clog << db(tup);

    //Get specific value
    get<0>(tup) = 50;
    cout << get<0>(tup) << endl;

    //Size
    cout << tuple_size<decltype(tup)>::value << endl;

    
}