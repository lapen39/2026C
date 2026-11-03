#define _USE_MATH_DEFINES

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

double compute_volume(double length, double width, double height); // Function Prototype(함수의 프로토타입) - 함수를 사용하기 전에 선언해야 함
double pyeong_to_meter2(double pyeong);

double compute_energy(double mass, double speed);
char compute_abc(char letter, int n);


int main(void){
    // 연습문제 4장 4번: 부피
    double length=30, width=30, height=30;
    double volume = compute_volume(length, width, height);

    printf("(%.1f, %.1f, %.1f) = %.1f\n", length, width, height, volume);

    // 연습문제 4장 5번: 평 -> m^2
    double pyeong=31;
    double meter2 = pyeong_to_meter2(pyeong);

    printf("%.1f -> %.1f\n", pyeong, meter2);

    /* 실습 과제 */
    // 연습문제 4장 7번
    double mass=100, speed=200;
    double kinetic_energy = compute_energy(mass, speed);

    printf("(%.1f * %.1f) = %.1f\n", mass, speed, kinetic_energy);

    // 연습문제 4장 9번
    int n=25;
    /*char letter='a';
    char abc = compute_abc(letter, n);*/
    char abc=compute_abc('a', n);

    printf("%c\n", abc);

    // 연습문제 4장 10번
    char beep='\a';

    printf("%c", beep);
    printf("화재가 발생하였습니다.");

    return 0;
}

double compute_volume(double length, double width, double height){
    return length * width * height;
}

double pyeong_to_meter2(double pyeong){
    const double PYEONG_RATE = 3.3058;
    return PYEONG_RATE * pyeong;
}


double compute_energy(double mass, double speed){
    return 0.5 * mass * speed * speed;
}

char compute_abc(char letter, int n){
    return letter + n;
}