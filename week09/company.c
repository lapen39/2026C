#define _USE_MATH_DEFINES

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

#include "company.h"

int read_companies(const char *fname, COMPANY companies[], int size){
    FILE *fp = fopen(fname, "r");
    if (fp == NULL){
        fprintf(stderr, "Can't open %s\n", fname);
        exit(EXIT_FAILURE);
    }

    char buf[BUFSIZ];
    fgets(buf, BUFSIZ, fp);
    COMPANY com;
    int no_companies = 0;
    while (fgets(buf, BUFSIZ, fp) != NULL){
        // printf("%s", buf);

        char *tok = strtok(buf, DELIMIT); // 구분
        tok = strtok(NULL, DELIMIT); // 특성화고
        tok = strtok(NULL, DELIMIT); // 기업명
        com.name = strdup(tok);

        tok = strtok(NULL, DELIMIT); // 규모
        tok = strtok(NULL, DELIMIT); // 사업자 번호
        tok = strtok(NULL, DELIMIT); // 대표자명
        tok = strtok(NULL, DELIMIT); // 사원수
        sscanf(tok, "%d", &com.no_employee);

        tok = strtok(NULL, DELIMIT); // 설립일
        tok = strtok(NULL, DELIMIT); // 대표 번호
        com.phone = strdup(tok);

        tok = strtok(NULL, DELIMIT); // 홈페이지
        com.webpage = strdup(tok);

        // print_company(com);
        companies[no_companies] = com;
        no_companies++;
    }

    fclose(fp);

    return no_companies;
}

void print_company(COMPANY com){
    printf("%-20s\t", com.name);
    printf("%-10s\t", com.phone);
    printf("%-30s\t", com.webpage);
    printf("%d\t", com.no_employee);
    printf("\n");
}

int compare_by_name(const void *a, const void *b){
    COMPANY c1 = *(const COMPANY*)a;
    COMPANY c2 = *(const COMPANY*)b;

    return strcmp(c1.name, c2.name);
}

void print_companies(COMPANY companies[], int no_companies){
    printf("========================================\n");
    for (int i = 0; i < no_companies; i++){
        print_company(companies[i]);
    }
    printf("\n");
}

COMPANY search_by_name(char *c_name, COMPANY companies[], int no_companies){
    int low = 0, high = no_companies - 1;
    int middle;

    while (low <= high){
        middle = (low + high) / 2;
        
        int cmp = strcmp(c_name, companies[middle].name);
        if (cmp == 0) return companies[middle];
        else if (cmp > 0)  low = middle + 1;
        else high = middle - 1;
    }
    
    COMPANY not_found = {NULL, NULL, NULL, 0};
    return not_found;
}