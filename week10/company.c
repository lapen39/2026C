#define _USE_MATH_DEFINES

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

#include "company.h"

NODE* read_companies(const char *fname){
    FILE *fp = fopen(fname, "r");
    if (fp == NULL){
        fprintf(stderr, "Can't open %s\n", fname);
        exit(EXIT_FAILURE);
    }

    char buf[BUFSIZ];
    fgets(buf, BUFSIZ, fp);
    COMPANY com;
    NODE *head = NULL;
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
        head = insert_node_first(head, com);
    }

    fclose(fp);

    return head;
}

void print_company(COMPANY com){
    printf("%-20s\t", com.name);
    printf("%-10s\t", com.phone);
    printf("%-30s\t", com.webpage);
    printf("%d\t", com.no_employee);
    printf("\n");
}

void print_companies(NODE *head){
    printf("========================================\n");
    
    NODE *p = head;
    while (p != NULL){
        print_company(*(p->com));
        p = p->link;
    }
}

NODE* insert_node_first(NODE *head, COMPANY com){
    NODE *n = allocate_node(com);
    if (head != NULL){
        n->link = head;
    }

    head = n;

    return head;
}

NODE* allocate_node(COMPANY com){
    NODE *n = (NODE *)malloc(sizeof(NODE));
    if (n == NULL){
        fprintf(stderr, "no memory\n");
        exit(EXIT_FAILURE);
    }

    n->com = allocate_company(com);
    n->link = NULL;
    return n;
}

COMPANY* allocate_company(COMPANY com){
    COMPANY *c = (COMPANY *)malloc(sizeof(COMPANY));
    if (c == NULL){
        fprintf(stderr, "no memory\n");
        exit(EXIT_FAILURE);
    }

    *c = com;

    return c;
}

NODE* reverse_list(NODE *head){
    NODE *head2 = NULL;
    while (head != NULL){
        head2 = insert_node_first(head2, *(head->com));

        head = head->link;
    }

    return head2;
}