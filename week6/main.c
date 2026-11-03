#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#define _CRT_NONSTDC_NO_DEPRECATE

#define N_STUDENTS 30
#define SIZE 5

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

void student_score(int scores[], int size);
int get_max(int scores[], int size);
int get_min(int scores[], int size);
double avg_score(int scores[], int size);
double get_stdev(int scores[], int size, double avg);
int get_count(int scores[], int size, double avg);
void get_distribution(int scores[], int size);

int main(void){
    /* 실습 과제 */
    int scores[N_STUDENTS];
    
    // 학생의 점수 초기화 (난수 사용)
    for (int i=0; i < N_STUDENTS; i++){
        scores[i] = rand() % 100 + 1;
    }

    // 전체 학생의 점수 출력
    student_score(scores, N_STUDENTS);

    // 최고 점수 및 최저 점수
    int max=get_max(scores, N_STUDENTS);
    int min=get_min(scores, N_STUDENTS);

    printf("max score: %d\n", max);
    printf("min score: %d\n", min);

    // 전체 학생의 평균 점수
    double avg=avg_score(scores, N_STUDENTS);

    printf("avg score: %.1f\n", avg);

    // 전체 학생의 표준 편차
    double stdev=get_stdev(scores, N_STUDENTS, avg);

    printf("Standard Deviation: %.1f\n", stdev);

    // 평균 이상의 점수를 받은 학생 수
    int count=get_count(scores, N_STUDENTS, avg);

    printf("count of higher than avg: %d\n", count);

    // 점수 구간별 학생 수 출력
    get_distribution(scores, N_STUDENTS);

    return 0;
}

// 전체 학생의 점수 출력
void student_score(int scores[], int size){
    for (int i=0; i < size; i++){
        printf("student %d: %d\n", i + 1, scores[i]);
    }
}
// 최고 점수 계산
int get_max(int scores[], int size){
    int temp=scores[0];
    for (int i=0; i < size; i++){
        if (scores[i] > temp){
            temp = scores[i];
        }
    }
    return temp;
}
// 최저 점수 계산
int get_min(int scores[], int size){
    int temp=scores[0];
    for (int i=0; i < size; i++){
        if (scores[i] < temp){
            temp = scores[i];
        }
    }
    return temp;
}
// 전체 학생의 평균 계산
double avg_score(int scores[], int size){
    int sum=0;

    for (int i=0; i < size; i++){
        sum += scores[i];
    }

    return sum / size;
}
// 전체 학생의 표준 편차 계산
double get_stdev(int scores[], int size, double avg){
    int result=0;

    for (int i=0; i < size; i++){
        result += pow(scores[i] - avg, 2);
    }

    return sqrt(result / size);
}
// 평균 이상의 점수를 받은 학생 수
int get_count(int scores[], int size, double avg){
    int sum=0;

    for (int i=0; i < size; i++){
        if (scores[i] >= avg){
            sum += 1;
        }
    }

    return sum;
}
// 점수 구간별 학생 수 출력
// void get_distribution(int scores[], int size){ // 변수 사용
//     int sum1=0, sum2=0, sum3=0, sum4=0, sum5=0;

//     for (int i=0; i < size; i++){
//         if      (scores[i] >= 90) sum1 += 1;
//         else if (scores[i] >= 80) sum2 += 1;
//         else if (scores[i] >= 70) sum3 += 1;
//         else if (scores[i] >= 60) sum4 += 1;
//         else                      sum5 += 1;
//     }

//     printf("------score distribution------\n");
//     printf("90 ~ 100 : %d\n", sum1);
//     printf("80 ~ 89 : %d\n", sum2);
//     printf("70 ~ 79 : %d\n", sum3);
//     printf("60 ~ 69 : %d\n", sum4);
//     printf("0 ~ 59 : %d\n", sum5);
// }
void get_distribution(int scores[],int size){ // 배열 사용
    int score_distribution[5]={0};

    for (int i=0; i < size; i++){
        if      (scores[i] >= 90) score_distribution[0] += 1;
        else if (scores[i] >= 80) score_distribution[1] += 1;
        else if (scores[i] >= 70) score_distribution[2] += 1;
        else if (scores[i] >= 60) score_distribution[3] += 1;
        else                      score_distribution[4] += 1;
    }

    printf("-----score distribution-----\n");
    printf("90 ~ 100 : %d\n", score_distribution[0]);
    printf("80 ~ 89 : %d\n", score_distribution[1]);
    printf("70 ~ 79 : %d\n", score_distribution[2]);
    printf("60 ~ 69 : %d\n", score_distribution[3]);
    printf("0 ~ 59 : %d\n", score_distribution[4]);
}