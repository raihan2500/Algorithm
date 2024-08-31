const int N = 1e6 + 100;

bool isPrime[N];
vector<int> lp(N), hp(N), prime;

void seive(){
    for(long long i = 2; i < N; i++){
        if(!isPrime[i]){
            lp[i] = hp[i] = i;
            for(long long j = i * 2; j < N; j += i){
                isPrime[j] = 1;
                hp[j] = i;
                if(lp[j] == 0)
                    lp[j] = i;
            }
        }
    }
}