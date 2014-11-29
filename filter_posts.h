#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#define max_word_groups 50
#define max_words 10
#define max_words_char 100

typedef struct word_groupings{
	int words_counter;
	int weight;
	int headers[n_headers+1];
	char * word_list[max_segments];
	struct word_groupings * next_word;
} words;

extern int filter_post(job_posts * head_post,char ** all_lines, int n_posts);
extern words * new_word_groupings(words * new_words);
extern int * find_posts(words * words_head,job_posts * head_post,char ** all_lines, int n_posts);
extern int comp(const void *pa, const void *pb);
extern int print_posts(char ** all_lines, int * score, int n_posts);
