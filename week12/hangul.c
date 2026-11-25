#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#define _CRT_NONSTDC_NO_DEPRECATE

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<string.h>
#include<ctype.h>

#include "hangul.h"

int read_hangul(char *fname, HAN list[], int count, int capacity) {
	FILE *fp = fopen(fname, "r");
	if (fp == NULL) {
		fprintf(stderr, "Can't open %s\n", fname);
		exit(EXIT_FAILURE);
	}

	char buf[BUFSIZ];
	char han[4];
	while (fgets(buf, BUFSIZ, fp) != NULL) {
		//printf("%s", buf);
		for (int i = 0; i < strlen(buf); i++) {
			if ((buf[i] & 0xF0) != 0xE0) continue;

			sprintf(han, "%c%c%c", buf[i], buf[i + 1], buf[i + 2]);
			i += 2;
			//printf("%s\n", han);

			count = count_freq(han, list, count, capacity);
		}
	}
	fclose(fp);
	return count;
}

int count_freq(char han[], HAN list[], int count, int capacity) {
	for (int i = 0; i < count; i++) {
		if (strcmp(han, list[i].w) == 0) {
			list[i].freq += 1;

			return count;
		}
	}
	strcpy(list[count].w, han);
	list[count].freq = 1;

	return count + 1;
}

void print_hans(HAN list[], int count) {
	for (int i = 0; i < count; i++)
		printf("%d: %s(%d)\n", i, list[i].w, list[i].freq);
	printf("\n\n");
}

int compare_by_han(const void *first, const void *second){
	return strcmp(((HAN *)first)->w, ((HAN *)second)->w);
}

HAN binary_search(FILE *fp, char w[], HAN list[], int count){
	HAN rec = {"", 0};
	int low = 0, high = count - 1;
	while (low <= high){
		int mid = (low + high) / 2;
		fseek(fp, mid * sizeof(HAN), SEEK_SET);
		fread(&rec, sizeof(HAN), 1, fp);

		int cmp = strcmp(w, rec.w);
		if (cmp == 0) return rec;
		else if (cmp < 0) high = mid - 1;
		else low = mid + 1;
	}
	HAN none = {"", 0};
	return none;
}