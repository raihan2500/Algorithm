#include<bits/stdc++.h>
using namespace std;
#define int        long long
const int M = 1e9 + 7;

int stlen(char* str){
    if(*str == '\0')return 0;
    
    //stlen(str) = stlen(str +  1) + 1;
    return stlen(str + 1) + 1;
}


int32_t main(){
    char str[] = "hello";
    cout<<stlen(str);   
}