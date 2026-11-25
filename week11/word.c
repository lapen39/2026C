#define _USE_MATH_DEFINES

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

#include "word.h"

int read_words(char *fname, WORDS *words[], int count, int capacity){
    FILE *fp = fopen(fname, "r");
    if (fp == NULL){
        fprintf(stderr, "Can't open %s\n", fname);
        exit(EXIT_FAILURE);
    }

    char buf[SIZE];
    char w[4];
    while (fgets(buf, SIZE, fp) != NULL){
        printf("%s\n", buf);

        for (int i =0; i < strlen(buf); i++){
            if (!(buf[i] & 0x80)) continue; // AND 취한게 0이면 = 아스키면 -> 아무짓도 안 함

            // AND 취한게 1이면 = 한글이면
            sprintf(w, "%c%c%c", buf[i], buf[i + 1], buf[i + 2]); // UTF-8에서 한글은 3바이트라서 c1, c2, c3 합침
            i += 2;
            printf("%s\n", w);

            count = count_freq(w, words, count, capacity);
        }
    }

    fclose(fp);
    return count;
}

int count_freq(char w[], WORDS *words[], int count, int capacity){
    for (int i = 0; i < count; i++){
        if (strcmp(w, words[i]->word) == 0){
            words[i]->freq += 1;

            return count;
        }
    }
    words[count] = allocate_word(w);

    return count + 1;
}

WORDS* allocate_word(char w[]){
    WORDS *n = (WORDS *)malloc(sizeof(WORDS));
    if (n == NULL){
        fprintf(stderr, "no memory\n");
        exit(EXIT_FAILURE);
    }

    n->word = strdup(w);
    n->freq = 1;

    return n;
}

void print_words(WORDS *words[], int count){
    for (int i = 0; i < count; i++){
        printf("%d: %s(%d)\n", i, words[i]->word, words[i]->freq);
    }
    
    printf("\n\n");
}

int compare_by_han(const void *first, const void *second){
    WORDS *a = *(WORDS **)first;
    WORDS *b = *(WORDS **)second;

    return strcmp(a->word, b->word);
}

WORDS* find_word(WORDS *words[], int count, char w[]){
    int low = 0, high = count - 1;
    while (low <= high){
        int mid = low + (high - low) / 2;
        int cmp = strcmp(w, words[mid]->word);

        if (cmp == 0) return words[mid];
        else if (cmp < 0) high = mid - 1;
        else low = mid + 1;
    }
    return NULL;
}