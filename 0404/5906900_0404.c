// #include <stdio.h>

// void swap(int *a, int *b);

// int main(void){
//     int x = 1;
//     int y = 2;

//     swap(&x,&y);
//     printf("x : %d, y:%d", x, y);

// }

// void swap(int *a,int *b){
//     int tmp = *a;
//     *a = *b;
//     *b = tmp;
// }

// int main(void){
//     student* stdptr;
//     int noOFStd;

//     printf("howmany student?");
//     scanf("%d",&noOFStd);

//     stdptr = (student *)malloc(sizeof(student)*noOFStd);
// }





#include <stdio.h>
#include <stdlib.h>

struct term
{
    float coef;
    int expon;
};

// 사용자로부터 다항식의 항을 입력받는 함수
struct term *get_polynomial(int *n)
{
    printf("다항식의 총 항의 수를 입력하시오: ");
    scanf("%d", n);
    struct term *poly = (struct term *)malloc(*n * sizeof(struct term));
    if (poly == NULL)
    {
        fprintf(stderr, "메모리 할당 오류\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < *n; i++)
    {
        printf("[%d번째 계수, 차수]: ", i + 1);
        scanf("%f %d", &poly[i].coef, &poly[i].expon);
    }
    return poly;
}

// 다항식을 출력하는 함수
void print_poly(struct term *poly, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%3.1fx^%d ", poly[i].coef, poly[i].expon);
        if (i < n - 1)
            printf("+ ");
    }
    printf("\n");
}

// 두 다항식을 곱하는 함수
struct term *poly_mult(struct term *poly1, int n1, struct term *poly2, int n2, int *size)
{
    // 최대 가능한 항의 개수만큼 임시 배열을 할당한다.
    int max_size = n1 * n2;
    struct term *tempResult = (struct term *)calloc(max_size, sizeof(struct term));
    if (tempResult == NULL)
    {
        fprintf(stderr, "메모리 할당 오류\n");
        exit(1);
    }

    int tempSize = 0; // 임시 결과의 실제 사용되는 항의 개수
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            // 현재 조합의 곱셈 결과를 저장한다.
            float c = poly1[i].coef * poly2[j].coef;
            int e = poly1[i].expon + poly2[j].expon;

            // 기존에 동일한 지수를 가진 항이 있는지 찾는다.
            int k;
            for (k = 0; k < tempSize; k++)
            {
                if (tempResult[k].expon == e)
                {
                    tempResult[k].coef += c; // 항을 결합한다.
                    break;
                }
            }
            // 새로운 항이면 추가한다.
            if (k == tempSize)
            {
                tempResult[tempSize].coef = c;
                tempResult[tempSize].expon = e;
                tempSize++;
            }
        }
    }

    // 결과 다항식의 메모리를 할당한다.
    struct term *result = (struct term *)malloc(tempSize * sizeof(struct term));
    if (result == NULL)
    {
        fprintf(stderr, "메모리 할당 오류\n");
        exit(1);
    }

    // 임시 결과에서 0이 아닌 계수의 항만 결과 배열로 복사한다.
    int count = 0;
    for (int i = 0; i < tempSize; i++)
    {
        if (tempResult[i].coef != 0)
        {
            result[count++] = tempResult[i];
        }
    }
    *size = count; // 결과 다항식의 항 개수를 업데이트한다.

    free(tempResult); // 임시 결과 메모리를 해제한다.
    return result;
}


int main()
{
    int n1, n2, size;
    struct term *poly1, *poly2, *result;

    poly1 = get_polynomial(&n1);
    printf("입력된 다항식 1: ");
    print_poly(poly1, n1);

    poly2 = get_polynomial(&n2);
    printf("입력된 다항식 2: ");
    print_poly(poly2, n2);

    result = poly_mult(poly1, n1, poly2, n2, &size);
    printf("다항식 곱셈 결과: ");
    print_poly(result, size);

    free(poly1);
    free(poly2);
    free(result);

    return 0;
}
