#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include "main.h"


/*  headers_list[0]="Position Type";
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
*/

filter_posts(job_posts * head_post,char ** all_lines,int n_posts){
    char *** word_list_array;
    word_list_array=malloc(sizeof(char**)*max_word_groups);
    int i;
    int j;
    for(i=0;i<=max_word_groups-1;i++){
        word_list_array[i]=malloc(sizeof(char*)*max_words);
    }

    for(i=0;i<=max_word_groups-1;i++){
        for(j=0;j<=max_words_char-1;j++){
            word_list_array[i][j]=malloc(sizeof(char)*max_words_char);
        }
    }

    int weights[max_word_groups]={0};
    int checked_headers[max_word_groups][n_headers+1]={0};

    
    word_list_array[0][0]="accountant";
    word_list_array[0][1]="accounting";
    word_list_array[0][2]="Accountant";
    word_list_array[0][3]="Accounting";
    word_list_array[0][4]="ACCOUNTANT";
    word_list_array[0][5]="ACCOUNTING";
    word_list_array[0][6]=NULL;
    weights[0]=-99999;
    checked_headers[0][0]=1;
    checked_headers[0][1]=1;
    checked_headers[0][2]=1;
    checked_headers[0][3]=1;
    checked_headers[0][4]=1;
    checked_headers[0][5]=1;
    checked_headers[0][6]=1;
    checked_headers[0][7]=1;
    checked_headers[0][8]=1;
    checked_headers[0][9]=1;
    checked_headers[0][10]=1;
    checked_headers[0][11]=1;
    checked_headers[0][12]=1;
    checked_headers[0][13]=1;
    checked_headers[0][14]=1;

    word_list_array[1][0]="senior";
    word_list_array[1][1]="Sr.";
    word_list_array[1][2]="Senior";
    word_list_array[1][3]="Sr";
    word_list_array[1][4]="SENIOR";
    word_list_array[1][5]="SR.";
    word_list_array[1][6]=NULL;
    weights[1]=-99999;
    checked_headers[1][0]=1;
    checked_headers[1][1]=0;
    checked_headers[1][2]=0;
    checked_headers[1][3]=0;
    checked_headers[1][4]=1;
    checked_headers[1][5]=1;
    checked_headers[1][6]=1;
    checked_headers[1][7]=0;
    checked_headers[1][8]=0;
    checked_headers[1][9]=0;
    checked_headers[1][10]=0;
    checked_headers[1][11]=0;
    checked_headers[1][12]=0;
    checked_headers[1][13]=0;
    checked_headers[1][14]=1;

    word_list_array[2][0]="tutor";
    word_list_array[2][1]="teacher";
    word_list_array[2][2]="Tutor";
    word_list_array[2][3]="Teacher";
    word_list_array[2][4]="TUTOR";
    word_list_array[2][5]="TEACHER";
    word_list_array[2][6]=NULL;
    weights[2]=-99999;
    checked_headers[2][0]=1;
    checked_headers[2][1]=1;
    checked_headers[2][2]=1;
    checked_headers[2][3]=1;
    checked_headers[2][4]=1;
    checked_headers[2][5]=1;
    checked_headers[2][6]=1;
    checked_headers[2][7]=1;
    checked_headers[2][8]=1;
    checked_headers[2][9]=1;
    checked_headers[2][10]=1;
    checked_headers[2][11]=1;
    checked_headers[2][12]=1;
    checked_headers[2][13]=1;
    checked_headers[2][14]=1;

    word_list_array[3][0]=" R ";
    word_list_array[3][1]=NULL;
    weights[3]=30;
    checked_headers[3][0]=1;
    checked_headers[3][1]=0;
    checked_headers[3][2]=0;
    checked_headers[3][3]=0;
    checked_headers[3][4]=1;
    checked_headers[3][5]=1;
    checked_headers[3][6]=1;
    checked_headers[3][7]=0;
    checked_headers[3][8]=0;
    checked_headers[3][9]=0;
    checked_headers[3][10]=0;
    checked_headers[3][11]=0;
    checked_headers[3][12]=0;
    checked_headers[3][13]=0;
    checked_headers[3][14]=1;

    word_list_array[4][0]="audio";
    word_list_array[4][1]="Audio";
    word_list_array[4][2]="AUDIO";
    word_list_array[4][3]=NULL;
    weights[4]=5;
    checked_headers[4][0]=1;
    checked_headers[4][1]=0;
    checked_headers[4][2]=1;
    checked_headers[4][3]=1;
    checked_headers[4][4]=1;
    checked_headers[4][5]=1;
    checked_headers[4][6]=1;
    checked_headers[4][7]=0;
    checked_headers[4][8]=0;
    checked_headers[4][9]=0;
    checked_headers[4][10]=1;
    checked_headers[4][11]=1;
    checked_headers[4][12]=1;
    checked_headers[4][13]=1;
    checked_headers[4][14]=1;

    word_list_array[5][0]="image";
    word_list_array[5][1]="Image";
    word_list_array[5][2]="IMAGE";
    word_list_array[5][3]=NULL;
    weights[5]=5;
    checked_headers[5][0]=1;
    checked_headers[5][1]=0;
    checked_headers[5][2]=1;
    checked_headers[5][3]=1;
    checked_headers[5][4]=1;
    checked_headers[5][5]=1;
    checked_headers[5][6]=1;
    checked_headers[5][7]=0;
    checked_headers[5][8]=0;
    checked_headers[5][9]=0;
    checked_headers[5][10]=0;
    checked_headers[5][11]=0;
    checked_headers[5][12]=0;
    checked_headers[5][13]=0;
    checked_headers[5][14]=1;

    word_list_array[6][0]="unique";
    word_list_array[6][1]="Unique";
    word_list_array[6][2]="UNIQUE";
    word_list_array[6][3]=NULL;
    weights[6]=4;
    checked_headers[6][0]=1;
    checked_headers[6][1]=0;
    checked_headers[6][2]=1;
    checked_headers[6][3]=1;
    checked_headers[6][4]=1;
    checked_headers[6][5]=1;
    checked_headers[6][6]=1;
    checked_headers[6][7]=0;
    checked_headers[6][8]=0;
    checked_headers[6][9]=0;
    checked_headers[6][10]=0;
    checked_headers[6][11]=0;
    checked_headers[6][12]=0;
    checked_headers[6][13]=0;
    checked_headers[6][14]=1;

    word_list_array[7][0]="physics";
    word_list_array[7][1]="Physics";
    word_list_array[7][2]="PHYSICS";
    word_list_array[7][3]=NULL;
    weights[7]=10;
    checked_headers[7][0]=0;
    checked_headers[7][1]=0;
    checked_headers[7][2]=1;
    checked_headers[7][3]=1;
    checked_headers[7][4]=0;
    checked_headers[7][5]=1;
    checked_headers[7][6]=1;
    checked_headers[7][7]=0;
    checked_headers[7][8]=0;
    checked_headers[7][9]=0;
    checked_headers[7][10]=1;
    checked_headers[7][11]=1;
    checked_headers[7][12]=1;
    checked_headers[7][13]=1;
    checked_headers[7][14]=1;

    word_list_array[8][0]="math";
    word_list_array[8][1]="Math";
    word_list_array[8][2]="MATH";
    word_list_array[8][3]=NULL;
    weights[8]=10;
    checked_headers[8][0]=0;
    checked_headers[8][1]=0;
    checked_headers[8][2]=1;
    checked_headers[8][3]=1;
    checked_headers[8][4]=0;
    checked_headers[8][5]=1;
    checked_headers[8][6]=1;
    checked_headers[8][7]=0;
    checked_headers[8][8]=0;
    checked_headers[8][9]=0;
    checked_headers[8][10]=1;
    checked_headers[8][11]=1;
    checked_headers[8][12]=1;
    checked_headers[8][13]=1;
    checked_headers[8][14]=1;

    word_list_array[9][0]="algorithm";
    word_list_array[9][1]="Algorithm";
    word_list_array[9][2]="ALGORITHM";
    word_list_array[9][3]=NULL;
    weights[9]=8;
    checked_headers[9][0]=1;
    checked_headers[9][1]=1;
    checked_headers[9][2]=1;
    checked_headers[9][3]=1;
    checked_headers[9][4]=1;
    checked_headers[9][5]=1;
    checked_headers[9][6]=1;
    checked_headers[9][7]=1;
    checked_headers[9][8]=1;
    checked_headers[9][9]=1;
    checked_headers[9][10]=1;
    checked_headers[9][11]=1;
    checked_headers[9][12]=1;
    checked_headers[9][13]=1;
    checked_headers[9][14]=1;

    word_list_array[10][0]="startup";
    word_list_array[10][1]="start up";
    word_list_array[10][2]="start-up";
    word_list_array[10][3]="Startup";
    word_list_array[10][4]="Start up";
    word_list_array[10][5]="Start-up";
    word_list_array[10][6]="STARTUP";
    word_list_array[10][7]="START UP";
    word_list_array[10][8]="START-UP";
    word_list_array[10][9]=NULL;
    weights[10]=6;
    checked_headers[10][0]=1;
    checked_headers[10][1]=1;
    checked_headers[10][2]=1;
    checked_headers[10][3]=1;
    checked_headers[10][4]=1;
    checked_headers[10][5]=1;
    checked_headers[10][6]=1;
    checked_headers[10][7]=1;
    checked_headers[10][8]=1;
    checked_headers[10][9]=1;
    checked_headers[10][10]=1;
    checked_headers[10][11]=1;
    checked_headers[10][12]=1;
    checked_headers[10][13]=1;
    checked_headers[10][14]=1;

    word_list_array[11][0]="stats";
    word_list_array[11][1]="statistic";
    word_list_array[11][2]="Stats";
    word_list_array[11][3]="Statistic";
    word_list_array[11][4]="STATS";
    word_list_array[11][5]="STATISTICS";
    word_list_array[11][6]=NULL;
    weights[11]=7;
    checked_headers[11][0]=1;
    checked_headers[11][1]=1;
    checked_headers[11][2]=1;
    checked_headers[11][3]=1;
    checked_headers[11][4]=1;
    checked_headers[11][5]=1;
    checked_headers[11][6]=1;
    checked_headers[11][7]=1;
    checked_headers[11][8]=1;
    checked_headers[11][9]=1;
    checked_headers[11][10]=1;
    checked_headers[11][11]=1;
    checked_headers[11][12]=1;
    checked_headers[11][13]=1;
    checked_headers[11][14]=1;

    word_list_array[12][0]="matlab";
    word_list_array[12][1]="Matlab";
    word_list_array[12][2]="MATLAB";
    word_list_array[12][3]=NULL;
    weights[12]=9;
    checked_headers[12][0]=0;
    checked_headers[12][1]=0;
    checked_headers[12][2]=1;
    checked_headers[12][3]=1;
    checked_headers[12][4]=0;
    checked_headers[12][5]=1;
    checked_headers[12][6]=1;
    checked_headers[12][7]=0;
    checked_headers[12][8]=0;
    checked_headers[12][9]=0;
    checked_headers[12][10]=1;
    checked_headers[12][11]=1;
    checked_headers[12][12]=1;
    checked_headers[12][13]=1;
    checked_headers[12][14]=1;

    word_list_array[13][0]=" C ";
    word_list_array[13][1]=" c ";
    word_list_array[13][2]=" c,";
    word_list_array[13][3]=" C,";
    word_list_array[13][4]=NULL;
    weights[13]=7;
    checked_headers[13][0]=0;
    checked_headers[13][1]=0;
    checked_headers[13][2]=1;
    checked_headers[13][3]=1;
    checked_headers[13][4]=0;
    checked_headers[13][5]=1;
    checked_headers[13][6]=1;
    checked_headers[13][7]=0;
    checked_headers[13][8]=0;
    checked_headers[13][9]=0;
    checked_headers[13][10]=1;
    checked_headers[13][11]=1;
    checked_headers[13][12]=1;
    checked_headers[13][13]=1;
    checked_headers[13][14]=1;

    /*bad_words*/
    word_list_array[14][0]="masters";
    word_list_array[14][1]="Masters";
    word_list_array[14][2]="MASTERS";
    word_list_array[14][3]="MS";
    word_list_array[14][4]="Master's";
    word_list_array[14][5]="master's";
    word_list_array[14][6]="Master";
    word_list_array[14][7]=NULL;
    weights[14]=-650;
    checked_headers[14][0]=0;
    checked_headers[14][1]=0;
    checked_headers[14][2]=1;
    checked_headers[14][3]=1;
    checked_headers[14][4]=1;
    checked_headers[14][5]=1;
    checked_headers[14][6]=1;
    checked_headers[14][7]=0;
    checked_headers[14][8]=0;
    checked_headers[14][9]=0;
    checked_headers[14][10]=1;
    checked_headers[14][11]=0;
    checked_headers[14][12]=1;
    checked_headers[14][13]=0;
    checked_headers[14][14]=0;

    word_list_array[15][0]="doctorate";
    word_list_array[15][1]="Doctorate";
    word_list_array[15][2]="DOCTORATE";
    word_list_array[15][3]=NULL;
    weights[15]=-900;
    checked_headers[15][0]=0;
    checked_headers[15][1]=0;
    checked_headers[15][2]=1;
    checked_headers[15][3]=1;
    checked_headers[15][4]=1;
    checked_headers[15][5]=1;
    checked_headers[15][6]=1;
    checked_headers[15][7]=0;
    checked_headers[15][8]=0;
    checked_headers[15][9]=0;
    checked_headers[15][10]=1;
    checked_headers[15][11]=0;
    checked_headers[15][12]=1;
    checked_headers[15][13]=0;
    checked_headers[15][14]=0;

    word_list_array[16][0]="postdoc";
    word_list_array[16][1]="Postdoc";
    word_list_array[16][2]="POSTDOC";
    word_list_array[16][3]="PostDoc";
    word_list_array[16][4]=NULL;
    weights[16]=-900;
    checked_headers[16][0]=0;
    checked_headers[16][1]=0;
    checked_headers[16][2]=1;
    checked_headers[16][3]=1;
    checked_headers[16][4]=1;
    checked_headers[16][5]=1;
    checked_headers[16][6]=1;
    checked_headers[16][7]=0;
    checked_headers[16][8]=0;
    checked_headers[16][9]=0;
    checked_headers[16][10]=1;
    checked_headers[16][11]=0;
    checked_headers[16][12]=1;
    checked_headers[16][13]=0;
    checked_headers[16][14]=0;

    word_list_array[17][0]="phd";
    word_list_array[17][1]="Ph.D";
    word_list_array[17][2]="PHD";
    word_list_array[17][3]="PhD";
    word_list_array[17][4]=NULL;
    weights[17]=-900;
    checked_headers[17][0]=0;
    checked_headers[17][1]=0;
    checked_headers[17][2]=1;
    checked_headers[17][3]=1;
    checked_headers[17][4]=1;
    checked_headers[17][5]=1;
    checked_headers[17][6]=1;
    checked_headers[17][7]=0;
    checked_headers[17][8]=0;
    checked_headers[17][9]=0;
    checked_headers[17][10]=1;
    checked_headers[17][11]=0;
    checked_headers[17][12]=1;
    checked_headers[17][13]=0;
    checked_headers[17][14]=0;

    word_list_array[18][0]="Advanced Degree";
    word_list_array[18][1]="advanced degree";
    word_list_array[18][2]="Advanced degree";
    word_list_array[18][3]="ADVANCED DEGREE";
    word_list_array[18][4]=NULL;
    weights[18]=-700;
    checked_headers[18][0]=0;
    checked_headers[18][1]=0;
    checked_headers[18][2]=0;
    checked_headers[18][3]=0;
    checked_headers[18][4]=0;
    checked_headers[18][5]=0;
    checked_headers[18][6]=0;
    checked_headers[18][7]=0;
    checked_headers[18][8]=0;
    checked_headers[18][9]=0;
    checked_headers[18][10]=0;
    checked_headers[18][11]=0;
    checked_headers[18][12]=0;
    checked_headers[18][13]=1;
    checked_headers[18][14]=0;

    word_list_array[19][0]="entry-level";
    word_list_array[19][1]="ENTRY LEVEL";
    word_list_array[19][2]="Entry level";
    word_list_array[19][3]="Entry Level";
    word_list_array[19][4]="entry Level";
    word_list_array[19][5]="Entry-level";
    word_list_array[19][6]="Entry-Level";
    word_list_array[19][7]="ENTRY-LEVEL";
    word_list_array[19][8]=NULL;
    weights[19]=200;
    checked_headers[19][0]=0;
    checked_headers[19][1]=0;
    checked_headers[19][2]=0;
    checked_headers[19][3]=0;
    checked_headers[19][4]=0;
    checked_headers[19][5]=0;
    checked_headers[19][6]=0;
    checked_headers[19][7]=0;
    checked_headers[19][8]=0;
    checked_headers[19][9]=0;
    checked_headers[19][10]=0;
    checked_headers[19][11]=0;
    checked_headers[19][12]=0;
    checked_headers[19][13]=1;
    checked_headers[19][14]=0;

    word_list_array[20][0]="intern ";
    word_list_array[20][1]="Intern ";
    word_list_array[20][2]="INTERN ";
    word_list_array[20][3]="internship";
    word_list_array[20][4]="Internship";
    word_list_array[20][5]="INTERNSHIP";
    word_list_array[20][6]=NULL;
    weights[20]=90;
    checked_headers[20][0]=0;
    checked_headers[20][1]=0;
    checked_headers[20][2]=0;
    checked_headers[20][3]=0;
    checked_headers[20][4]=0;
    checked_headers[20][5]=0;
    checked_headers[20][6]=0;
    checked_headers[20][7]=0;
    checked_headers[20][8]=0;
    checked_headers[20][9]=0;
    checked_headers[20][10]=0;
    checked_headers[20][11]=0;
    checked_headers[20][12]=0;
    checked_headers[20][13]=1;
    checked_headers[20][14]=0;

    /*FUCK IT*/

    word_list_array[21][0]="iOS";
    word_list_array[21][1]="Android";
    word_list_array[21][2]=NULL;
    weights[21]=-70;
    checked_headers[21][0]=0;
    checked_headers[21][1]=0;
    checked_headers[21][2]=1;
    checked_headers[21][3]=1;
    checked_headers[21][4]=1;
    checked_headers[21][5]=1;
    checked_headers[21][6]=1;
    checked_headers[21][7]=0;
    checked_headers[21][8]=0;
    checked_headers[21][9]=0;
    checked_headers[21][10]=1;
    checked_headers[21][11]=1;
    checked_headers[21][12]=0;
    checked_headers[21][13]=1;
    checked_headers[21][14]=1;

    word_list_array[22][0]="Javascript";
    word_list_array[22][1]="C++";
    word_list_array[22][2]="Java";
    word_list_array[22][3]=NULL;
    weights[22]=-100;
    checked_headers[22][0]=0;
    checked_headers[22][1]=0;
    checked_headers[22][2]=1;
    checked_headers[22][3]=1;
    checked_headers[22][4]=1;
    checked_headers[22][5]=1;
    checked_headers[22][6]=1;
    checked_headers[22][7]=0;
    checked_headers[22][8]=0;
    checked_headers[22][9]=0;
    checked_headers[22][10]=1;
    checked_headers[22][11]=1;
    checked_headers[22][12]=0;
    checked_headers[22][13]=1;
    checked_headers[22][14]=1;

    word_list_array[23][0]="mobile";
    word_list_array[23][1]="MOBILE";
    word_list_array[23][2]="Mobile";
    word_list_array[23][3]=NULL;
    weights[23]=5;
    checked_headers[23][0]=0;
    checked_headers[23][1]=0;
    checked_headers[23][2]=1;
    checked_headers[23][3]=1;
    checked_headers[23][4]=1;
    checked_headers[23][5]=1;
    checked_headers[23][6]=1;
    checked_headers[23][7]=0;
    checked_headers[23][8]=0;
    checked_headers[23][9]=0;
    checked_headers[23][10]=1;
    checked_headers[23][11]=1;
    checked_headers[23][12]=0;
    checked_headers[23][13]=1;
    checked_headers[23][14]=1;

    word_list_array[24][0]="Administrator";
    word_list_array[24][1]="administrator";
    word_list_array[24][2]="Executive";
    word_list_array[24][3]="executive";
    word_list_array[24][4]=NULL;
    weights[24]=-20;
    checked_headers[24][0]=0;
    checked_headers[24][1]=0;
    checked_headers[24][2]=1;
    checked_headers[24][3]=1;
    checked_headers[24][4]=1;
    checked_headers[24][5]=1;
    checked_headers[24][6]=1;
    checked_headers[24][7]=0;
    checked_headers[24][8]=0;
    checked_headers[24][9]=0;
    checked_headers[24][10]=1;
    checked_headers[24][11]=1;
    checked_headers[24][12]=0;
    checked_headers[24][13]=1;
    checked_headers[24][14]=1;

    word_list_array[25][0]="Software Design";
    word_list_array[25][1]="software design";
    word_list_array[25][2]="Software Develop";
    word_list_array[25][3]="Software develop";
    word_list_array[25][4]="software engineer";
    word_list_array[25][5]="Software Engineer";
    word_list_array[25][6]="Software engineer";
    word_list_array[25][7]=NULL;
    weights[25]=5;
    checked_headers[25][0]=0;
    checked_headers[25][1]=0;
    checked_headers[25][2]=1;
    checked_headers[25][3]=1;
    checked_headers[25][4]=1;
    checked_headers[25][5]=1;
    checked_headers[25][6]=1;
    checked_headers[25][7]=0;
    checked_headers[25][8]=0;
    checked_headers[25][9]=0;
    checked_headers[25][10]=1;
    checked_headers[25][11]=1;
    checked_headers[25][12]=0;
    checked_headers[25][13]=1;
    checked_headers[25][14]=1;

    word_list_array[26][0]="software design";
    word_list_array[26][1]="Software Design";
    word_list_array[26][2]="Software Develop";
    word_list_array[26][3]="software develop";
    word_list_array[26][4]=NULL;
    weights[26]=5;
    checked_headers[26][0]=0;
    checked_headers[26][1]=0;
    checked_headers[26][2]=1;
    checked_headers[26][3]=1;
    checked_headers[26][4]=1;
    checked_headers[26][5]=1;
    checked_headers[26][6]=1;
    checked_headers[26][7]=0;
    checked_headers[26][8]=0;
    checked_headers[26][9]=0;
    checked_headers[26][10]=1;
    checked_headers[26][11]=1;
    checked_headers[26][12]=0;
    checked_headers[26][13]=1;
    checked_headers[26][14]=1;

    word_list_array[27][0]="signal";
    word_list_array[27][1]="Signal";
    word_list_array[27][2]="SIGNAL";
    word_list_array[27][3]=NULL;
    weights[27]=20;
    checked_headers[27][0]=0;
    checked_headers[27][1]=0;
    checked_headers[27][2]=1;
    checked_headers[27][3]=1;
    checked_headers[27][4]=1;
    checked_headers[27][5]=1;
    checked_headers[27][6]=1;
    checked_headers[27][7]=0;
    checked_headers[27][8]=0;
    checked_headers[27][9]=0;
    checked_headers[27][10]=1;
    checked_headers[27][11]=1;
    checked_headers[27][12]=0;
    checked_headers[27][13]=1;
    checked_headers[27][14]=1;

    word_list_array[28][0]="Analy";
    word_list_array[28][1]="analy";
    word_list_array[28][2]="ANALY";
    word_list_array[28][3]=NULL;
    weights[28]=10;
    checked_headers[28][0]=0;
    checked_headers[28][1]=0;
    checked_headers[28][2]=1;
    checked_headers[28][3]=1;
    checked_headers[28][4]=1;
    checked_headers[28][5]=1;
    checked_headers[28][6]=1;
    checked_headers[28][7]=0;
    checked_headers[28][8]=0;
    checked_headers[28][9]=0;
    checked_headers[28][10]=1;
    checked_headers[28][11]=1;
    checked_headers[28][12]=0;
    checked_headers[28][13]=1;
    checked_headers[28][14]=1;

    word_list_array[29][0]="Python";
    word_list_array[29][1]=NULL;
    weights[29]=20;
    checked_headers[29][0]=0;
    checked_headers[29][1]=0;
    checked_headers[29][2]=1;
    checked_headers[29][3]=1;
    checked_headers[29][4]=1;
    checked_headers[29][5]=1;
    checked_headers[29][6]=1;
    checked_headers[29][7]=0;
    checked_headers[29][8]=0;
    checked_headers[29][9]=0;
    checked_headers[29][10]=1;
    checked_headers[29][11]=1;
    checked_headers[29][12]=0;
    checked_headers[29][13]=1;
    checked_headers[29][14]=1;

    word_list_array[30][0]="machine learning";
    word_list_array[30][1]="MACHINE LEARNING";
    word_list_array[30][2]="Machine Learning";
    word_list_array[30][3]="bayesian";
    word_list_array[30][4]="BAYESIAN";
    word_list_array[30][5]="Bayesian";
    word_list_array[30][6]=NULL;
    weights[30]=25;
    checked_headers[30][0]=0;
    checked_headers[30][1]=0;
    checked_headers[30][2]=1;
    checked_headers[30][3]=1;
    checked_headers[30][4]=1;
    checked_headers[30][5]=1;
    checked_headers[30][6]=1;
    checked_headers[30][7]=0;
    checked_headers[30][8]=0;
    checked_headers[30][9]=0;
    checked_headers[30][10]=1;
    checked_headers[30][11]=1;
    checked_headers[30][12]=0;
    checked_headers[30][13]=1;
    checked_headers[30][14]=1;

    word_list_array[31][0]="data science";
    word_list_array[31][1]="Data Science";
    word_list_array[31][2]="Data science";
    word_list_array[31][3]="DATA SCIENCE";
    word_list_array[31][4]="Big Data";
    word_list_array[31][5]="BIG DATA";
    word_list_array[31][6]="big data";
    word_list_array[31][7]="Big data";
    word_list_array[31][8]=NULL;
    weights[31]=40;
    checked_headers[31][0]=0;
    checked_headers[31][1]=0;
    checked_headers[31][2]=1;
    checked_headers[31][3]=1;
    checked_headers[31][4]=1;
    checked_headers[31][5]=1;
    checked_headers[31][6]=1;
    checked_headers[31][7]=0;
    checked_headers[31][8]=0;
    checked_headers[31][9]=0;
    checked_headers[31][10]=1;
    checked_headers[31][11]=1;
    checked_headers[31][12]=0;
    checked_headers[31][13]=1;
    checked_headers[31][14]=1;

    word_list_array[32][0]=" SQL";
    word_list_array[32][1]=".SQL";
    word_list_array[32][2]="mySQL";
    word_list_array[32][3]=NULL;
    weights[32]=15;
    checked_headers[32][0]=0;
    checked_headers[32][1]=0;
    checked_headers[32][2]=1;
    checked_headers[32][3]=1;
    checked_headers[32][4]=1;
    checked_headers[32][5]=1;
    checked_headers[32][6]=1;
    checked_headers[32][7]=0;
    checked_headers[32][8]=0;
    checked_headers[32][9]=0;
    checked_headers[32][10]=1;
    checked_headers[32][11]=1;
    checked_headers[32][12]=0;
    checked_headers[32][13]=1;
    checked_headers[32][14]=1;

    word_list_array[33][0]=NULL;



    /*---------------------------------------------------------------------------*/
    words * words_head=NULL;
    words_head=new_word_groupings(words_head);
    int counter;

    words * current_words=words_head;
    for(i=0; word_list_array[i][0]!=NULL;i++){
        current_words->words_counter=i;
        current_words->weight=weights[i];
        if (weights[i]==0){
            printf("not enough weights written");
        }
        for(counter=0;counter<=n_headers;counter++){
            current_words->headers[counter]=checked_headers[i][counter];
        }

        for(j=0;word_list_array[i][j]!=NULL;j++){
            current_words->word_list[j]=word_list_array[i][j];
        }
        current_words->word_list[j]=NULL;
        current_words->next_word=new_word_groupings(current_words->next_word); /*last element of words_head list is empty*/
        current_words=current_words->next_word;
    }


    int * score=find_posts(words_head, head_post, all_lines, n_posts);

    qsort(score,n_posts,sizeof(int)*3,comp);
    print_posts(all_lines,score,n_posts);

    return 0;
}

words * new_word_groupings(words * new_words){
    new_words=malloc(sizeof(words));
    memset(new_words->headers,0, sizeof(int)*(n_headers+1));
    new_words->next_word=NULL;
    return new_words;
    }

int * find_posts(words * words_head,job_posts * head_post,char ** all_lines, int n_posts){
    job_posts * current_post=head_post;
    int i;
    int j;
    int counter;
    int * score=malloc(sizeof(int)*n_posts*3);
    memset(score,0,sizeof(int)*n_posts*3);

    int post_n=0;
    while(current_post->next_job_post!=NULL){
        score[post_n*3]=current_post->headers->starts[n_headers][0]; /*puts starts and ends lines for each post*/
        score[post_n*3+1]=current_post->next_job_post->headers->starts[n_headers][0]-1;


        words * current_words=words_head;
        while(current_words->next_word!=NULL){
            int flag=0;
            for(i=0;i<=n_headers && flag==0;i++){
                if(current_words->headers[i]==1){
                    int word_counter=0;
                    while(current_words->word_list[word_counter]!=NULL && flag==0){
                        for(j=0;j<current_post->headers->start_end_placer[i] && flag==0;j++){
                            int start=current_post->headers->starts[i][j];
                            int end=current_post->headers->ends[i][j];
                            for(counter=start;counter<=end;counter++){
                                if((strstr(all_lines[counter],current_words->word_list[word_counter]))!=NULL){
                                        score[post_n*3+2]=score[post_n*3+2]+current_words->weight;
                                        printf("%d\n",score[post_n*3+2]);
                                        flag=1;
                                        break;
                                }
                            }
                        }
                    word_counter++;
                    }
                }

            }
            current_words=current_words->next_word;
        }
        current_post=current_post->next_job_post;
        post_n++;
    }
    return score;
    }

int comp(const void *pa, const void *pb){
    int (*a)[3]=pa;
    int(*b)[3]=pb;
    if ((*a)[2]<(*b)[2]){
    return 1;
}
    if ((*a)[2]>(*b)[2]){
        return -1;
    }
    return 0;
}

int print_posts(char** all_lines, int *score, int n_posts){
    FILE *fp=fopen("scored_posts4.txt","wb");
    int post_n;
    int line_n;
    int starts;
    int ends;

    for(post_n=0;post_n<=n_posts-1;post_n++){
        fprintf(fp,"THIS IS POST: %d\n",post_n);
        fprintf(fp,"THE SCORE IS: %d\n\n\n",score[post_n*3+2]);
        starts=score[post_n*3];
        ends=score[post_n*3+1];
        for(line_n=starts;line_n<=ends;line_n++){
            fprintf(fp,"%s\n",all_lines[line_n]);
        }
        fprintf(fp,"*****************************************************************\n\n");
    }
    fclose(fp);
    return 0;
}
