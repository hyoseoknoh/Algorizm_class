#include <stdio.h>

// int main(void){
//     int arr[5] = {1, 2, 3, 4, 5};
//     arr[4] = 10;

//     for(int i=0; i<5; i++){
//         printf("%d ", arr[i]);
//     }
//     return 0;
// }

// int main(void){
//     int arr[2][2] = {{1, 2, 3, 4, 5},{10,20,30,40,50}};
//     printf("%d",arr[0][0]);
// }

// typedef struct studentTag{
//     char name[10];
//     int age;
//     double gpa;
// }student;

// int main(void){
//     student a = {"kim",20,4.3};
//     student b = {"park",21,4.0};

//     printf("%s",a.name);

// }


// #include <stdio.h>

// int main() {
// 	int i;
// 	int a[5] = { 5,3,1,2,4 };
	
	
	
// 	printf("a의 주소 &a[0] = %p, a = %p \n", &a[0],a);
// 	printf("a의 값: %d\n", *a);
// 	for (i = 0; i < 5; i++)
// 		printf("\t 주소 %p  a[%d] : %d, *(a+%d) : %d\n",(a+i),i,a[i],i,*(a+i));

// }
#include <stdio.h>
#include <math.h> // 수학 함수 사용을 위한 헤더 파일

// 원반을 한 기둥에서 다른 기둥으로 이동하는 함수
void moveDisk(char fromPeg, char toPeg) {
    // 원반 이동 정보를 출력
    printf("Move disk from %c to %c\n", fromPeg, toPeg);
}

// 하노이 탑 문제를 해결하는 함수
void solveHanoi(int numDisks) {
    // 총 이동해야 하는 횟수 계산: 2^n - 1
    int totalMoves = pow(2, numDisks) - 1;
    // 기둥 이름 지정 ('A', 'B', 'C')
    char pegs[3] = {'A', 'B', 'C'};
    
    // 총 이동 횟수만큼 반복
    for (int move = 1; move <= totalMoves; move++) {
        // 비트 연산을 사용하여 출발 기둥 결정
        int from = (move & move - 1) % 3;
        // 비트 연산을 사용하여 도착 기둥 결정
        int to = ((move | move - 1) + 1) % 3;
        
        // 결정된 기둥으로 원반 이동
        moveDisk(pegs[from], pegs[to]);
    }
}

int main() {
    int numDisks = 3; // 예제로 사용할 원반의 개수: 3개
    solveHanoi(numDisks); // 하노이 탑 문제 해결 함수 호출
    return 0;
}
