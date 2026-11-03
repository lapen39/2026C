#define _USE_MATH_DEFINES

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define DELIMIT " \n\t,.:;\"'()?!"
#define MAX_WORD 1000

int main(){
    char *fname = "text.txt";
    FILE *fp = fopen(fname, "r");
    if (fp == NULL){
        fprintf(stderr, "Can't open file(%s)\n", fname);
        exit(EXIT_FAILURE);
    }

    char buf[BUFSIZ];
    int scount = 0, wcount = 0;
    int freq[MAX_WORD] = {0};
    char word[MAX_WORD][MAX_WORD];
    int ncount = 0;

    while (fgets(buf, BUFSIZ, fp) != NULL){
        printf("%s", buf);

        scount++;

        char *w = strtok(buf, DELIMIT);
        while (w != NULL){
            printf("%s\n", w);

            wcount++;

            int i;
            for (i = 0; i < ncount; i++){ // 이미 있는 단어인지 확인
                if (strcmp(word[i], w) == 0){ // 있으면 빈도수 +1
                    freq[i]++;
                    break;
                }
            }

            if ((ncount <= i) && (ncount < MAX_WORD)){ // 없으면 word에 추가 후 빈도수 +1
                strcpy(word[ncount], w);
                freq[ncount] = 1;
                ncount++;
            }
            
            w = strtok(NULL, DELIMIT);
        }
    }
    printf("line = %d\n", scount);
    printf("word = %d\n", wcount);

    for (int i = 0; i < ncount; i++){
        printf("%s's frequency = %d\n", word[i], freq[i]);
    }

    fclose(fp);

    return 0;
}