#include <stdio.h>
#include <string.h>
#include "main.h"

job_posts * parse_posts(char ** all_lines, title_lists * all_titles, int n_lines){

    job_posts * head_post=new_job_post(all_titles); /* creates new job_posts and outputs pointer to it*/
    job_posts * current_post=head_post;

    int line_i=0;
    char * pointer=NULL;
    char * titles_name;

    int header_i=0;
    int counter=0;
    int flag=0;
    title_lists * current_all_titles=all_titles;

    titles_array * head_titles=malloc(sizeof(titles_array));
    head_titles->next_titles_array=NULL;
    titles_array * current_titles_array=head_titles;

    for(line_i;line_i<=n_lines-1;line_i++){
        if(strncmp(all_lines[line_i],job_id,job_id_len)==0){
           
                if (line_i< n_title_lines){
                    printf("no job_title for first job_post\n");
                    return -1;
                }

                current_post->name=all_lines[line_i- n_title_lines];

                current_post->headers->starts[n_headers][0]=line_i- n_title_lines;
                current_post->headers->ends[n_headers][0]=line_i-1;
                current_post->headers->start_end_placer[n_headers]++;


                current_post->next_job_post=new_job_post(all_titles);
                current_post=current_post->next_job_post;

        }
        else if ((pointer=strstr(all_lines[line_i],":"))!=NULL){
            pointer[0]='\0';
            titles_name=all_lines[line_i];
            if (strlen(titles_name)<=max_title_length){
                current_all_titles=all_titles;
                flag=0;
                while (flag==0 && current_all_titles!=NULL){
                    counter=0;
                    while((current_all_titles->title_elements[counter])!=NULL){
                        if(strstr(titles_name,current_all_titles->title_elements[counter])!=NULL){
                            current_titles_array->line=line_i;
                            printf("%d %s\n",strlen(titles_name),titles_name);
                            current_titles_array->text=malloc(sizeof(char)*max_title_length+7); /*what the fuck*/
                            strcpy(current_titles_array->text,titles_name);
                            current_titles_array->next_titles_array=malloc(sizeof(titles_array));
                            current_titles_array->next_titles_array->next_titles_array=NULL;
                            current_titles_array=current_titles_array->next_titles_array;
                            flag=1;
                            break;
                        }
                        counter++;
                    }
                    current_all_titles=current_all_titles->next_title;
                }
            }
            pointer[0]=':';
        }
    }
    current_titles_array->line=n_lines+1;
    current_post->headers->starts[n_headers][0]=n_lines;


    current_post=head_post;
    current_titles_array=head_titles;
    int post_number=1;
    while((current_post->next_job_post)!=NULL){
        while((current_titles_array->next_titles_array!=NULL) && (current_titles_array->line)<=(current_post->headers->ends[n_headers][0])){
            printf("post title has ':' in it! line: %s\n", all_lines[current_titles_array->line]);
            current_titles_array=current_titles_array->next_titles_array;
        }

        while((current_titles_array->next_titles_array!=NULL) && (current_titles_array->line<current_post->next_job_post->headers->starts[n_headers][0])){

            current_all_titles=all_titles;
            header_i=0;
            while(current_all_titles!=NULL){
            counter=0;
                while((current_all_titles->title_elements[counter])!=NULL){
                    if(strstr(current_titles_array->text,current_all_titles->title_elements[counter])!=NULL){
                        current_post->headers->starts[header_i][current_post->headers->start_end_placer[header_i]]=current_titles_array->line;
                        if(current_titles_array->next_titles_array->line<current_post->next_job_post->headers->starts[n_headers][0]){
                        current_post->headers->ends[header_i][current_post->headers->start_end_placer[header_i]]=(current_titles_array->next_titles_array->line)-1;
                        
                        }
                        else {
                        current_post->headers->ends[header_i][current_post->headers->start_end_placer[header_i]]=current_post->next_job_post->headers->starts[n_headers][0]-1;
                        
                        }
                        current_post->headers->start_end_placer[header_i]++;
                        if (current_post->headers->start_end_placer[header_i]>=max_segments){
                            printf("There are too many element segments");
                            return 0;
                        }
                        break;
                        }
                    counter++;
                    }
                current_all_titles=current_all_titles->next_title;
                header_i++;
                }
            current_titles_array=current_titles_array->next_titles_array;
            }



 
        printf("%d\n",post_number);
        current_post=current_post->next_job_post;
        post_number++;
        }
        FILE *file_pointer=fopen("titles_array","wb");
        if (file_pointer==NULL){
            printf("file_pointer is NULL");
        }
        current_titles_array=head_titles;
        while(current_titles_array->next_titles_array!=NULL){
            fprintf(file_pointer,"%d: %s\n",current_titles_array->line,current_titles_array->text);
            current_titles_array=current_titles_array->next_titles_array;
        }


    current_post=head_post;
    counter=0;
    while(current_post->next_job_post!=NULL){

    printf("*************************\n");
    printf("%d\n",counter);
        for(header_i=0;header_i<=n_headers;header_i++){
            int i=0;
            for(i;i<current_post->headers->start_end_placer[header_i];i++){
                printf("%s\n",all_lines[current_post->headers->starts[header_i][current_post->headers->start_end_placer[i]]]);
                printf("start: %d\n",current_post->headers->starts[header_i][current_post->headers->start_end_placer[i]]);
                printf("end: %d\n",current_post->headers->ends[header_i][current_post->headers->start_end_placer[i]]);
                printf("---------------------------------\n");
        }

    }
    current_post=current_post->next_job_post;
    counter++;
    }

    return head_post;
}

job_posts * new_job_post(title_lists * all_titles){
    job_posts * new_post=malloc(sizeof(job_posts));

    new_post->headers=malloc(sizeof(headers));
    int i=0;
    for (i;i<=n_headers-1;i++){
            new_post->headers->name[i]=all_titles->title_header;
            all_titles=all_titles->next_title;
    }
            new_post->headers->name[n_headers]="Job Title";
    i=0;
    for (i;i<=n_headers;i++){
    new_post->headers->start_end_placer[i]=0;
    }

    new_post->next_job_post=NULL;

    return new_post;
    }
