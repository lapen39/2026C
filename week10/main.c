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

    NODE *head = NULL;
    char *fname = "company.txt";
    head = read_companies(fname);

    print_companies(head);

    NODE *head2 = reverse_list(head);
    print_companies(head2);

    return 0;
}