#include <stdio.h>
#include <string.h>
#define n_headers 14

typedef struct title_lists{
    char * title_header;
    char ** title_elements;
    struct title_lists * next_title;
    } title_lists;

extern title_lists * sep_titles(char * main_file, int n_titles, int max_title_length);
