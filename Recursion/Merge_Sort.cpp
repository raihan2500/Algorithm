#include<bits/stdc++.h>
using namespace std;

#define int                long long

#define endl               "\n"
#define nl                 cout<<"\n"
#define forn(i,e)          for(int i=0;i<e;i++)

const int N = 1e5 +  10;
vector<int>v;

//Code of Selection Sort
//Time Complexity O(n^2);
void SelectionSort(vector<int>&v, int n){
    for(int i = 0; i<n; i++){
        int minIndex = i;
        for(int j = i+1 ; j < n ; j++){
            if(v[j]<v[minIndex]){
                minIndex = j;
            }
        }
        swap(v[i],v[minIndex]);
    }
}


void merge (int l, int r, int mid){
    int l_sz = mid - l +1;
    int r_sz = r - mid;

    vector<int> L(l_sz +1), R(r_sz +1);

    for(int i = 0; i < l_sz; i++){
        L[i] = v[i+l];
    }

    for(int i = 0; i < r_sz; i++){
        R[i] = v[i+ mid +  1];
    }

    L[l_sz] = R [r_sz] = INT_MAX; 

    int l_i = 0, r_i = 0;
    for(int i = l; i<= r; i++){
        if(L[l_i] <= R[r_i]){
            v[i] = L[l_i];
            l_i++;
        }
        else {
            v[i] = R[r_i];
            r_i++;
        }
    }

}

//Merge Sort
//Time Complexity = O(n * log(n))
void mergeSort(int l, int r){
    if(l == r)return;
    int mid =  (l+r)/2;
    mergeSort(l,mid);
    mergeSort(mid+1, r);
    merge(l,r,mid);
}


signed main()
{
    int n;
    cin>>n;
    
    forn(i,n){
        int x;
        cin>>x;
        v.push_back(x);
    }

    mergeSort(0,n-1);

    for(auto a : v)cout<<a<<" ";

    
    
}