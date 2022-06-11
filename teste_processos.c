#include<stdlib.h>
#include<stdio.h>
#define ID_LEN 20
#define TRUE 1
#define FALSE 0
#include "funçoes.h"
#include"Process.h"

void fcfs_print_gantt_chart(Process *p, int len)
{
    int i, j;
    printf("\t ");
    for (i = 0; i < len; i++)
    {
        for (j = 0; j < p[i].burst; j++)
            printf("--");

        printf(" ");
    }

    printf("\n\t|");


    for (i = 0; i < len; i++)
    {
        for (j = 0; j < p[i].burst - 1; j++)
            printf(" ");

        printf("%s", p[i].id);

        for (j = 0; j < p[i].burst - 1; j++)
            printf(" ");

        printf("|");
    }
    
    printf("\n\t ");

    for (i = 0; i < len; i++)
    {
        for (j = 0; j < p[i].burst; j++)
            printf("--");

        printf(" ");
    }

    printf("\n\t");


    printf("0");

    for (i = 0; i < len; i++)
    {
        for (j = 0; j < p[i].burst; j++)
            printf("  ");

        if (p[i].return_time > 9)
            printf("\b");

        printf("%d", p[i].return_time);

    }

    printf("\n");
}
void main(){

    int process_count = 0;

    int i = 0;
    int j;


    Quantum quantum;

    Process *process;
    Process *temp;
    FILE *fp = fopen("process.txt", "r");


    if (fp == NULL) {
        printf("FILE OPEN ERROR! - Verificar Arquivo do Entrada\n");
       exit(1);
    }

    fscanf(fp, " %d", &process_count);

    process = (Process *) malloc(sizeof(Process) * process_count);
    temp=(Process *) malloc(sizeof(Process) * process_count);
    while (i < process_count) {
        fscanf(fp, "%s %d %d %d",process[i].id, &process[i].arrive_time, &process[i].burst, &process[i].priority);
      //  fscanf(fp, "%s %d %d %d",temp[i].id, &temp[i].arrive_time, &temp[i].burst, &temp[i].priority)
        i++;
    }
    i=0;
    int cont =0;
    
    process_init( process , process_count);
    process_init( temp, process_count);
    
    for(i=0;i<5;i++){
        //printf("arrive  %d\n",process[i].arrive_time);
       cont= arrive_time_sort(process,i,process_count,temp);
      // printf("%d",cont);
        //for (j=0;j<cont;j++){
          //  printf(" arrive do temp %d ",temp[j].arrive_time);

      //  }

    }

    
}