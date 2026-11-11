#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#define _CRT_NONSTDC_NO_DEPRECATE

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

int compute_roots(double a, double b, double c, double *x1, double *x2);

int calculator(int x, int y, char op);

double compute_pi(int n);

int add_random(double *x1, double *x2);

double rand_real();

int main(void){
    // 6장 Lab-이차방정식(ax^2 + bx + c의 근 계산)
    double a=1.0, b=2.0, c=1.0;
    double x1, x2;
    int flag=compute_roots(a, b, c, &x1, &x2);

    if (flag == 0) printf("No root");
    else           printf("(%f, %f, %f) = %f, %f\n", a, b, c, x1, x2);
    /* (flag == 0) ? printf("No root") :
                     printf("(%f, %f, %f) = %f, %f\n", a, b, c, x1, x2); */

    // 6장 Lab-산술계산기
    int x=10, y=5;
    char op='^';
    int result=calculator(x, y, op);

    printf("(%d %c %d) = %d\n", x, op, y, result);

    // 7장 Lab-파이 계산
    int n=100000000; // 1억
    // double pi=compute_pi(n);

    // printf("%f\n", pi);

    // 7장 Lab-자동으로 수학문제 생성
    srand(time(NULL));
    int result1=add_random(&x1, &x2); // 이차방정식 변수랑 같이 씀

    printf("(%f + %f) = %d\n", x1, x2, result1);

    // 7장 연습문제 19번
    double pi=compute_pi(n);

    printf("%f\n", pi);

    return 0;
}

// a가 0일 때, 근을 구하지 않음
int compute_roots(double a, double b, double c, double *x1, double *x2){
    if (fabs(a - 0.0) < 1E-10) return 0;

    double dis = pow(b, 2.0) - 4.0 * a * c;

    if (dis < 0) return 0;

    *x1 = ((-b) + sqrt(dis)) / (2.0 * a);
    *x2 = ((-b) - sqrt(dis)) / (2.0 * a);

    return 1;
}

// +, -, *, /, %
int calculator(int x, int y, char op){
    switch (op){
        case '+': return x + y;
        case '-': return x - y;
        case '*': return x * y;
        case '/': return x / y;
        case '%': return x % y;
        default:
            fprintf(stderr, "Unsupported operator\n"); // error 메세지 출력: fprintf()
            return 0;
    }
}

// 가능한 한 정확한 파이 계산
// double compute_pi(int n){
//     double divident=4.0;
//     double divisor=1.0, pi=0.0;

//     for (int i=0; i < n; i++){
//         pi += divident / divisor;
//         divident *= (-1.0);
//         divisor += 2;
//     }

//     return pi;
// }


int add_random(double *x1, double *x2){ // *x1, *x2가 실수인데 계산값은 정수로 강제 형변환을 해서 컴파일 에러가 뜰 수 있음
    *x1 = rand() % 100 + 1;
    *x2 = rand() % 100 + 1;

    return *x1 + *x2;
}

double rand_real(){
    return rand() / (double)RAND_MAX * 2.0 - 1.0;
}
double compute_pi(int n){
    int count=0;

    for (int i=0; i < n; i++){
        double x=rand_real();
        double y=rand_real();
        double distance=sqrt(pow(x, 2.0) + pow(y, 2.0));

        if (distance <= 1.0) count++;
    }

    return 4.0 * count / n;
}