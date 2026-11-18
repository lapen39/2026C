#ifndef __WORD__
#define __WORD__

#define SIZE 10000

struct Word{
    char *word;
    int freq;
};
typedef struct Word WORDS;

int read_words(char *fname, WORDS *words[], int nword, int capacity);
int wsearch(unsigned char w[], WORDS *words[], int nword, int capacity);
WORDS* allocate_word(unsigned char w[]);

#endif