const int N = 1e7 + 100;

vector<int> prime;
bool isPrime[N];

void seive(){
    for(long long i = 2; i < N; i++)
        if(!isPrime[i])
            for(long long j = i * i; j < N; j += i)
                isPrime[j] = 1;

    for(int i = 2; i < N; i++)
        if(!isPrime[i])
            prime.push_back(i);
}