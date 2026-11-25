#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#define _CRT_NONSTDC_NO_DEPRECATE

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<ctype.h>
#include <windows.h>


#include "hangul.h"

int main(int argc, char* argv[]) {
	SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

	if (argc < 2) {
		fprintf(stderr, "Usage: %s file1 file2 ...\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	HAN list[N_HAN]; // 포인터를 없애야 파일을 읽고 쓰기 편함
	int count = 0;
	for (int i = 1; i < argc; i++) {
		count = read_hangul(argv[i], list, count, N_HAN);
	}
	//print_hans(list, count);
	qsort(list, count, sizeof(HAN), compare_by_han);

	FILE *fp1 = fopen("bin.bin", "wb");
	if (fp1 == NULL){
		fprintf(stderr, "Can't open bin.bin\n");
		exit(EXIT_FAILURE);
	}

	fwrite(list, sizeof(HAN), count, fp1);
	fclose(fp1);

	FILE *fp2 = fopen("bin.bin", "rb");
	if (fp2 == NULL){
		fprintf(stderr, "Can't open bin.bin\n");
		exit(EXIT_FAILURE);
	}
	HAN n_list[N_HAN];
	fread(n_list, sizeof(HAN), count, fp2);
	print_hans(n_list, count);

	// 파일에서 bsearch 알고리즘 만들기
	HAN han = binary_search(fp2, "가", n_list, count);
	printf("%s(%d)\n", han.w, han.freq);
	fclose(fp2);

	return 0;
}