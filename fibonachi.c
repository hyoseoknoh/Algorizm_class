#include <stdio.h>
int fibo(int n){
    if(n==0)    return 0;
    if(n==1)    return 1;
    return fibo(n-1) + fibo(n-2);
}

int main(void){
    int i;
    for(i=0; i<10; i++){
        printf("%d ", fibo(i));
    }
    return 0;
}

