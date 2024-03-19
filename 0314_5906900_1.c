#include<stdio.h>

int main() {

   int i = 0, j = 0;   // for문을 나와서도 i, j 값을 사용한다.
   int sum = 0;        // 소수의 합을 저장할 변수 초기화

   for(i = 2; i <= 100; i++) {
      for(j = 2; j < i; j++) {  // j는 2부터 i - 1까지 돈다.(j = 2, 3, ..., i-1)
         if(i % j == 0)         // 만약, i와 j의 나머지값이 0이면
            break;              // 안쪽 for문(j)을 빠져나온다.
      }
      if(i == j) {              // 안쪽 for문(j)을 나온 후, i와 j의 값이 같으면
         printf("%4d", i);      // 소수인 i값을 출력한다.
         sum += i;              // 소수의 합에 i를 더한다.
      }
   }

   printf("\n");
   printf("소수들의 합: %d\n", sum); // 모든 소수의 합을 출력한다.

   return 0;
}
