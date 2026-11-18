#define _USE_MATH_DEFINES

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

#include "word.h"

int read_words(char *fname, WORDS *words[], int nword, int capacity){
    FILE *fp = fopen(fname, "r");
    if (fp == NULL){
        fprintf(stderr, "Can't open %s\n", fname);
        exit(EXIT_FAILURE);
    }

    char buf[BUFSIZ];
    unsigned char c1;
    unsigned char mask = 0x80; // 0x80: 1000 0000
    while (fgets(buf, BUFSIZ, fp) != NULL){
        printf("%s\n", buf);

        for (int i =0; i < strlen(buf); i++){
            c1 = buf[i];
            if (!(c1 & mask)) continue; // c1과 mask를 AND 취한게 0이면 = 아스키면 -> 아무짓도 안 함

            // c1과 mask를 AND 취한게 1이면 = 한글이면
            i++;
            unsigned char c2 = buf[i];
            i++;
            unsigned char c3 = buf[i];
            unsigned char w[4];
            sprintf(w, "%c%c%c", c1, c2, c3); // UFT-8에서 한글은 3바이트라서 c1, c2, c3 합침
            printf("%s\n", w);

            int index = wsearch(w, words, nword, capacity);
            if (index < 0){ // 단어가 없으면
                words[nword] = allocate_word(w);

                nword++;
            } else{ // 단어가 있으면
                words[nword]->freq += 1;
            }
        }
    }

    fclose(fp);

    return nword;
}

int wsearch(unsigned char w[], WORDS *words[], int nword, int capacity){
    for (int i = 0; i < nword; i++){
        if (strcmp(w, words[i]->word) == 0) return i;
    }
    return -1;
}

WORDS* allocate_word(unsigned char w[]){
    WORDS *n = (WORDS *)malloc(sizeof(WORDS));
    if (n == NULL){
        fprintf(stderr, "no memory\n");
        exit(EXIT_FAILURE);
    }

    n->word = strdup(w);
    n->freq = 1;

    return n;
}