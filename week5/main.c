#define _USE_MATH_DEFINES

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

int is_multiple(int n, int m);

double sin_degree(double deg);
double degree_to_radian(double deg);

int sum_dice(int n);

int sum_recursive(int n);

double calculate_euler(int n);

int main(void){
    // 8장 연습문제 2번
    int n=30, m=5;
    int flag=is_multiple(n, m);

    if (flag == 1) printf("%d is %d multiple\n", n, m);
    else           printf("%d is not %d multiple\n", n, m);

    // 8장 연습문제 9번
    for (int deg = 0; deg <= 180; deg += 10){
        double s_value=sin_degree((double)deg);

        printf("sin(%f) = %f\n", (double)deg, s_value);
    }

    // 8장 연습문제 11번
    int person  =sum_dice(3);
    int computer=sum_dice(3);

    printf("person: %d vs computer: %d\n", person, computer);

    if (person > computer) printf("person win\n");
    else                   printf("computer win\n");
    /* 같은 값이 나오는 이유: seed number 때문. rand() -> srand()로 바꾸면 실행할때마다 다른 값이 나옴 */

    // 9장 연습문제 6번
    int sum=sum_recursive(n);

    printf("%d+ = %d\n", n, sum);

    /* 실습 과제(팩토리얼 함수로 정의 안 하고 수식으로 계산하면 가산점) */
    // 8장 연습문제 15번
    double euler=calculate_euler(30);

    printf("euler = %f\n", euler);

    return 0;
}

// n이 m의 배수인지 확인
int is_multiple(int n, int m){
    if (n % m == 0) return 1;
    else            return 0;
}

// deg -> radian 변환
double degree_to_radian(double deg){
    return (M_PI * deg) / 180.0;
}
// deg에 대한 sin값 계산
double sin_degree(double deg){
    return sin(degree_to_radian(deg));
}

// 주사위를 n번 굴린 눈의 값 합 계산
int sum_dice(int n){
    int sum=0;

    for (int i=0; i < n; i++){
        sum += (rand() % 6) + 1;
    }

    return sum;
}

// 1~n까지 자연수의 합 계산(재귀함수로 작성)
int sum_recursive(int n){
    if (n == 0) return 0;
    else        return sum_recursive(n - 1) + n; // else 안 써도 됨.
}

// 오일러 수 계산
double calculate_euler(int n){
    double result=1.0, e=1.0;

    for (int i = 1; i <= n; i++){
        result *= i;
        e += 1.0 / result;
    }

    return e;
}