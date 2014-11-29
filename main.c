#include "main.h"

main(){
FILE *fp;
fp=fopen("all_callisto4.txt", "r");
if (fp==NULL){
    printf("failed to open file \n");
    return -1;
}


    int counter=0;
    int c;
    while((c=fgetc(fp))!=EOF){
    if (c=='\n'){
        counter++;
    }
    }

    rewind(fp);
    printf("there are %d+1 lines \n",counter);

    int max_lines=counter+1;
    int max_char=2808;
    char **all_lines;
    all_lines=malloc(sizeof(char*)*max_lines);

    int i=0;
    for (i;i<max_lines;i++){
        all_lines[i]=malloc(sizeof(char)*max_char);
    }
    int n_lines=getlines(all_lines, max_lines, max_char, fp);

    printf("n_lines is %d \n", n_lines);


    titles ** titles_head=malloc(sizeof(titles*));
    *titles_head=NULL;
    int n_titles=title_find(all_lines,n_lines,titles_head, max_title_length);
    printf("%d titles\n",n_titles);

    FILE *text_file;
    text_file=fopen("titles_callisto", "wb");
    print_titles(*titles_head, text_file);
    fclose(text_file);

    int n_posts=line_find(all_lines,n_lines,job_id,job_id_len);
    printf("there are %d job posts\n",n_posts);

    counter=line_find(all_lines,n_lines,"Location:",9);
    printf("there are %d Locations\n",counter);
    counter=line_find(all_lines,n_lines,"Job Location(s):",16);
    printf("there are %d Location(s)\n",counter);
    counter=line_find(all_lines,n_lines,"Description:",12);
    printf("there are %d Descriptions\n",counter);
    counter=line_find(all_lines,n_lines,"Job Function:",13);
    printf("there are %d Job Functions\n",counter);
    counter=line_find(all_lines,n_lines,"Job Functions:",16);
    printf("there are %d Job Functions\n",counter);

    title_lists *all_titles=sep_titles("titles_callisto",n_titles,max_title_length);

    job_posts * head_post=parse_posts(all_lines, all_titles, n_lines);

    filter_posts(head_post,all_lines,n_posts);

    return 0;

}


int getlines(char** all_lines, int max_lines, int max_char, FILE * fp){
    int c;
    int line_i=0;
    int char_i=0;
    while((c=fgetc(fp))!=EOF){
        if(c!='\n'){

            if (char_i>=max_char-2){
                all_lines[line_i]=realloc(all_lines[line_i], sizeof(char)*(max_char+1));
                if (all_lines[line_i]== NULL){
                    printf("out of memory for longer line. Max_char is %d", max_char);
                    return -1;
                }

                max_char++;
            }
            all_lines[line_i][char_i]=c;
            char_i++;
        }
        else{
        all_lines[line_i][char_i]='\0';
        char_i=0;
        line_i++;
        }
    }
    printf("max_char is: %d \n", max_char);
    return line_i+1; 
    }

int line_find(char** all_lines, int n_lines, char * phrase, int job_id_len){
    int line_i;
    int counter=0;
    for (line_i=0;line_i<=n_lines-1;line_i++){
        if(strncmp(all_lines[line_i],phrase,job_id_len)==0){
            counter++;
        }
    }
    return counter;
    }

int title_find(char** all_lines, int n_lines, titles ** titles_head, int max_title_length){
    int line_i;
    int counter=0;
    char * pointer=NULL;
    titles * current_titles;
    for(line_i=0;line_i<=n_lines-1;line_i++){
        current_titles=*titles_head;
        if((pointer=strstr(all_lines[line_i],":"))!=NULL){
            pointer[0]='\0';

            if (strlen(all_lines[line_i])<=max_title_length){
                while(current_titles!=NULL){
                        if(strcmp(all_lines[line_i],current_titles->title_name)==0){
                            current_titles->frequency=current_titles->frequency+1;
                            break;
                        }
                    current_titles=current_titles->next_title;

                }
                if(current_titles==NULL){
                add_titles(titles_head, all_lines[line_i]); /*function call to add new structure to list*/
                counter++;
                }
            }
            pointer[0]=':';
        }
    }
    return counter;
    }

    int test(){
    return 0;
    }
add_titles(titles ** titles_head, char * titles_name){
    titles * temp_titles=malloc(sizeof(titles));
    temp_titles->title_name=malloc(sizeof(char)*(strlen(titles_name)+1));
    strcpy(temp_titles->title_name, titles_name);
    temp_titles->frequency=1;
    temp_titles->next_title=*titles_head;
    *titles_head=temp_titles;
    return 0;
    }
print_titles(titles * titles_head ,FILE * fp){
    titles * current_titles= titles_head;
    while(current_titles!=NULL){
        fprintf(fp, "%s: %d \n", current_titles->title_name, current_titles->frequency);
        current_titles=current_titles->next_title;
    }
    return 0;
    }
