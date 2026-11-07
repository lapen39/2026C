#define _USE_MATH_DEFINES

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

#include "company.h"

int main(){
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    COMPANY companies[NO_COMPANY];
    char *fname = "company.txt";
    int no_companies = read_companies(fname, companies, NO_COMPANY);
    print_companies(companies, no_companies);

    qsort(companies, no_companies, sizeof(COMPANY), compare_by_name);
    print_companies(companies, no_companies);

    COMPANY c = search_by_name("비전세미콘", companies, no_companies);
    if (c.name != NULL) print_company(c);
    else printf("찾을 수 없습니다.\n");

    return 0;
}