#include <stdio.h>

int fac(int num);

int main(void){
    printf("%d",fac(5));

    return 0;
}


int fac(num){
    if(num <= 1)    return 1;
    else return (num*fac(num-1));
}