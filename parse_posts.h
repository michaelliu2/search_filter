#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#define max_segments 20
#define n_title_lines 3

typedef struct headers{
    char *name[n_headers+1];
    int start_end_placer[n_headers+1];
    int starts[n_headers+1][max_segments];
    int ends[n_headers+1][max_segments];
    } headers;

typedef struct job_posts{
    char * name;
    headers * headers;
    struct job_posts * next_job_post;
} job_posts;

typedef struct titles_array{
    int line;
    char * text;
    struct titles_array * next_titles_array;
    }titles_array;


extern job_posts * parse_posts(char ** all_lines, title_lists * all_titles, int n_lines);
extern job_posts * new_job_post(title_lists * all_titles);
