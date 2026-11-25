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
    int count = 0;
    for (int i = 1; i < argc; i++){
        count = read_words(argv[i], words, count, SIZE); // SIZE: 맥시멈크기, count: 현재 읽은 단어 수 => 함수가 호출되면서 count가 갱신됨
    }
    // printf("%d\n",count);
    // print_words(words, count);

    qsort(words, count, sizeof(WORDS *), compare_by_han);
    print_words(words, count);

    char w[4];
    while (1){
        printf("한글 입력 > ");
        scanf("%s", w);

        WORDS *found = find_word(words, count, w);
        if (found) printf("%s: %d\n", found->word, found->freq);
        else printf("not found\n");
    }

    return 0;
}