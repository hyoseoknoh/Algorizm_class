#include <stdio.h>

int fibo(int n){
    if(n==0)    return 0;
    if(n==1)    return 1;

    int pp = 0, p = 1, result = 0;

    for(int i=2; i<=n; i++){
        result = pp + p;
        pp = p;
        p = result;
    }
    return result;
}

int main(void){
    int i;
    for(i=0; i<10; i++){
        printf("%d ", fibo(i));
    }
    return 0;
}