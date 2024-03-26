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

typedef struct studentTag{
    char name[10];
    int age;
    double gpa;
}student;

int main(void){
    student a = {"kim",20,4.3};
    student b = {"park",21,4.0};

    printf("%s",a.name);

}
