#ifndef __WORD__
#define __WORD__

#define SIZE 10000

struct Word{
    char *word;
    int freq;
};
typedef struct Word WORDS;

int read_words(char *fname, WORDS *words[], int count, int capacity);
int count_freq(char w[], WORDS *words[], int count, int capacity);
WORDS* allocate_word(char w[]);
void print_words(WORDS *words[], int count);
int compare_by_han(const void *first, const void *second);
WORDS* find_word(WORDS *words[], int count, char w[]);

#endif