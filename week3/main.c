#define _USE_MATH_DEFINES

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

double f_to_c(double fahrenheit);

void print_digits(int n);

double get_surface(double radius);
double get_volume(double radius);

double get_height(double wand_height, double wand_shadow, double distance);

double get_radius(double al2si_distance, double angle);

int main(void){
    // 화씨 -> 섭씨
    double fahrenheit=100.0;
    double celsius=f_to_c(fahrenheit);

    printf("%.1f = %.1f\n", fahrenheit, celsius);

    // 연습문제 5장 5번
    int n=23;

    print_digits(n);

    // 연습문제 5장 8번
    double radius=10.0;
    double surface=get_surface(radius);
    double volume=get_volume(radius);

    printf("radius: %.1f -> surface: %.1f / volume: %.1f\n", radius, surface, volume);

    /* 실습 과제 */
    // 연습문제 5장 9번
    double wand_height=100, wand_shadow=20, distance=1000;
    double height=get_height(wand_height, wand_shadow, distance);

    printf("height = %.2f\n", height);

    // 연습문제 5장 11번
    double al2si_distance=900, angle=7.2;
    double earth_radius=get_radius(al2si_distance, angle);

    printf("earth_radius = %.2f\n", earth_radius);

    return 0;
}

double f_to_c(double fahrenfeit){
    return (5.0 / 9.0) * (fahrenfeit - 32);
}

/* 100보다 작은 수를 받아서 각 자리수의 숫자를 출력 */
void print_digits(int n){
    if (n > 100){
        printf("Error(%d)\n", n);
        
        return;
    }
    int tens = n / 10;
    int ones = n % 10;

    printf("input: %d -> tens: %d / ones: %d\n", n, tens, ones);
}

/* 구의 표면적 계산 */
double get_surface(double radius){
    return 4 * M_PI * radius * radius;
}
/* 구의 체적 계산 */
double get_volume(double radius){
    return (double) 4 / 3 * M_PI * pow(radius, 3.0);
}

double get_height(double wand_height, double wand_shadow, double distance){
    return (distance * wand_height) / wand_shadow;
}

double get_radius(double al2si_distance, double angle){
    return (al2si_distance * 360) / (2 * M_PI * angle);
}