#include<stdio.h>
#include<stdlib.h>


__int32_t main(){
    int *arr;
    int n;
    scanf("%d", &n);
    arr = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    arr = (int*)realloc(arr, 8 *sizeof(int));
    for(int i = n; i < n + 3; i++){
        scanf("%d", &arr[i]);
    }
    for(int i = 0; i < n + 3; i++){
        printf("%d ", arr[i]);
    }
}