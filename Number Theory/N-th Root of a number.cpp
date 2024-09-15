#include<bits/stdc++.h>
using namespace std;

class nthRoot{
    private:
        int p = 2;
        double eps = 1e-6;
        double n;

        bool chk(int p, double x){
            double m = 1;
            for(int i = 0; i < p; i++){
                m *= x;
                if(m > n)return false;
            }
            return true;
        }

    public:
        nthRoot(){

        }
        nthRoot(int p){
            this->p = p;
        }
        double getRoot(double n){
            this->n = n;
            double lo = 0, hi = n, mid;

            while(hi - lo > eps){
                mid = (lo + hi) / 2;
                if(chk(p, mid)){
                    lo = mid;
                }else{
                    hi = mid;
                }
            }
            return lo;
        }
};


int32_t main(){
    int n;
    cin >> n;
    
    nthRoot obj(4);
    cout << obj.getRoot(n) << endl;
}