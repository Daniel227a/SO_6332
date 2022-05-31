#include "CpuSchedulingAlgorithms.h"
#include"FCFS.h"


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
        fscanf(fp, "%s %d %d %d",
               process[i].id, &process[i].arrive_time, &process[i].burst, &process[i].priority);

        i++;
    }
    i=0;
  
    /*  

    for (i=0;i<process_count;i++){

        printf(" id %s",process[i].id);
        printf(" tempo de espera (waiting_time): %d",process[i].arrive_time);
        printf(" é o tempo total gasto pelo processo para sua execução na CPU (brust): %d",process[i].burst);
        printf(" priridade : %d",process[i].priority);
        printf("\n");

    }
    */
    FCFS(process , process_count);
    
    for(i=0;i<process_count;i++){

        printf(" id %s",process[i].id);
        printf(" tempo de espera (waiting_time): %d",process[i].arrive_time);
        printf(" (brust): %d",process[i].burst);
        printf(" priridade : %d",process[i].priority);
        printf(" return time : %d",process[i].return_time);
        printf(" turnoroud %d",process[i].return_time);
        printf("\n");

    }
    fcfs_print_gantt_chart(process ,process_count);
     print_table(process, process_count);
}