#include <stdio.h>
#include <string.h>
#include "main.h"

title_lists * sep_titles(char * main_file, int n_titles,int max_title_length){
    int max_elements=7;
    int max_title_char=20;


    char ** headers_list=malloc(sizeof(char*)*n_headers);
    int i=0;
    for(i;i<=n_headers-1;i++){
        headers_list[i]=malloc(sizeof(char)*max_title_char);
    }
    headers_list[0]="Position Type";
    headers_list[1]="Location";
    headers_list[2]="Description";
    headers_list[3]="Responsibilities";
    headers_list[4]="Job Function";
    headers_list[5]="Requirements";
    headers_list[6]="Qualifications";
    headers_list[7]="Job Duration";
    headers_list[8]="Hours Per Week";
    headers_list[9]="Salary";
    headers_list[10]="Skills";
    headers_list[11]="Duties";
    headers_list[12]="Education";
    headers_list[13]="Preferred";
    /*headers_list[14] is "Job Title" */
    char *** list_elements;
    list_elements=malloc(sizeof(char**)*n_headers);
    i=0;
    for(i;i<=n_headers-1;i++){
        list_elements[i]=malloc(sizeof(char*)*max_elements);
    }
    i=0;
    int j=0;
    for(i;i<=n_headers-1;i++){
        for(j;j<=max_elements-1;j++){
            list_elements[i][j]=malloc(sizeof(char)*max_title_char);
        }
    }

    list_elements[0][0]="Position Type";/*Position Type*/
    list_elements[0][1]="Position";
    list_elements[0][2]="POSITION";
    list_elements[0][3]="position";
    list_elements[0][4]=NULL;

    list_elements[1][0]="Location"; /*Location*/
    list_elements[1][1]="location";
    list_elements[1][2]="LOCATION";
    list_elements[1][3]=NULL;

    list_elements[2][0]="Description"; /* Description*/
    list_elements[2][1]="description";
    list_elements[2][2]="DESCRIPTION";
    list_elements[2][3]=NULL;

    list_elements[3][0]="Responsibil"; /*Responsibilities*/
    list_elements[3][1]="RESPONSIBIL";
    list_elements[3][2]="responsibil";
    list_elements[3][3]=NULL;

    list_elements[4][0]="Job Function";/*Job Function*/
    list_elements[4][1]="Role";
    list_elements[4][2]="ROLE";
    list_elements[4][3]="role";
    list_elements[4][4]=NULL;

    list_elements[5][0]="Requirement"; /*Requirements*/
    list_elements[5][1]="REQUIREMENT";
    list_elements[5][2]="requirement";
    list_elements[5][3]="REQUIRED";
    list_elements[5][4]="Required";
    list_elements[5][5]="required";
    list_elements[5][6]="require";
    list_elements[5][7]=NULL;

    list_elements[6][0]="Qualification"; /*Qualifications*/
    list_elements[6][1]="QUALIFICATION";
    list_elements[6][2]="qualification";
    list_elements[6][3]="experience";
    list_elements[6][4]="Experience";
    list_elements[6][5]="EXPERIENCE";
    list_elements[6][6]=NULL;

    list_elements[7][0]="Duration"; /*Job Duration*/
    list_elements[7][1]="duration";
    list_elements[7][2]="DURATION";
    list_elements[7][3]=NULL;

    list_elements[8][0]="Hours Per Week"; /*Hours Per Week*/
    list_elements[8][1]="Hours";
    list_elements[8][2]="HOURS";
    list_elements[8][3]="hours";
    list_elements[8][4]= NULL;

    list_elements[9][0]="Salary"; /*Salary*/
    list_elements[9][1]="SALARY";
    list_elements[9][2]="salary";
    list_elements[9][3]="Compensation";
    list_elements[9][4]="COMPENSATION";
    list_elements[9][5]="compensation";
    list_elements[9][6]="pay";
    list_elements[9][7]="Pay";
    list_elements[9][8]="PAY";
    list_elements[9][9]= NULL;

    list_elements[10][0]="Skills"; /*Skills*/
    list_elements[10][1]="skills";
    list_elements[10][2]="SKILLS";
    list_elements[10][3]=NULL;

    list_elements[11][0]="Duties"; /*Duties*/
    list_elements[11][1]="duties";
    list_elements[11][2]="DUTIES";
    list_elements[11][3]=NULL;

    list_elements[12][0]="Education"; /*Education*/
    list_elements[12][1]="EDUCATION";
    list_elements[12][2]="education";
    list_elements[12][3]=NULL;

    list_elements[13][0]="Prefer"; /*Preferred*/
    list_elements[13][1]="prefer";
    list_elements[13][2]="PREFER";
    list_elements[13][3]="DESIR";
    list_elements[13][4]="desir";
    list_elements[13][5]="Desir";
    list_elements[13][6]="Ideal";
    list_elements[13][7]="ideal";
    list_elements[13][8]="IDEAL";
    list_elements[13][9]=NULL;

    title_lists * list_head;
    list_head=malloc(sizeof(title_lists));
    title_lists * current_title= list_head;


    int counter=0;
    for(counter;counter<=n_headers-2;counter++){
        current_title->title_header=headers_list[counter];
        current_title->title_elements=list_elements[counter];
        current_title->next_title=malloc(sizeof(title_lists));
        current_title=current_title->next_title;
    }
        current_title->title_header=headers_list[n_headers-1];
        current_title->title_elements=list_elements[n_headers-1];
        current_title->next_title=NULL;

    FILE *main_fp=fopen(main_file, "r");
    if (main_fp==NULL){
        printf("main_fp is NULL :)");
    }

    char ** all_titles;
    all_titles=malloc(sizeof(char*)*n_titles);
    i=0;
    for (i;i<n_titles;i++){
        all_titles[i]=malloc(sizeof(char)*(max_title_length+7));
    }
    int n_lines=getlines(all_titles, n_titles,max_title_length+7, main_fp);

    current_title=list_head;
    FILE * fp=NULL;
    int line_i=0;
    char * pointer;
    int *titles_mask=malloc(sizeof(int)*(n_lines-1));
    i=0;
    for(i;i<=n_lines-2;i++){
        titles_mask[i]=0;
    }

    while (current_title!=NULL){
        fp=fopen(current_title->title_header, "wb");
        if(fp==NULL){
            printf("title_file fp is NULL");
        }
        counter=0;
        while((current_title->title_elements[counter])!=NULL){

            line_i=0;
            for(line_i;line_i<=n_lines-2;line_i++){
                if((strstr(all_titles[line_i],current_title->title_elements[counter]))!=NULL){
                    fprintf(fp,"%s\n",all_titles[line_i]);
                    titles_mask[line_i]++;
                }
            }
            counter++;
        }
        fclose(fp);
        current_title=current_title->next_title;
    }

    FILE *new_titles=fopen("unused_titles","wb");
    line_i=0;
    counter=0;
    for(line_i;line_i<=n_lines-2;line_i++){
        if(titles_mask[line_i]==0){
            fprintf(new_titles,"%s\n",all_titles[line_i]);
            counter++;
        }
    }
    fclose(new_titles);
    printf("there are %d unused titles\n", counter);

    return list_head;
    }
