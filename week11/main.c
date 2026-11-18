#define _USE_MATH_DEFINES

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

#include "word.h"

int main(int argc, char* argv[]){
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    if (argc < 2){ // 오류 체크
        fprintf(stderr, "Usage: %s <file>...\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    WORDS *words[SIZE];
    int nwords = 0;
    for (int i = 0; i < argc; i++){
        nwords = read_words(argv[i], words, nwords, SIZE); // SIZE: 맥시멈크기, nwords: 현재 읽은 단어 수 => 함수가 호출되면서 nwords가
    }

    // printf("%d\n", argc);
    // for (int i = 0; i < argc; i++){
    //     printf("%s\n", argv[i]);
    // }

    return 0;
}