#include <stdio.h>

void honnoi_tower(int n, char from, char tmp, char to){     // n개의 원판을 from에서 to로 옮기는 함수
    if (n == 1) printf("원판1을 %c에서 %c로 옮깁니다.\n", from, to);    // 원판이 1개일 때
    else{   // 원판이 1개가 아닐 때
        honnoi_tower(n-1, from, to, tmp);   // n-1개의 원판을 from에서 tmp로 옮김
        printf("원판%d을 %c에서 %c로 옮깁니다.\n", n, from, to);    // n번째 원판을 from에서 to로 옮김
        honnoi_tower(n-1, tmp, from, to);   // n-1개의 원판을 tmp에서 to로 옮김
    }   
}

int main(void){
    honnoi_tower(4, 'A', 'B', 'C');
    return 0;
}