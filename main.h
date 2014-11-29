#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include "sep_titles.h"
#include "parse_posts.h"
#include "filter_posts.h"

typedef struct titles{
    int frequency;
    char * title_name;
    struct titles * next_title;
} titles;



extern int getlines(char** text, int max_lines, int max_chars, FILE * file);
extern int line_find(char** text, int n_lines, char * string, int cmp_limit);
extern int title_find(char** text, int n_lines, titles ** title_head,int max_title_length);
extern int add_titles(titles ** titles_head, char * title_name);
extern int print_titles(titles * titles_head, FILE * fp);

static char *job_id="Position Type:";
static int job_id_len=14;
static int max_title_length=30;


