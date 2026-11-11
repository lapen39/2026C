#ifndef __COMPANY__
#define __COMPANY__

#define NO_COMPANY 150
#define DELIMIT "\t\n"

struct company{
    char *name;
    char *phone;
    char *webpage;
    int no_employee;
};
typedef struct company COMPANY;
int read_companies(const char *fname, COMPANY companies[], int size);
void print_company(COMPANY com);
int compare_by_name(const void *a, const void *b);
void print_companies(COMPANY companies[], int no_companies);
COMPANY search_by_name(char *c_name, COMPANY companies[], int no_companies);

#endif