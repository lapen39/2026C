#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#define _CRT_NONSTDC_NO_DEPRECATE

#define SIZE 4

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

int my_strlen(char *str);

void get_dif_types(char *c, int *i, float *f);

double *get_max(double A[], int size);

int merge(int A[], int B[], int size1, int C[], int size2);

int main(void){
    // 11장 연습문제 4번
    int len=my_strlen("HELLO");

    printf("HELLO's length: %d\n", len);

    // 11장 연습문제 5번
    char c;
    int i;
    float f;
    
    get_dif_types(&c, &i, &f);

    printf("%c %d %f\n", c, i, f);

    // 11장 연습문제 8번
    double D[]={1.23, 3.14, 9.16, 100.90};
    int size=sizeof(D)/sizeof(D[0]);
    double *pd = get_max(D, size);

    printf("max: %f\n", *pd);

    /* 실습 과제 */
    // 11장 연습문제 16번
    int A[SIZE]={2, 5, 7, 8};
    int B[SIZE]={1, 3, 4, 6};
    int C[SIZE * 2];
    int no_merged=merge(A, B, SIZE, C, SIZE * 2);

    printf("C[]= { ");
    for (int i = 0; i < no_merged; i++){
        printf("%d ", C[i]);
    }
    printf("}\n");

    return 0;
}

// 문자열의 길이 계산
int my_strlen(char *str){
    char *p=str;
    // int sum;

    while (*p != '\0'){
        p++;
        // sum++;
    }
    // while (*p) p++; 도 가능(속도가 빠름)

    return p - str; // sum;
}

// 문자열에 서로 다른 자료형 저장 및 반환
void get_dif_types(char *c, int *i, float *f){
    char buf[BUFSIZ]; // BUFSIZ : 512
    char *pc=(char *)&buf[0];
    int *pi=(int *)&buf[1]; // (int *) 안 써도 되긴 함
    float *pf=(float *)&buf[5];

    // 쓰기
    *pc = 'a';
    *pi = 100;
    *pf = 3.14F; // 3.14 : double => float로 형변환

    // 읽기
    *c = *pc;
    *i = *pi;
    *f = *pf;
}

// 최대값을 구한 후 그 위치의 주소 반환
double *get_max(double A[], int size){
    double *pmax=&A[0];

    for (int i = 0; i < size; i++){
        if (*pmax < A[i]) pmax = &A[i];
    }

    return pmax;
}

int merge(int A[], int B[], int size1, int C[], int size2){
    int A_num=0, B_num=0, C_num=0;

    while (A_num < size1 && B_num < size1){
        if (A[A_num] < B[B_num]){
            C[C_num] = A[A_num];
            A_num++;
        }
        else{
            C[C_num] = B[B_num];
            B_num++;
        }
        C_num++;
    }

    while (A_num < size1){
        C[C_num] = A[A_num];
        C_num++;
        A_num++;
    }
    while (B_num < size1){
        C[C_num] = B[B_num];
        C_num++;
        B_num++;
    }

    return C_num;
}