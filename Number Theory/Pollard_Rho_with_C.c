#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define  int long long int
#define print(x) printf("%ld\n", x);

const int N = 1000010; 

int isPrime[1000010];
int hp[1000010];

void seive(){
    for(int i = 2; i < N; i++){
        if(!isPrime[i]){
            hp[i] = i;
            for(int j = i + i; j < N; j += i){
                hp[j] = i;
                isPrime[j] = 1;
            }
        }
    }
}

int binExp(int a, int b, int M){
    int ans = 1; a %= M;
    while(b > 0){
        if(b & 1)ans = (__uint128_t) ans * a % M;
        b >>= 1;
        a = (__uint128_t) a * a % M;
    }
    return ans;
}

short isComposite(int n, int a, int s, int d){
    int x = binExp(a, d, n);
    if(x == 1 || x == n - 1)return 0;

    for(int i = 1; i < s; i++){
        x = (__uint128_t)x * x % n;
        if(x == n - 1)return 0;
    }
    return 1;
}

short miller_rabin(int n){
    if(n < 4)return n > 1;
    if(!(n & 1))return 0;

    int s = 0, d = n - 1;
    while(d % 2 == 0){
        d >>= 1;
        s++;
    }
    
    srand(time(0));

    for(int i = 0; i < 5; i++){
        int a = 2 + rand() % (n - 3);
        if(isComposite(n, a, s, d))return 0;
    }
    return 1;    
}

int func(int x, int c, int mod){
    return (x * x % mod + c) % mod;
}

int gcd(int a, int b){
    if(a % b == 0)return b;
    return gcd(b, a % b);
}


int rho(int n){
    srand(time(0));
    int c = 1 + rand() % (n - 2);
    int x = 2 + rand() % (n - 2);

    int y = x, d = 1;

    while(d == 1){
        x = func(x, c, n);
        y = func(func(y, c, n), c, n);
        d = gcd(abs(x - y), n);
    }

    return d;
}



typedef struct {
    int *data;
    size_t size;
    size_t capacity;
} Vector;

void initVector(Vector *vec, size_t initialCapacity) {
    vec->data = (int *)malloc(initialCapacity * sizeof(int));
    vec->size = 0;
    vec->capacity = initialCapacity;
}

void pushBack(Vector *vec, int value) {
    if (vec->size == vec->capacity) {
        vec->capacity *= 2;
        vec->data = (int *)realloc(vec->data, vec->capacity * sizeof(int));
    }
    vec->data[vec->size++] = value;
}

void freeVector(Vector *vec) {
    free(vec->data);
    vec->data = NULL;
    vec->size = 0;
    vec->capacity = 0;
}

Vector factorize(int n){
    if(n == 1){
        Vector emp;
        initVector(&emp, 0);
        return emp;
    }
    if(miller_rabin(n)){
        Vector emp;
        initVector(&emp, 1);
        pushBack(&emp, n);
        return emp;
    }
    
    Vector fact, temp;
    initVector(&fact, 1); initVector(&temp, 1);

    if(n < N){
        while(n > 1){
            int pm = hp[n];
            while(n % pm == 0){
                n /= pm;
                pushBack(&fact, pm);
            }
        }
        return fact;
    }

    int x = rho(n);
    fact = factorize(x);
    temp = factorize(n / x);
    for(int i = 0; i < temp.size; i++){
        pushBack(&fact, temp.data[i]);
    }
    return fact;
}

Vector mergeSort(Vector vec){
    int n = vec.size;
    int mid = n / 2;
    Vector left, right;
    initVector(&left, 1); initVector(&right, 1);
    for(int i = 0; i < mid; i++){
        pushBack(&left, vec.data[i]);
    }
    for(int i = mid; i < n; i++){
        pushBack(&right, vec.data[i]);
    }

    if(left.size > 1)left = mergeSort(left);
    if(right.size > 1)right = mergeSort(right);

    int i = 0, j = 0, k = 0;
    for(; i < left.size && j < right.size;){
        if(left.data[i] < right.data[j]){
            vec.data[k++] = left.data[i++];
        }else{
            vec.data[k++] = right.data[j++];
        }
    }

    while(i < left.size)vec.data[k++] = left.data[i++];
    while(j < right.size)vec.data[k++] = right.data[j++];

    return vec;
}

void solve(){
    int n;
    scanf("%lld", &n);

    Vector vec = factorize(n);
    mergeSort(vec);
    printf("%ld ", vec.size);
    for(int i = 0; i < vec.size; i++){
        printf("%lld ", vec.data[i]);
    }
    printf("\n");
}

__int32_t main(){
    seive();
    int test;
    scanf("%lld", &test);
    while(test--)solve();    
}