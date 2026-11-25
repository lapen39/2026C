#ifndef __HANGUL__
#define __HANGUL__
#define N_HAN    10000

struct hangul {
	char w[4];
	int freq;
};
typedef struct hangul HAN;

int read_hangul(char *fname, HAN list[], int count, int capacity);
int count_freq(char han[], HAN list[], int count, int capacity);
void print_hans(HAN list[], int count);
int compare_by_han(const void *first, const void *second);
HAN binary_search(FILE *fp, char w[], HAN list[], int count);

#endif